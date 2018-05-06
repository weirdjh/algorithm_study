from collections import defaultdict

## 1. Array Pair Sum
## Input : Integer Arr
## Output : All pairs that sum up to a specific value k

# O(nlogn)
def Array_pair_sum1(arr, k):
	ans = []

	if len(arr) < 2:
		return

	left, right = (0, len(arr)-1)

	# sorting
	arr.sort()

	while(left < right):
		if arr[left] + arr[right] == k:
			ans.append((arr[left], arr[right]))
			left += 1

		elif arr[left] + arr[right] < k:
			left += 1

		elif arr[left] + arr[right] > k:
			right -= 1

	print(ans)
	return

# O(n)
def Array_pair_sum2(arr, k):
	ans = []
	dp = dict()

	for num in arr:
		if num in dp.values():			
			ans.append((num, k-num))
		else:
			dp[num] = k-num

	print(ans)
	return


## 2. Largest Continuous Sum (Kadane's algorithm)
## Input : Arr
## Output : lcs

#O(N)
def Largest_continuous_sum(arr):
	max_so_far = max_part = 0

	for num in arr:
		max_part += num
		if (max_part < 0):
			max_part = 0
		if (max_so_far < max_part):
			max_so_far = max_part

	print(max_so_far)
	return


## 3. Find Missing Element
## Input : Arr1, Arr2 (Non-negative)
## Output : Missing Element

def Find_missing_element(arr1, arr2):
	result = 0

	# 3^7 = 0011 ^ 0111 = 0100 = 4
	# 4^7 = 0100 ^ 0111 = 0011 = 3
	# Flip bit twice --> original
	for num in arr1+arr2:
		result ^= num
	print(result)
	return


## 4. K'th Largest Element
## Input : Arr
## Output : K'th Largest Element

def K_Largest_Element(arr, k):

	# find pivot (q-sort)
	# [5][1 4 3 7 10 9 14] => low = 4, high = 3
	# [3 1 4 "5" 7 10 9 14] => pivot = 3
	def partition(arr, left, right):
		pos = arr[left]
		low, high = left + 1, right
	
		while(low <= high):
			while(low <= right and pos >= arr[low]):
				low += 1
			while((left+1) <= high and pos <= arr[high]):
				high -= 1
			if (low <= high):
				arr[low], arr[high] = arr[high], arr[low]

		arr[left], arr[high] = arr[high], arr[left]

		return high

	def quick_select(arr, left, right, select):
		if (select > 0 and select <= right-left+1):
			pivot = partition(arr,left,right)

			if(right - pivot + 1 == select):
				return arr[pivot]

			# 'select' is in SMALL GROUP based on Pivot
			elif(right - pivot + 1 < select):
				return quick_select(arr,left,pivot-1,select-(right-(pivot-1)) )

			# 'select' is in LARGE GROUP based on Pivot
			else:
				return quick_select(arr,pivot+1,right,select)
		return -1

	ret = quick_select(arr, 0, len(arr)-1, k)
	print(ret)
	return


## 5. Find Median Dynamically
## Input : number
## Output : median

import heapq

class MaxHeapObj(object):
	def __init__(self, val): self.val = val
	def __lt__(self, other): return self.val > other.val
	def __eq__(self, other): return self.val == other.val
	def __str__(self): return str(self.val)

class MinHeap(object):
	def __init__(self): self.h = []
	def heappush(self, x): heapq.heappush(self.h, x)
	def heappop(self): return heapq.heappop(self.h)
	def __len__(self): return len(self.h)
	def top(self): return self.h[0]
	def printheap(self): print(self.h)

class MaxHeap(MinHeap):
	def heappush(self, x): heapq.heappush(self.h, MaxHeapObj(x))
	def heappop(self): return heapq.heappop(self.h).val
	def __len__(self): return len(self.h)
	def top(self): return self.h[0].val
	def printheap(self): 
		print('[', end='')
		for i in self.h: 
			print(i.val, end=', ')
		print(']')

def find_median(input_number):
	# Lower : Max heap
	# Higher : Min heap
	#
	# ['3' 1 2]['4' 6 7] ==> middle of maxh & minh
	# ["3" 1 2 0][4 6 7] ==> top of maxh
	maxh = MaxHeap()
	minh = MinHeap()

	trace = []

	# standard number = maxh.top()
	maxh.heappush(input_number[0])
	trace.append(input_number[0])

	for num in input_number[1:]:
		trace.append(num)

		if(num < maxh.top()):
			maxh.heappush(num)
		else:
			minh.heappush(num)
		
		# adjust the number of maxh and minh
		if (minh.__len__()+1 < maxh.__len__()):
			x = maxh.heappop()
			minh.heappush(x)
		elif(maxh.__len__() < minh.__len__()):
			x = minh.heappop()
			maxh.heappush(x)

		trace.sort()
		print(trace)
		if (minh.__len__() == maxh.__len__()):
			print(float(minh.top() + maxh.top())/2)
		else:
			print(maxh.top())


