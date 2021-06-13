# Wildcard Matching

## Problem



Given an input string \(`s`\) and a pattern \(`p`\), implement wildcard pattern matching with support for `'?'` and `'*'` where:

* `'?'` Matches any single character.
* `'*'` Matches any sequence of characters \(including the empty sequence\).

The matching should cover the **entire** input string \(not partial\).

## Example

```text
Input: s = "adceb", p = "*a*b"
Output: true

Explanation: The first '*' matches the empty sequence, 
while the second '*' matches the substring "dce".
```

.

.

.



## Idea

* Application of LCS

## Complexity

* Time : $$O(N*M)$$ 
* Space: $$O(N*M)$$

## Code 

```java
class Solution {
	public boolean isMatch(String s, String p) {
        
		boolean[][] dp = new boolean[s.length()+1][p.length()+1];
        
		for(int j=1; j<=p.length(); j++) {
			if (p.charAt(j-1) != '*') {
				break;
			}
			dp[0][j] = true;
		}
		dp[0][0] = true;
		
		for(int i=1; i<=s.length(); i++) {
			for(int j=1; j<=p.length(); j++) {
				if (p.charAt(j-1) == '*') {
					dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
				}
				else if(s.charAt(i-1) == p.charAt(j-1) || p.charAt(j-1) == '?') {
					dp[i][j] = dp[i-1][j-1];
				}
				else if (s.charAt(i-1) != p.charAt(j-1)) {
					dp[i][j] = false;
				}
			}
		}
        
		return dp[s.length()][p.length()];
	}
}


```

## Ref

* [https://leetcode.com/problems/wildcard-matching/](https://leetcode.com/problems/wildcard-matching/)

## Tag

`#dp` `#lcs`

