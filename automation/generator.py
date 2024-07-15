import os
import re

input2Output = {
	"double":"float",
	"Scalar":"Color",
	"Mat":"Ref<CVMat>",
	"InputArray":"Ref<CVMat>",
	"InputOutputArray":"Ref<CVMat>",
	"InputArrayOfArrays":"Array"
	}
outputTypes = {
	"OutputArray": "Ref<CVMat>",
	"OutputArrayOfArrays":"Array"
	}

def ConvertType(inputType):
	type = input2Output.get(inputType)
	return type if type else inputType

def ProcessTokens(line):
	line = re.sub(r"([\w\d]+::)|const |&", "", line)
	inputs = re.search(r"(?<=\()[\w\d ,_()=\-&]*(?=\))", line)
	split = line.split()
	outputType = split[0]
	methodName = split[1]

	if inputs:
		inputs = inputs.group().split(", ")
		inputs = [re.split(r"=| ", i) for i in inputs]

	return outputType, methodName, inputs

def WriteHeaderLine(outputType, methodName, inputs):
	tmpList = []
	filteredInputs = []
	addtionalParameters = False
	outputs = [[ ConvertType(outputType), "Default" ]]

	for input in inputs:
		if input[0] in outputTypes:
			newOutput = [ outputTypes[input[0]] ]
			newOutput.extend(input[1:])
			outputs.append(newOutput)
			continue

		if len(input) == 2:
			inputType = ConvertType(input[0])
			filteredInputs.append([inputType, input[1]])
		
		if len(input) == 3:
			addtionalParameters = True

		if len(input) < 2 or len(input) > 3:
			print("-------- Error --------")
			break
	
	if addtionalParameters:
		filteredInputs.append(["Dictionary", "additional_parameters"])

	updatedInputs = ", ".join( map(lambda i : f"{i[0]} {i[1]}" ,filteredInputs) )

	outputs = [ o for o in outputs if o[0] != "void" ]

	type = "-------- Error --------"

	if len(outputs) > 1:
		type = "Dictionary"
	elif len(outputs) == 0:
		type = "void"
	else:
		type = outputs[0][0]

	outputLine = f"{type} {methodName}({updatedInputs});"

	return outputLine, filteredInputs, outputs, addtionalParameters

def WriteBinding(isStatic, className, methodName, inputs):
	processedInputs = ""
	if inputs:
		processedInputs = ", " + ", ".join(map(lambda i : "\"" + i[1] + "\"", inputs))
	if isStatic:
		return 
	else:
		return f"ClassDB::bind_method( D_METHOD(\"{methodName}\"{processedInputs}), &{className}::{methodName});"

f = open("automation/Core.in", "r")
className = "CVCore"
isStatic = False

for line in f.readlines():
	try:
		outputType, methodName, inputs = ProcessTokens(line)
		headerLine, filteredInputs, outputs, addtionalParameters = WriteHeaderLine(outputType, methodName, inputs)
		binding = WriteBinding(isStatic, className, methodName, filteredInputs)

		print(line, end="")
		##print(outputs)
		print(headerLine)
		print(binding, "\n")
	except Exception as err:
		print(err)
		print("-------- Error --------")
