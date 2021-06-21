# Wiggle Subsequence

## Problem

A **wiggle sequence** is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference \(if one exists\) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

* For example, `[1, 7, 4, 9, 2, 5]` is a **wiggle sequence** because the differences `(6, -3, 5, -7, 3)` alternate between positive and negative.
* In contrast, `[1, 4, 7, 2, 5]` and `[1, 7, 4, 5, 5]` are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.

A **subsequence** is obtained by deleting some elements \(possibly zero\) from the original sequence, leaving the remaining elements in their original order.

Given an integer array `nums`, return _the length of the longest **wiggle subsequence** of_ `nums`.

## Example

```text
Input: nums = [1,7,4,9,2,5]
Output: 6

Explanation: 
The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
```

.

.

.



## Idea

* how can I store longest thing?

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(1)$$

## Code 

{% tabs %}
{% tab title="dp" %}
* cyclic sort \(LIS\)

```java
// [1,17,5,10,13,15,10,5,16,8]

// dp = 1 17 10 13 15 16
//        5        10 8
//                 5
// dp =[1 2 1 1 3 2]
class Solution {
    public int wiggleMaxLength(int[] nums) {
        int[] dp = new int[nums.length];
        
        int idx = 0;
        
        dp[0] = 1;
        for(int i=1; i<nums.length; i++) {
            if (nums[i-1] < nums[i]) {
                dp[++idx] = 1;
            }
            else if (nums[i-1] == nums[i]) {
                continue;
            }
            else {
                dp[idx] += 1;
            }
        }
        
        int sum = 0;
        for(int i=0; i<=idx; i++) {
            if (i == 0 || i == idx) {
                if (dp[i] == 1) {
                    sum += 1;
                }
            }
            if (dp[i] >= 2) {
                sum += 2;
            }
        }
        
        return sum;
    }
}
```
{% endtab %}

{% tab title="awesome..." %}


```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        
        int up = 1, down = 1;
        for(int i=0; i<nums.length-1; i++) {
            if (nums[i] > nums[i+1]) {
                down = up + 1;
            }
            if (nums[i] < nums[i+1]) {
                up = down + 1;
            }
        }
        
        return Math.max(down, up);            
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/wiggle-subsequence/](https://leetcode.com/problems/wiggle-subsequence/)

## Tag

`#LIS` `#dp`

