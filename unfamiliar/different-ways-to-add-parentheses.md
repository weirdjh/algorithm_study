# Different Ways to Add Parentheses

## Problem



 Given a string `expression` of numbers and operators, return _all possible results from computing all the different possible ways to group numbers and operators_. You may return the answer in **any order**.

## Example

```text
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]

Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
```

.

.

.



## Idea

* Store result integer into array!

## Complexity

* Time : $$O(2^N)$$ 
* Space: $$O(2^N)$$

## Code 

```java
class Solution {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> res = new ArrayList<Integer>();
        
        for(int i=0; i<expression.length(); i++) {
            char c = expression.charAt(i);
            
            if (c == '-' || c == '+' || c == '*') {
                String a = expression.substring(0, i);
                String b = expression.substring(i+1);
                
                List<Integer> lefts = diffWaysToCompute(a);
                List<Integer> rights = diffWaysToCompute(b);
                
                for(int left: lefts) {
                    for(int right: rights) {
                        if (c == '-') {
                            res.add(left - right);
                        }
                        else if (c == '+') {
                            res.add(left + right);
                        }
                        else if (c == '*') {
                            res.add(left * right);
                        }
                    }
                }
            }
        }
        
        if (res.size() == 0) {
            res.add(Integer.valueOf(expression));
        }
        
        return res;
    }
}
```

## Ref

* [https://leetcode.com/problems/different-ways-to-add-parentheses/](https://leetcode.com/problems/different-ways-to-add-parentheses/)

## Tag

`#calculator` `#divide-and-conquer`

