import sys

# python3 check.py output.txt test/dt_answer1.txt

if __name__ == "__main__":

	output = open(sys.argv[1], "r")
	answer = open(sys.argv[2], "r")

	op = output.readline()[:-1]
	answer.readline()

	idx = len(op.split('\t'))

	ansData = [line.split('\t')[idx] for line in answer.read().splitlines()]
	outputData = [line.split('\t')[idx] for line in output.read().splitlines()]

	match = 0

	total = len(ansData)
	for i in range(total):
		if ansData[i] == outputData[i]:
			match += 1

	print(match, end= " / ")
	print(total)


# pre-pruning with 2 : 251 / 346
# pre-pruning with 3 : 281 / 346
# pre-pruning with 4 : 312 / 346
# pre-pruning with 6 : 315 / 346
# pre-pruning with 7 : 314 / 346
# pre-pruning with 8 : 315 / 346
# pre-pruning with 9 : 310 / 346
# pre-pruning with 10 : 305 / 346