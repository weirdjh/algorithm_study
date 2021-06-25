# Subarrays with K Different Integers

## Problem

Given an array `nums` of positive integers, call a \(contiguous, not necessarily distinct\) subarray of `nums` _good_ if the number of different integers in that subarray is exactly `k`.

\(For example, `[1,2,3,1,2]` has `3` different integers: `1`, `2`, and `3`.\)

Return the number of good subarrays of `nums`.

**Example 1:**

```text
Input: nums = [1,2,1,2,3], k = 2
Output: 7

Explanation: 
Subarrays formed with exactly 2 different integers: 
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
```





.

.

.



## Idea

* 두 개의 atmost를 이용하여 풀 수 있음

## Complexity

* Time: $$O(n)$$
* Space: $$O(1)$$

## Code 

```java
class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        
        return subarraysAtmost(nums, k) - subarraysAtmost(nums, k-1);
    }
    
    public int subarraysAtmost(int[] nums, int k) {
        int start = 0;
        
        Map<Integer, Integer> map = new HashMap<>();
        
        int res = 0;
        
        for(int end=0; end<nums.length; end++) {
            map.put(nums[end], map.getOrDefault(nums[end], 0) + 1);
            
            while(map.size() > k) {
                map.put(nums[start], map.get(nums[start]) - 1);

                if (map.get(nums[start]) == 0) {
                    map.remove(nums[start]);
                }
                
                start += 1;
            }
            
            res += (end - start);
        }
        
        return res;
    }
}

// Atmost K

// nums = [4 1 1 2 3], K = 2
// num    start    end    map          res    misc
// 4      0        0      {4:1}        1      {4}
// 1      0        1      {4:1, 1:1}   2      + {4,1}, {1}
// 1      0        2      {4:1, 1:2}   3      + {4,1,1}, {1,1}, {1}
// 2      1        3      {1:2, 2:1}   3      + {1,1,2}, {1,2}, {2}
// 3      3        4      {2:1, 3:1}   2      + {2,3}, {3}
```

## Ref

* [https://leetcode.com/problems/beautiful-arrangement/](https://leetcode.com/problems/subarrays-with-k-different-integers/)

## Tag

`#sliding-window` `#atmost`

