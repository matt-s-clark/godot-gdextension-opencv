from os import listdir
from os.path import isfile, join
import re

openCVInputTypes = {
	"Scalar":"Ref<CVScalar>",
	"Point": "Vector2",
	"Point2f": "Vector2",
	"Size": "Vector2",
	"Mat":"Ref<CVMat>",
	"InputArray":"Ref<CVMat>",
	"InputOutputArray":"Ref<CVMat>",
	"Rect":"Ref<CVRect>",
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
	"Mat": "{0}->get_pointer()",
	"InputArray": "{0}->get_pointer()",
	"InputOutputArray": "{0}->get_pointer()",
	"Rect": "{0}->get_pointer()",
	"Scalar": "{0}->get_pointer()",
	"Point": "Point({0}.x, {0}.y)",
	"Point2f": "Point2f({0}.x, {0}.y)",
	"Size": "Size({0}.x, {0}.y)",
}
initializingType = {
	"Mat":"Mat",
	"InputArray":"Mat",
	"InputOutputArray":"Mat",
	"OutputArray": "Mat",
	"Scalar": "Scalar"
}
addParamConversion = {
	"noArray()":"Mat()",
}
convertibleTypes = ["Point", "Size", "Point2f"]
pointerTypes = ["Ref<CVMat>", "Ref<CVScalar>", "Ref<CVRect>"]

def GetOrDefault(val : str, list : dict):
	tmp = list.get(val)
	return tmp if tmp else val

def ProcessTokens(line : str):
	isStatic = bool(re.match(r"static ", line))
	line = re.sub(r"([\w\d]+::)|const |&|static |(?<=<) | (?=>)|\*", "", line)
	inputs = re.search(r"(?<=\()[\w\d ,_()=\-&*\.<>+\[\]]+(?=\))", line)
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
			newInput = [GetOrDefault(input[0], input2Output), input[1], input[2], input[0]]
			addtionalParameters.append(newInput)

		if len(input) < 2 or len(input) > 3:
			print("Failed input ", input)
			print(line)
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

def GenerateHeaderLine(methodName, filteredInputs, isStatic, outputType):
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

def GenerateCode(className, headerLine, methodName, newMethodName, isStatic, inputs, outputs, methodOutputType, outputType, addtionalParameters, filteredInputs):
	codeLinesList = []
	methodCall = f"cv::{methodName}" if isStatic else "---- Not Implemented ----"
	methodInputs = ", ".join([processingLine[i[0]].format(i[1]) if i[0] in processingLine and (i[0] in initializingType or i[1] not in map(lambda ad : ad[1], addtionalParameters)) else i[1] for i in inputs])
		
	returnName = "output" if len(outputs) == 1 and outputs[0][0] not in openCVInputTypes else "defReturn"
	callReturn = "" if methodOutputType ==  "void" else f"{returnName} = "
	first = re.sub(re.escape(newMethodName) + r"\(", f"{className}::{newMethodName}(",headerLine[:-1]) + "{"
	first = re.sub(r"static ", "", first)

	codeLinesList.append(first)

	if len(outputs) != 0:
		codeLinesList.append(f"	{GetOrDefault(outputType, input2Output)} output;")

		if len(outputs) > 1:
			for ou in outputs:
				if "Ref<" in GetOrDefault(ou[0], input2Output):
					codeLinesList.append(f"	{GetOrDefault(ou[0], input2Output)} out{ou[1]};")
					codeLinesList.append(f"	out{ou[1]}.instantiate();")
		if len(outputs) == 1 and "Ref<" in GetOrDefault(outputs[0][0], input2Output):
			codeLinesList.append(f"	output.instantiate();")
	
	for i in outputs:
		type = initializingType[i[0]] if i[0] in initializingType else i[0]
		defaultValue = f" = {GetOrDefault(i[2], addParamConversion)}" if len(i) == 3 else ""
		codeLinesList.append(f"	{GetOrDefault(type, openCVOutputTypes)} {i[1]}{defaultValue};")

	# Check inputs
	checkNNInputs = [a for a in filteredInputs if "Ref<" in GetOrDefault(a[0], input2Output)]
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
			codeLinesList.append(f"	GET_OBJECT_PROPERTY({ad[0]}, {ad[1]}, {GetOrDefault(ad[2], addParamConversion)});")
		elif ad[3] in convertibleTypes:
			codeLinesList.append(f"	GET_CONVERTIBLE_PROPERTY({ad[3]}, Variant::{ad[0].upper()}, {ad[1]}, {ad[2]});")
		else:
			codeLinesList.append(f"	GET_SIMPLE_PROPERTY({ad[0]}, Variant::{ad[0].upper()}, {ad[1]}, {ad[2]});")


	codeLinesList.append("")

	codeLinesList.append(f"	SAFE_CALL({callReturn}{methodCall}({methodInputs}));")

	## convertOutput
	if len(outputs) == 1:
		so = outputs[0][1]
		if GetOrDefault(outputs[0][0], input2Output) in pointerTypes:
			codeLinesList.append("")
			codeLinesList.append(f"	output->set_pointer({so});")
	elif len(outputs) > 1:
		codeLinesList.append("")
		for i in outputs:
			if GetOrDefault(i[0], input2Output) in pointerTypes:
				codeLinesList.append(f"	out{i[1]}->set_pointer({i[1]});")
		
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

