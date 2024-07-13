import os
import re

input2Output = {
	"Scalar":"Color",
	"InputArray":"Ref<CVMat>", 
	"InputArrayOfArrays":"Array"
	}
outputTypes = {"OutputArray": "Ref<CVMat>"}

def ConvertType(inputType):
	type = input2Output.get(inputType)
	return type if type else inputType

def ProcessTokens(line):
	line = re.sub(r"[\w\d]+::", "", line)
	inputs = re.search(r"(?<=\()[\w\d ,_()=\-&]*(?=\))", line)
	split = line.split()
	outputType = split[0]
	methodName = split[1]

	if inputs:
		inputs = inputs.group().split(", ")
		inputs = [re.split(r"=| ", i) for i in inputs]

	return (outputType, methodName, inputs)

def WriteHeaderLine(outputType, methodName, inputs):
	tmpList = []
	addtionalParameters = False
	outputs = [outputType]

	for input in inputs:
		if input[0] in outputTypes:
			outputs.append(outputTypes[input[0]])
			continue

		if len(input) == 2:
			inputType = ConvertType(input[0])
			tmpList.append( f"{inputType} {input[1]}" )
		
		if len(input) == 3:
			addtionalParameters = True

		if len(input) < 2 or len(input) > 3:
			print("-------- Error --------")
			break
	
	updatedInputs = ", ".join(tmpList)

	if addtionalParameters:
		updatedInputs += ", Dictionary additional_parameters"

	outputs = [ ConvertType(o) for o in outputs if o != "void" ]

	type = "-------- Error --------"

	if len(outputs) > 1:
		type = "Dictionary"
	elif len(outputs) == 0:
		type = "void"
	else:
		type = outputs[0]

	outputLine = f"{type} {methodName}({updatedInputs});"

	return outputLine

f = open("automation/Core.in", "r")

for line in f.readlines():
	print(line, end="")
	try:
		outputType, methodName, inputs = ProcessTokens(line)
		outputLine = WriteHeaderLine(outputType, methodName, inputs)

		print(outputLine, "\n")
	except:
		print("-------- Error --------")
