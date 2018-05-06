import sys
from collections import defaultdict

def beyesian(rules, attr, dataCnt, classCnt):
	
	max = 0 
	size = len(dataCnt)
	raplacian = 0
	for c in classCnt:
		pxc = 1

		for idx in range(len(rules)):
			rule = makeRule(attr[idx], rules[idx])

			if(dataCnt.get(rule,0) == 0):
				raplacian = 1
		
			pxc *= (float(dataCnt[rule][c] + raplacian) / (classCnt[c] + raplacian*(size)))

		pxc *= classCnt[c]

		if(max < pxc):
			max = pxc
			rst = c
			
	i = rst.index('=')

	return rst[i+1:]


def makeRule(attr, value):
	return attr + "=" + value


# attr : {0 : "attr0", 1 : "attr1", ... }
# classCnt : { class1 : n1, class2 : n2, ... }
# P(X|C), dataCnt['attr=value']['class'] = count
def makeDataSet(dataSet):

	attrTmp = dataSet.readline()[:-1].split('\t')
	attr = defaultdict(int)
	for i in range(len(attrTmp)):
		attr[i] = attrTmp[i]
	
	classIdx = len(attr) - 1
	classCnt = defaultdict(int)
	
	dataCnt = defaultdict(lambda: defaultdict(int))

	for line in dataSet:
		items = line[:-1].split('\t')

		classified = makeRule(attr[classIdx], items[classIdx])
		classCnt[classified] += 1

		for idx in range(len(items)-1):
			rule = makeRule(attr[idx], items[idx])
			dataCnt[rule][classified] += 1

	return dataCnt, classCnt, attr


# Read Test File and make output file which have classified data
# [[1,2,3], [2,3,3]] => outputFile
def predictDataSet(test, output, attr, dataCnt, classCnt):

	label = test.readline()
	output.write(label)

	for line in test.read().splitlines():
		output.write(line)
		output.write('\t')

		l = line.split('\t')

		output.write(beyesian(l, attr, dataCnt, classCnt))	
		output.write('\n')



if __name__ == "__main__":
	trainingSet = open(sys.argv[1],"r")
	testSet = open(sys.argv[2], "r")
	output = open(sys.argv[3], "w")

	dataCnt, classCnt, attr = makeDataSet(trainingSet)

	a = beyesian(['<=40', 'medium', 'yes', 'fair'], attr, dataCnt, classCnt)
	print(a)

	#predictDataSet(testSet, output, attr, dataCnt, classCnt)