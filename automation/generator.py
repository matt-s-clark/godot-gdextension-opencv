import os
import re

openCVInputTypes = {
	"Scalar":"Color",
	"Mat":"Ref<CVMat>",
	"InputArray":"Ref<CVMat>",
	"InputOutputArray":"Ref<CVMat>",
	"InputArrayOfArrays":"Array"
}
openCVOutputTypes = {
	"OutputArray": "Ref<CVMat>",
	"OutputArrayOfArrays":"Array"
}
input2Output = {
	"double":"float",
	"size_t": "int",
}
input2Output.update(openCVInputTypes)
input2Output.update(openCVOutputTypes)

processingLine = {
	"Mat": "{0}->get_mat()",
	"InputArray": "{0}->get_mat()",
	"InputOutputArray": "{0}->get_mat()",
	"Scalar": "Scalar({0}.b, {0}.g, {0}.r) * 255" ## Simplify
}
initializingType = {
	"Mat":"Mat",
	"InputArray":"Mat",
	"InputOutputArray":"Mat",
	"OutputArray": "Mat",
}
addParamConversion = {
	"noArray()":"Mat()",
}
convertibleTypes = ["Color"]

def GetOrDefault(val : str, list : dict):
	tmp = list.get(val)
	return tmp if tmp else val

def ProcessTokens(line : str):
	isStatic = bool(re.match(r"static ", line))
	line = re.sub(r"([\w\d]+::)|const |&|static |(?<=<) | (?=>)|\*", "", line)
	inputs = re.search(r"(?<=\()[\w\d ,_()=\-&*\.<>]+(?=\))", line)
	split = line.split()
	methodOutputType = split[0]
	methodName = split[1]
	newMethodName = re.sub(r"NaN", r"Nan", methodName)
	newMethodName = re.sub(r"([a-z]+)([A-Z]|\d+)", r"\g<1>_\g<2>", newMethodName)
	newMethodName = re.sub(r"([A-Z])([A-Z][a-z])", r"\g<1>_\g<2>", newMethodName)
	newMethodName = newMethodName.lower()
	filteredInputs = []
	addtionalParameters = []
	outputs = [[ methodOutputType, "defReturn" ]] if methodOutputType != "void" else []

	if inputs:
		inputs = inputs.group().split(", ")
		inputs = [re.split(r"=| ", i) for i in inputs]
	else:
		inputs = []
		print("No inputs ", line)

	for input in inputs:
		if input[0] in openCVOutputTypes:
			newOutput = [ input[0] ]
			newOutput.extend(input[1:])
			outputs.append(newOutput)
			continue

		if len(input) == 2:
			newInput = [GetOrDefault(input[0], input2Output)]
			newInput.append(input[1])
			filteredInputs.append(newInput)
		
		if len(input) == 3:
			newInput = [GetOrDefault(input[0], input2Output)]
			newInput.extend(input[1:])
			addtionalParameters.append(newInput)

		if len(input) < 2 or len(input) > 3:
			print("Failed input ", input)
			break
	
	if len(addtionalParameters):
		filteredInputs.append(["Dictionary", "additional_parameters"])

	outputType = "-------- Error --------"

	if len(outputs) > 1:
		outputType = "Dictionary"
	elif len(outputs) == 0:
		outputType = "void"
	else:
		outputType = outputs[0][0]

	return methodOutputType, methodName, newMethodName, inputs, isStatic, filteredInputs, outputs, addtionalParameters, outputType

def GenerateHeaderLine(methodName, filteredInputs, isStatic):
	updatedInputs = ", ".join( map(lambda i : f"{i[0]} {i[1]}" ,filteredInputs) )
	static = "static " if isStatic else ""

	outputLine = f"{static}{GetOrDefault(outputType, input2Output)} {methodName}({updatedInputs});"

	return outputLine

def GenerateBinding(isStatic, className, methodName, inputs):
	processedInputs = ""
	if inputs:
		processedInputs = ", " + ", ".join(map(lambda i : "\"" + i[1] + "\"", inputs))
	if isStatic:
		return f"	ClassDB::bind_static_method(get_class_static(), D_METHOD(\"{methodName}\"{processedInputs}), &{className}::{methodName});"
	else:
		return f"	ClassDB::bind_method( D_METHOD(\"{methodName}\"{processedInputs}), &{className}::{methodName});"

