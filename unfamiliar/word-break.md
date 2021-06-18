# Word Break

## Problem

* Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

  ```text
  Input: s = "applepenapple", wordDict = ["apple","pen"]
  Output: true
  ```

* Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order**.

  ```text
  Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
  Output: ["cats and dog","cat sand dog"]
  ```

* Given an array of strings `words` \(**without duplicates**\), return _all the **concatenated words** in the given list of_ `words`.

  A **concatenated word** is defined as a string that is comprised entirely of at least two shorter words in the given array.

  ```text
  Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
  Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
  ```



## Code 

{% tabs %}
{% tab title="Word Break" %}
* dp를 통해 i까지 word가 true인지 아닌지 저장할 수 있음.
* 혹은 hashmap통해서 memoization가능.

```java
// dp[i] = (true or not) until i

//         a p p l e p e
// dp = [t f f f f f f f]
//       t         t
//           

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        
        boolean[] dp = new boolean[s.length()+1];
        dp[0] = true;
        
        for(int i=1; i<=s.length(); i++) {
            for(int j=i-1; j>=0; j--) {
                if (dp[j] && wordSet.contains(s.substring(j,i))) {
                    dp[i] = true;
                    continue;
                }
            }
        }
        
        return dp[s.length()];
    }
}

// Memoization
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Map<Integer, Boolean> memo = new HashMap<>();
        
        return wordBreak(s, 0, wordDict, memo);
    }
    
    public boolean wordBreak(String s, int idx, List<String> wordDict, Map<Integer, Boolean> memo) {
        if (s.length() == idx) {
            memo.put(idx, true);
            return true;
        }
        
        if (memo.containsKey(idx)) {
            return memo.get(idx);
        }
        
        boolean ans = false;
        for(String word: wordDict) {
            if (s.startsWith(word, idx)) {
                if (wordBreak(s, idx + word.length(), wordDict, memo)) {
                    ans = true;
                    break;
                }
            }
        }
        
        memo.put(idx, ans);
        
        return ans;
    }
}
```
{% endtab %}

{% tab title="Word Break 2" %}
* Hashmap 통해서 i 까지 만들 수 있는 word 저장.

```java
// map
// catsanddog -> [cat, cats, and, sand, dog]

// 0,1: null
// 2: [cat]
// 3: [cats]
// 4: null
// 5: null
// 6: ["cat sand", "cats and"]
// 7: null
// 8: null
// 9: ["cat sand dog", "cats and dog"]
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        // idx+1, list
        Map<Integer, List<String>> map = new HashMap<>();
        
        List<String> initList = new ArrayList<>();
        initList.add("");
        
        map.put(0, initList);
        
        Set<String> wordSet = new HashSet<>(wordDict);
        
        for(int i=1; i<=s.length(); i++) {
            for(int j=0; j<i; j++){
                if (map.containsKey(j) && wordSet.contains(s.substring(j,i))) {
                    for(String stored: map.get(j)) {
                        if (stored.length() == 0) {
                            map.computeIfAbsent(i, x -> new ArrayList<>()).add(s.substring(j,i));    
                        }
                        else {
                            map.computeIfAbsent(i, x -> new ArrayList<>()).add(stored + ' ' + s.substring(j,i));
                        }
                    }
                }
            }
        }
        
        return map.getOrDefault(s.length(), Collections.emptyList());
    }
}
```
{% endtab %}

{% tab title="Concatenated Word" %}
* prefix / suffix가 wordSet에서 찾을 수 있는지 ? -&gt; 자연스레 2개 이상의 단어 조합이 됨.
* HashMap을 통해 이전 연산의 결과를 저장.

```java
class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        
        Set<String> wordSet = new HashSet<>(Arrays.asList(words));
        Map<String, Boolean> memo = new HashMap<>();
        
        List<String> ans = new ArrayList<>();
        
        for(String word: words) {
            if (dfs(word, wordSet, memo)) {
                ans.add(word);
            }
        }
        
        return ans;
    }
    
    public boolean dfs(String target, Set<String> wordSet, Map<String, Boolean> memo) {
        
        if (memo.containsKey(target)) {
            return memo.get(target);
        }
        
        for(int i=1; i<target.length(); i++) {
            
            String targetPrefix = target.substring(0, i);
            
            if (!wordSet.contains(targetPrefix)) {
                continue;
            }
            
            String targetSuffix = target.substring(i);
            if (wordSet.contains(targetSuffix) || dfs(targetSuffix, wordSet, memo)) {
                memo.put(target, true);
                
                return true;
            }
        }
        
        memo.put(target, false);
                
        return false;
    }
}
```
{% endtab %}
{% endtabs %}



## Ref

* [https://leetcode.com/problems/word-break/](https://leetcode.com/problems/word-break/)
* [https://leetcode.com/problems/word-break-ii/](https://leetcode.com/problems/word-break-ii/)
* [https://leetcode.com/problems/concatenated-words/](https://leetcode.com/problems/concatenated-words/)



## Tag

`#word break` `#dfs` `#hashmap` `#dp` `#prefix-suffix`

