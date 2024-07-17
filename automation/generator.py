import os
import re

openCVOutputTypes = {
	"OutputArray": "Ref<CVMat>",
	"OutputArrayOfArrays":"Array"
	}
input2Output = {
	##"double":"float",
	"Scalar":"Color",
	"Mat":"Ref<CVMat>",
	"InputArray":"Ref<CVMat>",
	"InputOutputArray":"Ref<CVMat>",
	"InputArrayOfArrays":"Array"
	}
input2Output.update(openCVOutputTypes)

processingLine = {
	"Mat": f"->get_mat()",
	"InputArray": f"->get_mat()",
	"InputOutputArray": f"->get_mat()",
	"Scalar": f"cv::Scalar(color.b, color.g, color.r) * 255" ## Simplify
}
initializingType = {
	"Mat":"cv::Mat",
	"InputArray":"cv::Mat",
	"InputOutputArray":"cv::Mat",
	"OutputArray": "cv::Mat",
}

def GetOrDefault(val : str, list : dict):
	tmp = list.get(val)
	return tmp if tmp else val

def ProcessTokens(line : str):
	isStatic = bool(re.match(r"static ", line))
	line = re.sub(r"([\w\d]+::)|const |&|static ", "", line)
	inputs = re.search(r"(?<=\()[\w\d ,_()=\-&]*(?=\))", line)
	split = line.split()
	methodOutputType = split[0]
	methodName = split[1]

	if inputs:
		inputs = inputs.group().split(", ")
		inputs = [re.split(r"=| ", i) for i in inputs]

	return methodOutputType, methodName, inputs, isStatic

def GenerateHeaderLine(methodOutputType, methodName, inputs):
	filteredInputs = []
	addtionalParameters = False
	outputs = [[ methodOutputType, "defReturn" ]] if methodOutputType != "void" else []

	for input in inputs:
		if input[0] in openCVOutputTypes:
			newOutput = [ input[0] ]
			newOutput.extend(input[1:])
			outputs.append(newOutput)
			continue

		if len(input) == 2:
			newInput = [GetOrDefault(input[0], input2Output)]
			newInput.extend(input[1:])
			filteredInputs.append(newInput)
		
		if len(input) == 3:
			addtionalParameters = True

		if len(input) < 2 or len(input) > 3:
			print("-------- Error --------")
			break
	
	if addtionalParameters:
		filteredInputs.append(["Dictionary", "additional_parameters"])

	updatedInputs = ", ".join( map(lambda i : f"{i[0]} {i[1]}" ,filteredInputs) )

	outputType = "-------- Error --------"

	if len(outputs) > 1:
		outputType = "Dictionary"
	elif len(outputs) == 0:
		outputType = "void"
	else:
		outputType = outputs[0][0]

	outputLine = f"{GetOrDefault(outputType, input2Output)} {methodName}({updatedInputs});"

	return outputLine, filteredInputs, outputs, addtionalParameters, outputType

def GenerateBinding(isStatic, className, methodName, inputs):
	processedInputs = ""
	if inputs:
		processedInputs = ", " + ", ".join(map(lambda i : "\"" + i[1] + "\"", inputs))
	if isStatic:
		return f"ClassDB::bind_static_method(get_class_static(), D_METHOD(\"{methodName}\"{processedInputs}), &{className}::{methodName});"
	else:
		return f"ClassDB::bind_method( D_METHOD(\"{methodName}\"{processedInputs}), &{className}::{methodName});"

def GenerateCode(className, headerLine, methodName, isStatic, inputs, outputs, methodOutputType, outputType):
	codeLinesList = []
	methodCall = f"cv::{methodName}" if isStatic else "---- Not Implemented ----"
	methodInputs = ", ".join([i[1] + processingLine[i[0]] if i[0] in processingLine else i[1] for i in inputs])
	returnName = "output" if len(outputs) == 1 and outputs[0][0] not in input2Output else "defReturn"
	callReturn = "" if methodOutputType ==  "void" else f"{returnName} = "

	codeLinesList.append(re.sub(methodName, f"{className}::{methodName}",headerLine[:-1]) + "{")
	codeLinesList.append("")

	if len(outputs) != 0:
		codeLinesList.append(f"	{GetOrDefault(outputType, input2Output)} output;")
		if len(outputs) == 1 and GetOrDefault(outputs[0][0], input2Output) == "Ref<CVMat>":
			codeLinesList.append(f"	output.instantiate();")
	
	for i in outputs:
		type = initializingType[i[0]] if i[0] in initializingType else i[0]
		defaultValue = f"= {i[2]}" if len(i) == 3 else ""
		codeLinesList.append(f"	{GetOrDefault(type, openCVOutputTypes)} {i[1]}{defaultValue};")
	
	codeLinesList.append("")

	codeLinesList.append(f"	SAFE_CALL({callReturn}{methodCall}({methodInputs}));")
		
	codeLinesList.append("")

	## convertOutput
	if len(outputs) == 1:
		so = outputs[0][1]
		if GetOrDefault(outputs[0][0], input2Output) == "Ref<CVMat>":
			codeLinesList.append(f"	output->set_mat({so})")
		if GetOrDefault(outputs[0][0], input2Output) == "Color":
			codeLinesList.append(f"	output = Color({so}[0], {so}[1], {so}[2]);")
	else:
		for i in outputs:
			if i[0] == "Ref<CVMat>":
				codeLinesList.append(f"	out{i[1]}->set_mat({i[1]})")

	codeLinesList.append("")
	
	if len(outputs) != 0:
		codeLinesList.append("	return output;")

	codeLinesList.append("}")

	return "\n".join(codeLinesList)

f = open("automation/Core.in", "r")
className = "CVCore"
isStaticClass = True

for line in f.readlines():
	try:
		methodOutputType, methodName, inputs, isStatic = ProcessTokens(line)
		isStatic = isStaticClass or isStatic
		headerLine, filteredInputs, outputs, addtionalParameters, outputType = GenerateHeaderLine(methodOutputType, methodName, inputs)
		binding = GenerateBinding(isStatic, className, methodName, filteredInputs)
		methodImplementation = GenerateCode(className, headerLine, methodName, isStatic, inputs, outputs, methodOutputType, outputType)

		print(line, end="")
		##print(outputs)
		print(headerLine)
		print(binding, "\n")
		print(methodImplementation, "\n")
	except Exception as err:
		print(err)
		print("-------- Error --------")
