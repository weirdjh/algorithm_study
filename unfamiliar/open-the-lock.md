# Open the Lock

## Problem

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: `'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'`. The wheels can rotate freely and wrap around: for example we can turn `'9'` to be `'0'`, or `'0'` to be `'9'`. Each move consists of turning one wheel one slot.

The lock initially starts at `'0000'`, a string representing the state of the 4 wheels.

You are given a list of `deadends` dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a `target` representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

## Example

{% hint style="info" %}
`sample input`: 

```text
deadends = ["0201","0101","0102","1212","2002"],
target = "0202"
```

`sample output`: 

```text
6
("0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202")
```
{% endhint %}

.

.

.



## Idea

* weight가 constant인 경우에 shortest path를 찾는 문제라면?
* deadend는 이미 visit한 것과 같지 않을까?

## Complexity

* Time : $$O(8^{d/2})$$ 
* Space: $$O(8^{d/2})$$ 

## Code 

{% tabs %}
{% tab title="BFS" %}


```java
class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> visited = new HashSet<>(Arrays.asList(deadends));
        
        Queue<String> queue = new LinkedList<>();
        queue.offer("0000");
        
        int turn = -1;
        while(!queue.isEmpty()) {
            int size = queue.size();
            
            turn += 1;
            
            while(size-- > 0) {
                String current = queue.poll();
                
                if (current.equals(target)) {
                    return turn;
                }
                
                if (visited.contains(current)) {
                    continue;
                }
                
                visited.add(current);
                queue.addAll(findNextWheels(current));
            }
            
        }
        
        return -1;
    }
    
    public List<String> findNextWheels(String current) {
        List<String> nextWheels = new ArrayList<>();
        
        for(int i=0; i<4; i++) {
            String prefix = current.substring(0, i);
            String postfix = current.substring(i+1);
            char c = current.charAt(i);
            
            // plus one
            nextWheels.add(prefix + (c == '9' ? 0 : c -'0' + 1) + postfix);
            
            // minus one
            nextWheels.add(prefix + (c == '0' ? 9 : c - '0' -1) + postfix);
            
        }
        
        return nextWheels;
    }
}
```
{% endtab %}

{% tab title="Bidirectional-BFS" %}
* bidirectional BFS를 쓸 수 있는 condition!
  * start와 end가 명확히 한개
  * adjacency list가 항상 일정함\(?\)

```java
class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> visited = new HashSet<>(Arrays.asList(deadends));
        
        Set<String> beginSet = new HashSet<>();
        Set<String> endSet = new HashSet<>();
        
        beginSet.add("0000");
        endSet.add(target);
        
        int turn = -1;
        while(!beginSet.isEmpty() && !endSet.isEmpty()) {
            Set<String> tmp = new HashSet<>();
            
            turn += 1;
            
            for(String current: beginSet) {
                
                // Attention to this!
                if (endSet.contains(current)) {
                    return turn;
                }
                
                if (visited.contains(current)) {
                    continue;
                }
                
                visited.add(current);
                tmp.addAll(findNextWheels(current));            
            }
            
            // Change direction
            // begin -> end
            // end -> begin
            beginSet = endSet;
            endSet = tmp;
        }
        
        return -1;
    }
    
    public List<String> findNextWheels(String current) {
        List<String> nextWheels = new ArrayList<>();
        
        for(int i=0; i<4; i++) {
            String prefix = current.substring(0, i);
            String postfix = current.substring(i+1);
            char c = current.charAt(i);
            
            // plus one
            nextWheels.add(prefix + (c == '9' ? 0 : c -'0' + 1) + postfix);
            
            // minus one
            nextWheels.add(prefix + (c == '0' ? 9 : c - '0' -1) + postfix);
            
        }
        
        return nextWheels;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/open-the-lock/](https://leetcode.com/problems/open-the-lock/)

## Tag

`#bidirectional_bfs` `#bfs` `#find_shortest_path`

