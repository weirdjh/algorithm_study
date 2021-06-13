# Edit Distance

## Problem



Given two strings `word1` and `word2`, return _the minimum number of operations required to convert `word1` to `word2`_.

You have the following three operations permitted on a word:

* Insert a character
* Delete a character
* Replace a character

## Example

```text
Input: word1 = "intention", word2 = "execution"
Output: 5

Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
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
    public int minDistance(String word1, String word2) {
        int n = word2.length(), m = word1.length();
        
        int[][] dp = new int[n+1][m+1];

        for(int i=0; i<=n; i++) {
            dp[i][0] = i;
        }
        for(int j=0; j<=m; j++) {
            dp[0][j] = j;
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if (word2.charAt(i-1) == word1.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1])) + 1;
                }

            }
        }

        return dp[n][m];

    }
}

/*
Use f[i][j] to represent the shortest edit distance between word1[0,i) and word2[0, j). 
Then compare the last character of word1[0,i) and word2[0,j), 
which are c and d respectively (c == word1[i-1], d == word2[j-1]):

if c == d, then : f[i][j] = f[i-1][j-1]

Otherwise we can use three operations to convert word1 to word2:

(a) if we replaced c with d: f[i][j] = f[i-1][j-1] + 1;

(b) if we added d after c: f[i][j] = f[i][j-1] + 1;

(c) if we deleted c: f[i][j] = f[i-1][j] + 1;
*/
```

## Ref

* [https://leetcode.com/problems/edit-distance/](https://leetcode.com/problems/edit-distance/)

## Tag

`#dp` `#lcs`