## 6. Minimum Window Substring
## Input: string S, string T
## Output: minimum window in S which will contain all the characters in T
## Complexity: O(N)
## https://leetcode.com/problems/minimum-window-substring/description/
'''
ADOBECODEBANC  : [A, B, C]
s              : [1, 1, 1]
s    e         : [0, 0, 0] => ADOBEC
 s    e        : [1, 0, 0]
 s        e    : [0,-1, 0] => DOBECODEBA 
  s       e    : [0,-1, 0] => OBECODEBA 
   s      e    : [0, 0, 0] => BECODEBA 
    s     e    : [0, 0, 0] => ECODEBA
     s    e    : [0, 0, 0] => CODEBA
      s    e   : [0, 0, 1] 
      s     e  : [0, 0, 0] => ODEBANC
       s    e  : [0, 0, 0] => DEBANC
        s   e  : [0, 0, 0] => EBANC
         s   e : [0, 0, 0] => BANC
'''
def Minimum_window_substring(S, T):
	
	# Two pointer
	start = end = 0

	# Check whether the substring is valid
	# the number of required elements
	count = len(T)
	misStart = -1
	minLength = 987654321

	# d[i] : the number of element i that's required for a "valid" window
	# No need to consider other elements
	d = defaultdict(int)
	for c in T:
		d[c] = 1

	while(end < len(S)):
		print(str(start) + ' ' + str(end) + ' ' + str(count))
		# if S[end] is a required element
		if(d[S[end]] > 0):
			# found element :D
			count -= 1

		d[S[end]] -= 1
		end += 1

		# all required elements are in the current window
		while(count == 0):
			print('#' + str(start) + ' ' + str(end) + ' ' + str(count))
			if (end- start < minLength):
				minStart = start
				minLength = end- start
			
			# required elements passed
			if (d[S[start]] >= 0):
				count += 1
			
			d[S[start]] += 1
			start += 1

	print(S[minStart:minStart+minLength])
	return


## 7. LRU Cache
## Implement with Double Linked List
## HEAD - node - node - ... - TAIL
## remove the next of the HEAD node
## add new node before the TAIL node
## https://leetcode.com/problems/lru-cache/description/

## Complexity of get & set : O(1)

import random

class LRUNode:
	def __init__(self, k, v):
		self.key = k
		self.val = v
		self.prev = None
		self.next = None

class LRUCache:
	def __init__(self,capacity):
		self.capacity = capacity
		self.dic = dict()
		self.head = LRUNode(0, 0)
		self.tail = LRUNode(0, 0)
		self.head.next = self.tail
		self.tail.prev = self.head

	# Key exists => move it to tail
	def get(self, key):
		if key in self.dic:
			n = self.dic[key]
			self._remove(n)
			self._add(n)
			return n.val
		return -1


	def set(self, key, value):

		# Already exists
		if key in self.dic:
			self._remove(self.dic[key])

		# new Node
		n = LRUNode(key, value)
		self._add(n)
		self.dic[key] = n

		# cache exceeds capacity
		if len(self.dic) > self.capacity:
			print("memory exceeds : evicts (%d, %d)" % (n.key, n.val))
			n = self.head.next
			self._remove(n)
			del self.dic[n.key]

	def _remove(self, node):
		p = node.prev
		n = node.next
		p.next = n
		n.prev = p

	def _add(self, node):
		p = self.tail.prev
		p.next = node
		self.tail.prev = node
		node.prev = p
		node.next = self.tail

# Cache capacity : 50
# random key with range [1, 100)
# random value with range [100, 200)
# get : 500
def Cache_usage():
	LRU = LRUCache(50)

	hit = 0
	miss = 0
	for i in range(500):
		key = random.randrange(1, 100)

		value_from_cache = LRU.get(key)
		if(value_from_cache != -1):
			hit += 1
			print("hit : (%d, %d)" % (key, value_from_cache))

		else:
			value = random.randrange(100, 200)
			LRU.set(key,value)
			value_from_cache = LRU.get(key)
			miss += 1
			print("miss : update (%d, %d)" % (key, value_from_cache))

	print("Hit ratio = ", end='')
	print(float(hit)/(hit+miss))


## 8. Largest Rectangle in Histogram
## Input : height of each rectangles
## Ouput : Largest Rectangle
## https://leetcode.com/problems/largest-rectangle-in-histogram/description/
## https://www.acmicpc.net/blog/view/12

# Complexity : O(N)

# Bigger or equal => keep it into stack
# Else => pop & calculate area
def Largest_rectangle(heights):
	heights.append(0)
	stack = [-1]
	area = 0
	for i in range(len(heights)):
		while heights[i] < heights[stack[-1]]:
			h = heights[stack.pop()]
			
			# left = stack[-1], right = i-1
			w = i - stack[-1] - 1
			area = max(area, h * w)
		stack.append(i)
	heights.pop()
	print(area)
	return


if __name__ == "__main__":

	#Array_pair_sum1([1,8,3,5,4,6,7,11], 15)
	#Array_pair_sum2([1,8,3,5,4,6,7,11], 15)
	#Largest_continuous_sum([-2,-3,4,-1,-2,1,5,-3])
	#Find_missing_element([4,1,0,2,9,6,8,7,5,3], [6,4,7,2,1,0,8,3,9])
	#K_Largest_Element([5,1,4,3,7,10,9,14], 4)
	#find_median([3,2,4,1,6,7,0])
	#Minimum_window_substring("ADOBECODEBANC", "ABC")
	#Cache_usage()
	Largest_rectangle([2,1,5,6,2,3])
