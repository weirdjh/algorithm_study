# Beautiful Arrangement

## Problem

Suppose you have `n` integers labeled `1` through `n`. A permutation of those `n` integers `perm` \(**1-indexed**\) is considered a **beautiful arrangement** if for every `i` \(`1 <= i <= n`\), **either** of the following is true:

* `perm[i]` is divisible by `i`.
* `i` is divisible by `perm[i]`.

Given an integer `n`, return _the **number** of the **beautiful arrangements** that you can construct_.





## Example

```text
Input: n = 2
Output: 2

Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
```

.

.

.



## Idea

* search all

## Complexity

* Time: $$O(n!)$$
* Space: $$O(n!)$$

## Code 

```java
// n = 3

// 1 2 3
// 1 3 2 (x)
// 2 1 3 
// 2 3 1 (x)

// 3 1 2 (x)
// 3 2 1 

// dp[n] = dp[n-1] + 

class Solution {
    public int countArrangement(int n) {
        int[] perm = new int[n];
        for(int i=0; i<n; i++) {
            perm[i] = i+1;
        }
        
        return countArrangement(perm, 0, n);
    }
    
    public int countArrangement(int[] perm, int idx, int n) {
        if (idx == n) {
            return 1;
        }
        
        int ans = 0;
        
        for(int i=idx; i<n; i++) {           
            if (perm[i] % (idx+1) != 0 && (idx+1) % (perm[i]) != 0) {
                continue;
            }
            
            swap(perm, idx, i);
            
            ans += countArrangement(perm, idx+1, n);
            
            swap(perm, idx, i);
        }
        
        return ans;
    }
    
    private void swap(int[] perm, int i, int j) {
        int tmp = perm[i];
        perm[i] = perm[j];
        perm[j] = tmp;
    }
}
```

## Ref

* [https://leetcode.com/problems/beautiful-arrangement/](https://leetcode.com/problems/beautiful-arrangement/)

## Tag

`#permutation`

