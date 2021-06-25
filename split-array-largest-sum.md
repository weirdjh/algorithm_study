# Split Array Largest Sum

## Problem



Given an array `nums` which consists of non-negative integers and an integer `m`, you can split the array into `m` non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these `m` subarrays.

**Example 1:**

```text
Input: nums = [7,2,5,10,8], m = 2
Output: 18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
```





.

.

.



## Idea

* 어디까지 가능하니?

## Complexity

* Time: $$O(nlogn)$$
* Space: $$O(1)$$

## Code 

```java
class Solution {
    public int splitArray(int[] nums, int m) {
        int sum = 0, max = 0;
        
        for(int num: nums) {
            sum += num;
            max = Math.max(max, num);
        }
        
        int left = max, right = sum;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canSplit(nums, mid, m)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
    private boolean canSplit(int[] nums, int target, int m) {
        int count = 1;
      
        int sum = 0;        
        for(int num: nums) {
            sum += num;
            if (sum > target) {
                count += 1;
                sum = num;
                
                if (count > m) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
```

## Ref

* [https://leetcode.com/problems/split-array-largest-sum/](https://leetcode.com/problems/split-array-largest-sum/)

## Tag

`#binary-search`

