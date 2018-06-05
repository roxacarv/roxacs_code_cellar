from random import randint

def BubbleSort(arrayToSort):
	change = False
	for i in range(len(arrayToSort)-1):
		if(arrayToSort[i] > arrayToSort[i+1]):
			bufferElement = arrayToSort[i]
			arrayToSort[i] = arrayToSort[i+1]
			arrayToSort[i+1] = bufferElement
			change = True
	if(change):
		return BubbleSort(arr)
	else:
		return arr

def TestSorting():
	newArrayToSort = []
	for i in range(1000):
		newArrayToSort.append(randint(0, 10000))
	result = BubbleSort(newArrayToSort)
	print(result)

while True:
	if(input() == "0"):
		break
	else:
		TestSorting()
