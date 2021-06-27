# Kth Largest Element in an Array

## Problem



Given an integer array `nums` and an integer `k`, return _the_ `kth` _largest element in the array_.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

**Example 1:**

```text
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```



.

.

.



## Idea

* Quick Select

## Complexity

* Time: $$O(nlogn)$$
* Space: $$O(1)$$

## Code 

{% tabs %}
{% tab title="quick select" %}
```java
import java.util.*;

class Program {
  public static int quickselect(int[] array, int k) {
    
    return quickselect(array, 0, array.length-1, k-1);
  }
	
	public static int quickselect(int[] array, int left, int right, int position) {
		while(left <= right) {
			int pivot = partition(array, left, right);
			
			if (pivot == position) {
				return array[pivot];
			}
			else if (pivot < position) {
				left = pivot + 1;
			}
			else {
				right = pivot - 1;
			}
		}
		
		return -1;
	}
	
	public static int partition(int[] array, int left, int right) {
		int pivot = left;
		int l = left + 1;
		int r = right;
		
		while(l <= r) {
			if (array[l] > array[pivot] && array[pivot] > array[r]) {
				swap(array, l, r);
			}
			if (array[l] <= array[pivot]) {
				l+=1;
			}
			if (array[r] >= array[pivot]) {
				r-=1;
			}
		}
		swap(array, pivot, r);
		
		return r;
	}
	
	public static void swap(int[] array, int l, int r) {
		int tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

```
{% endtab %}

{% tab title="priority queue" %}
```java
// Priority queue with size k

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i=0; i<nums.length; i++) {
            if (i < k) {
                pq.offer(nums[i]);
            }
            else {
                if (pq.peek() < nums[i]) {
                    pq.poll();
                    pq.offer(nums[i]);
                }
            }
        }
        
        return pq.peek();
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/kth-largest-element-in-an-array/](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## Tag

`#quick-select` `#priority-queue` `#kth`

