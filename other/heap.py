'''
# Input Edge
6 8
1 3 1
1 2 3
1 5 5
2 6 4
3 4 2
4 5 1
4 6 4
5 6 1
'''


import sys
from collections import defaultdict

INTMAX = 987654321

class min_heap:
	def __init__(self,arr):
		self.arr = arr

	def swap(self, a, b):
		tmp = a
		a = b
		b = tmp

	def heapify(self, i):
		N = len(self.arr)
		left = i * 2 + 1
		right = i * 2 + 2
		smallest = i

		if left < N and self.arr[left] < self.arr[i]:
			smallest = left
		if right < N and self.arr[right] < self.arr[smallest]:
			smallest = right

		if i != smallest:
			self.arr[i], self.arr[smallest] = self.arr[smallest], self.arr[i]
			self.heapify(smallest)

	def min_build(self):
		for i in range(int(len(self.arr) / 2))[::-1]:
			self.heapify(i)
		return self.arr

	def getArr(self):
		return self.arr


class priority_queue():
	def __init__(self,arr):
		self.arr = arr

	def insert(self, N):
		self.arr.append(N)
		idx = len(self.arr)-1

		while idx != 0:
			if self.arr[idx] < self.arr[(idx-1)//2]:
				self.arr[idx], self.arr[(idx-1)//2] = self.arr[int((idx-1)/2)], self.arr[idx]
				idx = (idx-1) / 2
			else:
				break
		#print(self.arr)
		

	def pop(self):
		ret = self.arr[0]

		self.arr[0] =  self.arr[-1]
		self.arr.pop()

		heap = min_heap(self.arr)
		self.arr = heap.min_build()
		#print(self.arr)
		return ret

	def top(self):
		return self.arr[0]

	def empty(self):
		return not self.arr

	def getPQ(self):
		print(self.arr)


def djikstra(start, graph):
	dist = defaultdict(dict)
	for i in range(1,6+1):
		dist[i] = INTMAX
	dist[1] = 0	

	pq = priority_queue([])

	# first element
	pq.insert((0,1))

	while not pq.empty():
		cost = pq.top()[0]
		loc = pq.top()[1]

		pq.pop()
		if cost > dist[loc]:
			continue

		for edge in graph[loc]:
			next = edge
			next_cost = cost + graph[loc][edge]
			if dist[next] > next_cost:
				dist[next] = next_cost
				pq.insert((next_cost, next))
	
	return dist




if __name__ == '__main__':

	inputFile = open('inputEdge.txt','r')
	V, E = [int(x) for x in inputFile.readline()[:-1].split(' ')]

	graph = defaultdict(dict)

	for line in inputFile.read().splitlines():
		s,e,d = [int(x) for x in line.split(' ')]
		graph[s][e] = d

	print(graph)
	print(djikstra(1, graph))

	'''	
	inputFile = open('input.txt','r')

	for line in inputFile.read().splitlines():
		print("########")
		items  = [int(item) for item in line.split(' ')]
		
		#print(items)
		#t = min_heap(items)
		#t.min_build()
		
		p = priority_queue([])
		for n in items:
			p.insert(n)

		p.pop()
		p.pop()

	'''

