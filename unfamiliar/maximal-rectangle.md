# Maximal Rectangle

## Problem

 Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return _its area_.

## Example

{% hint style="info" %}
`sample input`: 

```text
matrix =
[1 0 1 0 0]
[1 0 1 1 1]
[1 1 1 1 1]
[1 0 0 1 0]
```

`sample output`: 

```text
6
```
{% endhint %}

.

.

.



## Idea

* 각 row별로 누적 height을 구한다면?

## Complexity

* Time : $$O(N^2)$$ 
* Space: $$O(N^2)$$ 

## Code 

{% tabs %}
{% tab title="Maximal Rectanlge" %}


```java
/*

1 0 1 0 0 1
1 0 1 1 1 1
1 1 1 1 1 1
1 0 0 1 0 0

*/

class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix==null || matrix.length==0 || matrix[0].length==0) {
            return 0;
        }
        
        // height의 width를 1 늘려주었음
        // ... 마지막 pop하기 편하도록...
        int[][] heights = new int[matrix.length][matrix[0].length + 1];
        
        // initialize heights
        for(int j=0; j<matrix[0].length; j++) {
            heights[0][j] = matrix[0][j] - '0';
        }
        
        for(int i=1; i<matrix.length; i++) {
            for(int j=0; j<matrix[i].length; j++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = heights[i-1][j] + 1;
                }
                else {
                    heights[i][j] = 0;
                }
            }
        }
        
        // get maximum area
        int max = 0;
        for(int i=0; i<heights.length; i++) {
            max = Math.max(max, getMaximumArea(heights[i]));
        }
        
        return max;
    }
    
    //   #
    //  ## #
    //  ## ##
    // #######
    public int getMaximumArea(int[] heights) {
        
        Stack<Integer> stack = new Stack<>();
        
        int max = 0;
        for(int i=0; i<heights.length; i++) {
            while(!stack.isEmpty() && heights[stack.peek()] > heights[i]) {
                int height = heights[stack.pop()];
                int width = !stack.isEmpty()? i-stack.peek()-1: i;
                
                max = Math.max(max, height * width);
            }
            stack.push(i);
        }
        
        return max;
    }
}
```
{% endtab %}

{% tab title="Largest Rectangle in Histogram" %}
* stack
* 왼쪽까지 거리 &lt;-&gt; 오른쪽까지 거리 : width!

```java
//   #
//  ## #
//  ## ##
// #######
public int largestRectangleArea(int[] heights) {
    Stack<Integer> stack = new Stack<>();
    
    int max = 0;
    
    // height.length까지 iterate -> 마지막 pop을 위한 trick
    for(int i=0; i<=heights.length; i++) {
        while(!stack.isEmpty() && (i == heights.length || heights[stack.peek()] > heights[i])) {
            int height = heights[stack.pop()];
            int width = (!stack.isEmpty()) ? i - stack.peek() -1 : i;
            
            max = Math.max(max, height * width);
        }
        stack.push(i);
    }
    
    return max;
}
```
{% endtab %}
{% endtabs %}

## Ref

{% embed url="https://leetcode.com/problems/maximal-rectangle/" %}

{% embed url="https://leetcode.com/problems/largest-rectangle-in-histogram/" %}







## Tag

`#stack` `#max_area`

