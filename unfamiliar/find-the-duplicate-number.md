# Find the Duplicate Number

## Problem

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`, return _this repeated number_.

## Example

```text
Input: nums = [3,1,3,4,2]
Output: 3
```

.

.

.



## Idea

* Find correct position \(modify array\)
* find loop with graph

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(1)$$

## Code 

{% tabs %}
{% tab title="Cyclic" %}


```java
class Solution {
    public int findDuplicate(int[] nums) {

        for(int i=0; i<nums.length; i++) {
            while(i != nums[i] - 1)  {
                if (nums[i] == nums[nums[i] - 1]) {
                    return nums[i];
                }
                swap(nums, i, nums[i] - 1);
            }   
        }
        
        return -1;
    }
    
    public void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```
{% endtab %}

{% tab title="Graph" %}


```java
// Thinks as a graph

/*
[2,5,9,6,9,3,8,9,7,1]

0 -> 1
1 -> 5
2 -> 9
3 -> 6
4 -> 9
5 -> 3
6 -> 8
7 -> 9
8 -> 7
9 -> 1

slow    fast
0       0 
1       5 
5       6 
3       7 
6       1 
8       3 
7       8 
9       9       

*/

// 

// slow : d + a*loop + x 
// fast : d + b*loop + x

// 2d + 2a*loop + 2x = d + b*loop + x
// d + x  = (b-2a)*loop

// 0 -> d / fast -> d + x

class Solution {
    public int findDuplicate(int[] nums) {
        int head = 0;
        int slow = nums[head], fast = nums[nums[head]];
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        while(head != fast) {
            head = nums[head];
            fast = nums[fast];
        }
        
        return head;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/find-the-duplicate-number/](https://leetcode.com/problems/find-the-duplicate-number/)

## Tag

`#cyclic-sort` `#Floyd's-loop-detection` `#cycle` `#duplicate` 