def GenerateCode(className, headerLine, methodName, newMethodName, isStatic, inputs, outputs, methodOutputType, outputType, addtionalParameters):
	codeLinesList = []
	methodCall = f"cv::{methodName}" if isStatic else "---- Not Implemented ----"
	methodInputs = ", ".join([processingLine[i[0]].format(i[1]) if i[0] in processingLine else i[1] for i in inputs])
	returnName = "output" if len(outputs) == 1 and outputs[0][0] not in openCVInputTypes else "defReturn"
	callReturn = "" if methodOutputType ==  "void" else f"{returnName} = "
	first = re.sub(re.escape(newMethodName) + r"\(", f"{className}::{newMethodName}(",headerLine[:-1]) + "{"
	first = re.sub(r"static ", "", first)

	codeLinesList.append(first)

	if len(outputs) != 0:
		codeLinesList.append(f"	{GetOrDefault(outputType, input2Output)} output;")

		if len(outputs) > 1:
			for ou in outputs:
				if GetOrDefault(ou[0], input2Output) == "Ref<CVMat>":
					codeLinesList.append(f"	{GetOrDefault(ou[0], input2Output)} out{ou[1]};")
		if len(outputs) == 1 and GetOrDefault(outputs[0][0], input2Output) == "Ref<CVMat>":
			codeLinesList.append(f"	output.instantiate();")
	
	for i in outputs:
		type = initializingType[i[0]] if i[0] in initializingType else i[0]
		defaultValue = f" = {GetOrDefault(i[2], addParamConversion)}" if len(i) == 3 else ""
		codeLinesList.append(f"	{GetOrDefault(type, openCVOutputTypes)} {i[1]}{defaultValue};")
	
	# Check inputs
	checkNNInputs = [a for a in filteredInputs if "Ref" in GetOrDefault(a[0], input2Output)]
	outputName = "output" if outputType != "void" else ""
	if len(checkNNInputs) > 0:
		codeLinesList.append("")
	for inp in checkNNInputs:
		codeLinesList.append(f"	ERR_FAIL_NULL_V_MSG({inp[1]}, {outputName}, \"{inp[1]} should not be null.\");")

	# Addtional Parameters
	if len(addtionalParameters) > 0:
		codeLinesList.append("")
	for ad in addtionalParameters:
		if "Ref" in ad[0]:
			codeLinesList.append(f"	GET_OBJECT_PROPERTY({ad[0]}, {ad[1]});")
		else:
			default = ad[2] if ad[0] not in convertibleTypes else f"{ad[0]}()"
			codeLinesList.append(f"	GET_SIMPLE_PROPERTY({ad[0]}, Variant::{ad[0].upper()}, {ad[1]}, {default});")


	codeLinesList.append("")

	codeLinesList.append(f"	SAFE_CALL({callReturn}{methodCall}({methodInputs}));")

	## convertOutput
	if len(outputs) == 1:
		so = outputs[0][1]
		if GetOrDefault(outputs[0][0], input2Output) == "Ref<CVMat>":
			codeLinesList.append("")
			codeLinesList.append(f"	output->set_mat({so});")
		if GetOrDefault(outputs[0][0], input2Output) == "Color":
			codeLinesList.append("")
			codeLinesList.append(f"	output = Color({so}[0], {so}[1], {so}[2]);")
	elif len(outputs) > 1:
		codeLinesList.append("")
		for i in outputs:
			if GetOrDefault(i[0], input2Output) == "Ref<CVMat>":
				codeLinesList.append(f"	out{i[1]}->set_mat({i[1]});")
		
		codeLinesList.append("")
		
		for i in outputs:
			if GetOrDefault(i[0], input2Output) == "Ref<CVMat>":
				codeLinesList.append(f"	output[\"{i[1]}\"] = out{i[1]};")
			else:
				codeLinesList.append(f"	output[\"{i[1]}\"] = {i[1]};")

	if len(outputs) != 0:
		codeLinesList.append("")
		codeLinesList.append("	return output;")

	codeLinesList.append("}")

	return "\n".join(codeLinesList)

className = "CVCore"
isStaticClass = True
includes = """#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>"""
inputHeader = ""

with open("automation/Core.in", "r") as f:
	inputHeader = f.readlines()

headerLines = []
bindingLines = []
implementationLines = []

for line in inputHeader:
	if line == "\n":
		continue
	if line[0] == "#":
		continue

	methodOutputType, methodName, newMethodName, \
	inputs, isStatic, filteredInputs, \
	outputs, addtionalParameters, outputType = ProcessTokens(line)
	isStatic = isStaticClass or isStatic
	headerLine = GenerateHeaderLine(newMethodName, filteredInputs, isStatic)
	binding = GenerateBinding(isStatic, className, newMethodName, filteredInputs)
	methodImplementation = GenerateCode(className, headerLine, methodName, newMethodName, isStatic, inputs, outputs, methodOutputType, outputType, addtionalParameters)

	headerLines.append(headerLine)
	bindingLines.append(binding)
	implementationLines.append(methodImplementation)

hTemplate = ""
with open(f"automation/Template.h", "r") as hTemplateFile:
	hTemplate = hTemplateFile.read()

hTemplate = re.sub(r"<ClassName>", className, hTemplate)
hTemplate = re.sub(r"<Includes>", includes, hTemplate)
hTemplate = re.sub(r"<Headers>", "\n\t".join(headerLines), hTemplate)

with open(f"automation/{className}.h", "w") as oh:
	oh.write(hTemplate)

cTemplate = ""
with open(f"automation/Template.cpp", "r") as cTemplateFile:
	cTemplate = cTemplateFile.read()

cTemplate = re.sub(r"<ClassName>", className, cTemplate)
cTemplate = re.sub(r"<Bindings>", "\n".join(bindingLines), cTemplate)
cTemplate = re.sub(r"<Implementation>", "\n\n".join(implementationLines), cTemplate)

with open(f"automation/{className}.cpp", "w") as oc:
	oc.write(cTemplate)
