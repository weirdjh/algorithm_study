# Palindrome Partitioning II

## Problem



Given a string `s`, partition `s` such that every substring of the partition is a palindrome.

Return _the minimum cuts needed_ for a palindrome partitioning of `s`.

**Example 1:**

```text
Input: s = "aab"
Output: 1

Explanation: 
The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```





.

.

.



## Idea

* palindrome table + kadane

## Complexity

* Time: $$O(n^2)$$
* Space: $$O(n^2)$$

## Code 

```java
/*
ex. cacommo

if length == 1:
    dp[i][j] = (s[i] == s[j])
if length == 2
    dp[i][j] = dp[i][j-1] && (s[i] == s[j])
else :
    dp[i][j] = dp[i+1][j-1] & (s[i] == s[j])

  c a c o m m o
c T F T F F F F
a   T F F F F F
c     T F F F F
o       T F F T
m         T T F
m           T F
o             T

*/

class Solution {
    public int minCut(String s) {
       boolean[][] dp = new boolean[s.length()][s.length()]; 
        
        for(int length=1; length<=s.length(); length++) {
            for(int j=length-1; j<s.length(); j++) {
                int i = j - length + 1;
                
                if (length == 1) {
                    dp[i][j] = true;
                }
                else if (length == 2) {
                    dp[i][j] = dp[i][j-1] && (s.charAt(i) == s.charAt(j));
                }
                else {
                    dp[i][j] = dp[i+1][j-1] && (s.charAt(i) == s.charAt(j));
                }
            }
        }
        
        int[] mincut = new int[s.length()+1];

        for(int i=1; i<=s.length(); i++) {
            
            mincut[i] = mincut[i-1] + 1;
            for(int j=1; j<i; j++) {
                if (dp[j-1][i-1]) {
                    mincut[i] = Math.min(mincut[i], mincut[j-1] + 1);
                }
            }
        }
        
        return mincut[s.length()] - 1;
    }
}
```

## Ref

* [https://leetcode.com/problems/palindrome-partitioning-ii/](https://leetcode.com/problems/palindrome-partitioning-ii/)

## Tag

`#palindrorme`

