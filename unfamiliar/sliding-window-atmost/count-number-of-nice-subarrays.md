# Count Number of Nice Subarrays

## Problem



Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are `k` odd numbers on it.

Return _the number of **nice** sub-arrays_.

**Example 1:**

```text
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
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
    public int numberOfSubarrays(int[] nums, int k) {
         
        return numberOfAtmost(nums, k) - numberOfAtmost(nums, k-1);
    }
    
    public int numberOfAtmost(int[] nums, int k) {
        
        int start = 0, end = 0;
        int odd = 0;
        
        int res = 0;
        
        while(end < nums.length) {
            if (nums[end++] % 2 == 1) {
                odd += 1;
            }
            
            while(odd > k) {
                if (nums[start++] % 2 == 1) {
                    odd -= 1;
                }
            }
            
            res += (end - start + 1);
        }
        
        return res;
    }
}

// Atmost K

// nums = [4 1 1 2 3], K = 2
// num    start    end    odd    res    misc
// 4      0        0      0      1      {4}
// 1      0        1      1      2      + {4,1}, {1}
// 1      0        2      2      3      + {4,1,1}, {1,1}, {1}
// 2      0        3      2      4      + {4,1,1,2}, {1,1,2}, {1,2}, {2}
// 3      2        4      3->2   3      + {1,2,3}, {2,3}, {3}
```

## Ref

* [https://leetcode.com/problems/count-number-of-nice-subarrays/](https://leetcode.com/problems/count-number-of-nice-subarrays/)

## Tag

`#sliding-window` `#atmost`

