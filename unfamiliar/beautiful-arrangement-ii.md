# Beautiful Arrangement II

## Problem

Given two integers `n` and `k`, construct a list `answer` that contains `n` different positive integers ranging from `1` to `n` and obeys the following requirement:

* Suppose this list is `answer = [a1, a2, a3, ... , an]`, then the list `[|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|]` has exactly `k` distinct integers.

Return _the list_ `answer`. If there multiple valid answers, return **any of them**.



## Example

```text
Input: n = 3, k = 1
Output: [1,2,3]

Explanation: 
The [1,2,3] has three different positive integers 
ranging from 1 to 3, and the [1,1] has exactly 1 distinct integer: 1
```

.

.

.



## Idea

* Make some example and find common logic

## Complexity

* Time: $$O(n)$$
* Space: $$O(1)$$

## Code 

{% tabs %}
{% tab title="reverse" %}
```java
// arr = [1 2 3 4 5 6] k = 1
// -> [1 2 3 4 5 6] -> (diff: 1)

// arr = [1 2 3 4 5 6] k = 2
// -> [1 6 5 4 3 2] -> (diff: 5 1)

// arr = [1 2 3 4 5 6] k = 3
// -> [1 6 2 3 4 5] -> (diff: 5 4 1)

// arr = [1 2 3 4 5 6] k = 4
// -> [1 6 2 5 4 3] -> (diff: 5 4 3 1)

class Solution {
    public int[] constructArray(int n, int k) {
        int[] nums = new int[n];
        for(int i=0; i<n; i++) {
            nums[i] = i+1;
        }
        
        int l = 1;
        for(int i=0; i<k-1; i++) {
            reverselist(nums, l++, n-1);
        }
        
        return nums;
    }
    
    private void reverselist(int[] nums, int i, int j) {
        while(i <= j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            
            i += 1;
            j -= 1;
        }
    }
}
```
{% endtab %}

{% tab title="pointer" %}
```

```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/beautiful-arrangement-ii/](https://leetcode.com/problems/beautiful-arrangement-ii/)

## Tag

`#array`

