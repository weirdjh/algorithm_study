# Sliding Window \(Atmost\)

## Count Number of Nice Subarray

Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are `k` odd numbers on it.

Return _the number of **nice** sub-arrays_.

**Example 1:**

```text
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```



## Subarrays with K Different Integers



Given an array `nums` of positive integers, call a \(contiguous, not necessarily distinct\) subarray of `nums` _good_ if the number of different integers in that subarray is exactly `k`.

\(For example, `[1,2,3,1,2]` has `3` different integers: `1`, `2`, and `3`.\)

Return the number of good subarrays of `nums`.

**Example 1:**

```text
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
```

