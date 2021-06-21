# Basic Calculator

## Problem



 Given a string `s` representing a valid expression, implement a basic calculator to evaluate it, and return _the result of the evaluation_.

* `s` consists of digits, `'+'`, `'-'`, `'('`, `')'`, and `' '`.

## Example

```text
Input: s = "-(1+(-4+5+2)-3)+(6+8)"
Output: 13
```

.

.

.



## Idea

* store sum / sign

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(N)$$

## Code 



{% tabs %}
{% tab title="stack" %}
```java
// idea:
// 1. calculate sum when '+', '-', ')' appears (initialize num as 0)
// 2. change sign when '+', '-' appears
// 3. store current sum and sign when '(' appears
//    apply it when ')' appears

class Solution {
    public int calculate(String s) {
        Stack<Integer> sumStack = new Stack<>();
        Stack<Integer> signStack = new Stack<>();
        
        int sign = 1;
        signStack.push(sign);
        
        int sum = 0;
        sumStack.push(sum);
        
        int num = 0;
        for(char c: s.toCharArray()) {
            if (Character.isDigit(c)) {
                num = 10 * num + (int) (c - '0');
            }
            
            if (c == '(') {
                signStack.push(sign);
                sumStack.push(sum);
                
                sum = 0;
                sign = 1;
            }
            
            if (c == ')') {
                sum += sign * num;
                num = 0;
                
                sum *= signStack.pop();
                sum += sumStack.pop();
            }
            
            if (c == '+') {
                sum += sign * num;
                num = 0;
                sign = 1;
            }
            if (c == '-') {
                sum += sign * num;
                num = 0;
                sign = -1;
            }
        }
        
        return sum + sign * num;
        
    }
}

/*
-(1+(-10+5+8)-3)+(6+8)

c    sign    num    sum        signStack    sumStack
-    -1      0      0          [1]          []
(    1       0      0          [1 -1]       [0]
1    1       1      0          [1 -1]       [0]
+    1       0      1          [1 -1]       [0]
(    1       0      0          [1 -1 1]     [0 1]
-    -1      0      0          [1 -1 1]     [0 1]
1    -1      1      0          [1 -1 1]     [0 1]
0    -1      10     0          [1 -1 1]     [0 1]
+    1       0      -10        [1 -1 1]     [0 1]
5    1       5      0          [1 -1 1]     [0 1]
+    1       0      -5         [1 -1 1]     [0 1]
8    1       8      -5         [1 -1 1]     [0 1]
)    1       0      (3)+1      [1 -1]       [0]
-    -1      0      4          [1 -1]       [0]
3    1       3      4          [1 -1]       [0]
)    1       0      -(4-3)+0   [1]          []  
+    1       0      -1         [1]          []  
(    1       0      0          [1 1]        [-1]
6    1       6      0          [1 1]        [-1]
+    1       0      6          [1 1]        [-1]
8    1       8      6          [1 1]        [-1]
)    1       0      14-1       [1]          []


result :: 13
  

*/
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/basic-calculator/](https://leetcode.com/problems/basic-calculator/)

## Tag

`#calculator` `#stack`

