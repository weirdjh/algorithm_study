# Regular Expression Matching

## Problem



 Given an input string \(`s`\) and a pattern \(`p`\), implement regular expression matching with support for `'.'` and `'*'` where: ``

* `'.'` Matches any single character.​​​​
* `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire** input string \(not partial\).

## Example

```text
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. 
Therefore, it matches "aab".
```

.

.

.



## Idea

* find condition of `*`.

## Complexity

* Time : $$O(N^2)$$ 
* Space: $$O(N^2)$$

## Code 



{% tabs %}
{% tab title="stack" %}
```java
/*
   '' c * a . * b
'' T  F T F F F F 
a  F  F F T F T F
a  F  F F T T T F
b  F  F F F T T T
*/
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length()+1][p.length()+1];
        
        dp[0][0] = true;
        
    		for(int j=2; j<=p.length(); j++) {
                if (p.charAt(j-1) == '*') {
                    dp[0][j] = dp[0][j-2];
                }
    		}
    		
    		for(int i=1; i<=s.length(); i++) {
            for(int j=1; j<=p.length(); j++) {
    				    if (p.charAt(j-1) == '*') {
                    if(s.charAt(i-1) == p.charAt(j-2) || p.charAt(j-2) == '.')  {
                        dp[i][j] = (dp[i][j-1] || dp[i-1][j] || dp[i][j-2]);
                    }
                    else {
                        dp[i][j] = dp[i][j-2];
                    }                                    
        				}
    		    		else if(s.charAt(i-1) == p.charAt(j-1) || p.charAt(j-1) == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
    		}
            
    		return dp[s.length()][p.length()];
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/regular-expression-matching/](https://leetcode.com/problems/regular-expression-matching/)

## Tag

`#lcs` `#dp`

