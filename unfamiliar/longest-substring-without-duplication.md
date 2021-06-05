# Longest Substring without Duplication

## Problem

Given string, find its longest substring without duplicate characters.

## Example

{% hint style="info" %}
`sample input`:   
string = "a**merican**eagle"

`sample output`:   
"merican"
{% endhint %}

.

.

.



## Idea

* 기본적으로 two pointer \(start + end\)
* Hashmap을 사용
  *  `{alphabet : index}`
  * 특정 alphabet첫 방문 
    * put
  * 특정 alphabet 다시 방문
    * max update \(및 start, end pointer의 index저장\)
    * put

## Complexity

* Time : O\(N\)
* Space: O\(N\) ... string에 사용된 alphabet 이 적을수록 줄어듬 

## Code 

```java
import java.util.*;

class Program {
  public static String longestSubstringWithoutDuplication(String str) {
    Map<Character, Integer> lastSeen = new HashMap<Character, Integer>();
		int[] longest = {0, 1};
		int startIdx = 0;
		
		for(int i=0; i<str.length(); i++) {
			char c = str.charAt(i);
			if(lastSeen.containsKey(c)) {
				startIdx = Math.max(startIdx, lastSeen.get(c) + 1);
			}
			if (longest[1] - longest[0] < i + 1 - startIdx) {
				longest = new int[] {startIdx, i+1};
			}
			lastSeen.put(c, i);
		}
		
		return str.substring(longest[0], longest[1]);
  }
}

```



## Ref

-

## Tag

`#two-pointer` `#hashmap`

