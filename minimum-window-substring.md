# Minimum Window Substring

## Problem

Given two strings `s` and `t` of lengths `m` and `n` respectively, return _the **minimum window substring** of_ `s` _such that every character in_ `t` _\(**including duplicates**\) is included in the window. If there is no such substring, return the empty string_ `""`_._

The testcases will be generated such that the answer is **unique**.

A **substring** is a contiguous sequence of characters within the string.

**Example 1:**

```text
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Explanation: 
The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```





.

.

.



## Idea

* sliding window를 활용,
* 현재 window가 valid 한지 아닌지 여부를 count를 이용하여 확인

## Complexity

* Time: $$O(n+m)$$
* Space: $$O(m)$$

## Code 

```java
class Solution {
    public String minWindow(String s, String t) {
        Map<Character, Integer> countMap = new HashMap<>();
        
        int count = t.length();
        for(int i=0; i<t.length(); i++) {
            char c = t.charAt(i);
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }
        
        String ans = "";
        
        for(int start = 0, end=0; end<s.length(); end++) {
            char endC= s.charAt(end);
            
            if (!countMap.containsKey(endC)) {
                continue;
            }
            
            countMap.put(endC, countMap.get(endC) - 1);
            if (countMap.get(endC) >= 0) {
                count -= 1;
            }
            
            // valid case
            while (count == 0) {
                char startC = s.charAt(start);
                
                if (countMap.containsKey(startC)) {
                    if (ans.length() == 0 || ans.length() > (end - start + 1)) {
                        ans = s.substring(start, end + 1);
                    }
                    
                    countMap.put(startC, countMap.get(startC) + 1);
                    if (countMap.get(startC) > 0) {
                        count += 1;   
                    }
                }
                start += 1;
            }
        }
        
        return ans;
    }
}
```

## Ref

* [https://leetcode.com/problems/minimum-window-substring/](https://leetcode.com/problems/minimum-window-substring/)

## Tag

`#sliding-window`

