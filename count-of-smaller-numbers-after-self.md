# Count of Smaller Numbers After Self

## Problem



You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.

**Example 1:**

```text
Input: nums = [5,2,6,1]
Output: [2,1,1,0]

Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
```



.

.

.



## Idea

* Merge sort..

## Complexity

* Time: $$O(n^2)$$
* Space: $$O(n)$$

## Code 

```java
import java.util.*;

class Program {
  public static List<Integer> rightSmallerThan(List<Integer> array) {
		List<Integer> rst = new ArrayList<>();
		List<Integer> indexArray = new ArrayList<>();
		for (int i=0; i<array.size(); i++) {
			rst.add(0);
			indexArray.add(i);
		}
	
    mergeSort(rst, indexArray, array, 0, array.size()-1);
		
    return rst;
  }
	
	// 0 1 2 3 -> 
	public static void mergeSort(List<Integer> rst, List<Integer> indexArray, List<Integer> array, int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			
			mergeSort(rst, indexArray, array, left, mid );
			mergeSort(rst, indexArray, array, mid+1, right);
			
			merge(rst, indexArray, array, left, mid, right);
		} 
	}
	
	public static void merge(List<Integer> rst, List<Integer> indexArray, List<Integer> array, int left, int mid, int right) {
		int count = 0;
		
		List<Integer> tempIndexArray = new ArrayList<>();
		
		int l = left, r = mid+1;
		while(l <= mid && r <= right) {
			if (array.get(indexArray.get(l)) <= array.get(indexArray.get(r))) {
				rst.set(indexArray.get(l), rst.get(indexArray.get(l))+count);
				tempIndexArray.add(indexArray.get(l++));
			}
			else {
				count += 1;
				tempIndexArray.add(indexArray.get(r++));
			}
		}
		while(l <= mid) {
			rst.set(indexArray.get(l), rst.get(indexArray.get(l)) + count);
			tempIndexArray.add(indexArray.get(l++));
		}
		while(r <= right) {
			tempIndexArray.add(indexArray.get(r++));
		}
		
		for (int i=0; i<tempIndexArray.size(); i++) {
			indexArray.set(left+i, tempIndexArray.get(i));
		}
	}
}

```

## Ref

* [https://leetcode.com/problems/count-of-smaller-numbers-after-self/](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

## Tag

`#merge-sort`

