# Longest String Chain

## Problem

Let's say `word1` is a predecessor of `word2` if and only if we can add exactly one letter anywhere in `word1` to make it equal to `word2`. For example, `"abc"` is a predecessor of `"abac"`.

A _word chain_ is a sequence of words `[word_1, word_2, ..., word_k]` with `k >= 1`, where `word_1` is a predecessor of `word_2`, `word_2` is a predecessor of `word_3`, and so on.

Return the longest possible length of a word chain with words chosen from the given list of `words`.

## Example

{% hint style="info" %}
`sample input`: 

```text
words = ["a","b","ba","bca","bda","bdca"]
```

`sample output`: 

```text
4 (case of "a","ba","bda","bdca")
```
{% endhint %}

.

.

.



## Idea

* `짧은 것` -&gt; `긴 것` 으로 만들려고 하면 쉽지않음 \(ex. "ba" -&gt; "bca"\)
* `긴 것` -&gt; `짧은 것` 순으로 확인한다면? 
* tip\) Map을 dp처럼 쓸 수가 있다?

## Complexity

* Time : O\(NlogN\)
* Space: O\(N\)

## Code 

{% tabs %}
{% tab title="Bottom up" %}


```java
//["xbc","pcxbcf","xb","cxbc","pcxbc"]

// O(nlogn)
//["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"]

class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (x,y) -> Integer.compare(-x.length(), -y.length()));
        
        // {str : max count}
        Map<String, Integer> dp = new HashMap<>();
        
        int longest = 0;
        
        for(String word: words) { 
            int max = 0;
            for(int i=0; i<word.length(); i++) {
                String newWord = word.substring(0,i) + word.substring(i+1);
                
                max = Math.max(max, dp.getOrDefault(newWord, 0) + 1);
            }
            longest = Math.max(longest, max);
        }
        
        return longest;
    }
}

```
{% endtab %}

{% tab title="Top down" %}


```java
//["xbc","pcxbcf","xb","cxbc","pcxbc"]

// O(nlogn)
//["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"]

// Hashmap

// delete one -> next -> hashmap?

// caching

class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (x,y) -> Integer.compare(x.length(), y.length()));
        
        Set<String> set = new HashSet<>();
        for(String word: words) {
            set.add(word);
        }
        
        // {str : max count}
        Map<String, Integer> cache = new HashMap<>();
        
        int max = 0;
        for(int i = words.length -1; i>=0; i--) { 
            max = Math.max(max, longestStrChain(words[i], set, cache));
        }
        
        return max;
    }
    
    public int longestStrChain(String word, Set<String> set, 
                               Map<String, Integer> cache) {
        
        if (cache.containsKey(word)) {
            return cache.get(word);
        }
        
        int max = 1;
        for(int i=0; i<word.length(); i++) {
            String newWord = word.substring(0,i) + word.substring(i+1, word.length());

            if (set.contains(newWord)) {
                max = Math.max(max, longestStrChain(newWord, set, cache)+1);
            }
        }
        
        cache.put(word, max);
        
        return max;        
    }
}

```
{% endtab %}
{% endtabs %}



## Ref

{% embed url="https://leetcode.com/problems/longest-string-chain/" %}



## Tag

`#dp` `#hashmap`

