# Word Search II

## Problem



 Given an `m x n` `board` of characters and a list of strings `words`, return _all words on the board_.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells** are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

## Example

![](../.gitbook/assets/image%20%2819%29.png)

```text
Output: ["eat","oath"]
```

.

.

.



## Idea

* find all!

## Complexity

* Time : $$O(M*N * 3^L)$$ where L is max length word
* Space: $$O(M * N)$$

## Code 



{% tabs %}
{% tab title="dfs + trie" %}
```java
class Solution {
    
    int[] dirX = new int[] {-1, 0, 1, 0};
    int[] dirY = new int[] {0, -1, 0, 1};
    
    public List<String> findWords(char[][] board, String[] words) {
        
        Trie trie = new Trie();
        
        for(String word: words) {
            trie.insert(word);
        }
        
        List<String> ans = new ArrayList<>();
        
        for(int i=0; i<board.length; i++) {
            for(int j=0; j<board[i].length; j++) {
                char c = board[i][j];
                if (trie.root.childs[c-'a'] == null) {
                    continue;
                }
                    
                board[i][j] = 'X';
                ans.addAll(dfs(board, j, i, trie.root.childs[c-'a']));
                board[i][j] = c;    
            }
        }
        
        return ans;
    }
    
    public List<String> dfs(char[][] board, int x, int y, TrieNode node) {
        List<String> ans = new ArrayList<>();
        
        if (node.word != null) {
            ans.add(node.word);
            node.word = null;
        }
        
        for(int i=0; i<4; i++) {
            int nextX = x + dirX[i];
            int nextY = y + dirY[i];
            
            if (nextX < 0 || nextX >= board[0].length || nextY < 0 || nextY >= board.length) {
                continue;
            }
            
            char c = board[nextY][nextX];
            
            if (c == 'X') {
                continue;
            }
            
            if (node.childs[c-'a'] == null) {
                continue;
            }
            
            board[nextY][nextX] = 'X';
            
            ans.addAll(dfs(board, nextX, nextY, node.childs[c-'a']));
            
            board[nextY][nextX] = c;
        }
        
        return ans;
    }
    
    class Trie {
        TrieNode root = new TrieNode();
        
        public void insert(String word) {
            TrieNode node = root;
            
            for(char c: word.toCharArray()) {
                if (node.childs[c-'a'] == null) {
                    node.childs[c-'a'] = new TrieNode();
                }
                node = node.childs[c-'a'];
            }
            node.word = word;
        }
    }
    
    class TrieNode {
        TrieNode[] childs = new TrieNode[26];
        String word = null;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/word-search-ii/](https://leetcode.com/problems/word-search-ii/)

## Tag

`#dfs` `#trie` `#find-all`

