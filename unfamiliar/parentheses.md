# Parentheses

## Problem

* Check if parentheses is valid. \( `"(){}[]"` \).
* Find length of longest valid parentheses \(`"()"`\).
* Remove minimum number of Invalid parentheses to make it valid. \(`"()"`\).



## Code 

{% tabs %}
{% tab title="Check Valid" %}


```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        
        for(Character c: s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }
            
            else if (!stack.isEmpty() && ((stack.peek() == '(' && c == ')') || 
                                          (stack.peek() == '{' && c == '}') || 
                                          (stack.peek() == '[' && c == ']'))){
                stack.pop();
            }
            else {
                return false;
            }
        }
        
        return stack.isEmpty();
    }
}
```
{% endtab %}

{% tab title="Find\_Longest\_stack\_1" %}
* stack의 top에는 '\)'가 있다고 생각.
* 떠올리기 겁나 힘든 풀이...라고 생각함.

```java
class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        
        // Assume that last is ')'
        stack.push(-1);
        
        int maxSum = 0;
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '(') {
                stack.push(i);
            }
            else if (c == ')') {
                stack.pop();
                
                // '))' case
                if (stack.isEmpty()) {
                    stack.push(i);
                }
                
                // ')(()' case
                else {
                    int length = i - stack.peek();
                    
                    maxSum = Math.max(maxSum, length);
                }
            }
        }
        
        return maxSum;
    }
}
```
{% endtab %}

{% tab title="Find\_Longest\_stack\_2" %}
* matching 되지 못한 괄호를 stack에 남겨두고... 짬처리해주는 풀이
* 마지막 index주의

```java
class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        
        for(int i=0; i<s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            }
            else {
                if(!stack.isEmpty() && s.charAt(stack.peek()) == '(') {
                    stack.pop();
                }
                else {
                    stack.push(i);
                }
            }
        }
        
        if (stack.isEmpty()) {
            return s.length();
        }
        
        int max = 0;
        int rightIdx = s.length() - 1;
        while(!stack.isEmpty()) {
            int leftIdx = stack.pop();
            
            // (leftIdx + 1 ~ rightIdx) : valid
            int length = (rightIdx - leftIdx);
            
            max = Math.max(max, length);
            rightIdx = leftIdx - 1;
        }
        
        // (0 ~ rightIdx) : valid
        max = Math.max(max, rightIdx+1);
        
        return max;
    }
}
```
{% endtab %}

{% tab title="Find\_Longest\_DP" %}
* dp\[i\] = \(현재까지 가장 긴 valid parentheses\)

```java
class Solution {
    public int longestValidParentheses(String s) {
        int[] dp = new int[s.length()+1];
        
        int openCount = 0;
        int max = 0;
        for(int i=1; i<=s.length(); i++) {
            if (s.charAt(i-1) == '(') {
                openCount += 1;
            }
            else {
                if (openCount <= 0) {
                    continue;
                }
                dp[i] = dp[i-1] + 2;
                
                // 이전에 괄호 친구들을 체크해줄 수 있음.
                dp[i] += dp[i-dp[i]];
                
                max = Math.max(max, dp[i]);
                openCount -= 1;
            }
        }
        
        return max;
    }
}
```
{% endtab %}

{% tab title="Remove\_Invalid" %}
* 그냥 BFS \(왜?? valid parentheses까지의 shortest path 를 구하는 문제이므로\)

```java
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        
        List<String> ans = new ArrayList<>();
        
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        
        queue.offer(s);
        visited.add(s);
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            
            while(size-- > 0) {
                String current = queue.poll();
                
                if (isValid(current)) {
                    ans.add(current);
                }
                
                for(int i=0; i<current.length(); i++) {
                    if (current.charAt(i) != '(' && current.charAt(i) != ')') {
                        continue;
                    }
                    
                    String next = current.substring(0,i) + current.substring(i+1);
                    
                    if (visited.contains(next)) {
                        continue;
                    }
                    visited.add(next);
                    queue.offer(next);
                }
            }
            
            if (ans.size() > 0) {
                return ans;
            }
        }
        
        return ans;
        
    }
    
    public boolean isValid(String s) {
        int score = 0;
        
        for(char c: s.toCharArray()) {
            if (c == '(') {
                score += 1;
            }
            else if (c == ')') {
                if (score > 0) {
                    score -= 1;
                }
                else {
                    return false;
                }
            }
        }
        
        return score == 0;
    }
    
}
```
{% endtab %}
{% endtabs %}



## Ref

* [https://leetcode.com/problems/valid-parentheses/](https://leetcode.com/problems/valid-parentheses/)
* [https://leetcode.com/problems/longest-valid-parentheses/](https://leetcode.com/problems/longest-valid-parentheses/)
* [https://leetcode.com/problems/remove-invalid-parentheses/](https://leetcode.com/problems/remove-invalid-parentheses/)



## Tag

`#parentheses` `#stack` `#dp` `#bfs`