def ProcessFile(file, className, isStaticClass, includes):
	inputHeader = ""
	with open(file, "r") as f:
		inputHeader = f.readlines()

	headerLines = []
	bindingLines = []
	implementationLines = []

	CustomImplementationFlag = 0
	CustomImplementationCode = []

	for line in inputHeader:
		if line[0] == "#":
			continue
		
		# Process Custom Implementation
		if line.startswith(">CustomImplementation"):
			CustomImplementationFlag = 1
			continue
		if line.startswith("<CustomImplementation"):
			CustomImplementationFlag = 0
			implementationLines.append("// Custom Implementation")
			implementationLines.append("\n".join(CustomImplementationCode))
			CustomImplementationCode = []
			continue
		
		if CustomImplementationFlag == 1:
			headerLines.append(line[:-1])
			CustomImplementationFlag +=1
			continue
		elif CustomImplementationFlag == 2:
			bindingLines.append(f"	{line[:-1]}")
			CustomImplementationFlag +=1
			continue
		elif CustomImplementationFlag == 3:
			CustomImplementationCode.append(line[:-1])
			continue

		if line == "\n":
			continue

		# Process input line
		methodOutputType, methodName, newMethodName, \
		inputs, isStatic, filteredInputs, \
		outputs, addtionalParameters, outputType = ProcessTokens(line)
		isStatic = isStaticClass or isStatic
		headerLine = GenerateHeaderLine(newMethodName, filteredInputs, isStatic, outputType)
		binding = GenerateBinding(isStatic, className, newMethodName, filteredInputs)
		methodImplementation = GenerateCode(className, headerLine, methodName, newMethodName, isStatic, inputs, outputs, methodOutputType, outputType, addtionalParameters, filteredInputs)

		headerLines.append(headerLine)
		bindingLines.append(binding)
		implementationLines.append(methodImplementation)

	hTemplate = ""
	with open(f"automation/templates/Template.h", "r") as hTemplateFile:
		hTemplate = hTemplateFile.read()

	hTemplate = re.sub(r"<HeaderClassName>", className.upper(), hTemplate)
	hTemplate = re.sub(r"<ClassName>", className, hTemplate)
	hTemplate = re.sub(r"<Includes>", includes, hTemplate)
	hTemplate = re.sub(r"<Headers>", "\n\t".join(headerLines), hTemplate)

	with open(f"src/{className}.h", "w") as oh:
		oh.write(hTemplate)

	cTemplate = ""
	with open(f"automation/templates/Template.cpp", "r") as cTemplateFile:
		cTemplate = cTemplateFile.read()

	cTemplate = re.sub(r"<ClassName>", className, cTemplate)
	cTemplate = re.sub(r"<Bindings>", "\n".join(bindingLines), cTemplate)
	cTemplate = re.sub(r"<Implementation>", "\n\n".join(implementationLines), cTemplate)

	with open(f"src/{className}.cpp", "w") as oc:
		oc.write(cTemplate)


if __name__ == "__main__":
	isStaticClass = True
	includes = """#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include \"CVRect.h\"
#include \"CVScalar.h\"
#include \"HelperFunctions.h\""""

	inputPath = "automation/inputs/"
	inputFiles = [f for f in listdir(inputPath) if isfile(join(inputPath, f))]

	for file in inputFiles:
		ProcessFile(join(inputPath, file), f"CV{file.replace(".in", "")}", isStaticClass, includes)

