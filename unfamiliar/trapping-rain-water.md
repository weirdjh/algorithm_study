# Trapping Rain Water

## Problem

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

## Example



![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```text
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```



.

.

.



## Idea

* left -&gt; right / right -&gt; left
* largest rectangle in histogram
* two pointer



## Complexity

* Time : $$O(N)$$
* Space: $$O(1)$$

## Code 

{% tabs %}
{% tab title="L -> R / R -> L" %}
* Time : $$O(N)$$
* Space: $$O(N)$$

```java
//          [0 1 0 2 1 0 1 3 2 1 2 1]

// toRight: [0 1 1 2 2 2 2 3 3 3 3 3]
// toLeft : [3 3 3 3 3 3 3 3 2 2 2 1]

// min    : [0 1 1 2 2 2 2 3 2 2 2 1]

class Solution {
    public int trap(int[] height) {
        if (height.length == 0) {
            return 0;
        }
        
        int[] toRight = new int[height.length];
        int[] toLeft = new int[height.length];
        
        toRight[0] = height[0];
        toLeft[height.length-1] = height[height.length-1];
        
        for(int i=1; i<height.length; i++) {
            toRight[i] = Math.max(toRight[i-1], height[i]);
            
            int j = height.length - i - 1;
            toLeft[j] = Math.max(toLeft[j+1], height[j]);
        }
        
        int sum = 0;
        for(int i=0; i<height.length; i++) {
            sum += Math.min(toRight[i], toLeft[i]) - height[i];
        }
        
        return sum;
    }
}
```
{% endtab %}

{% tab title="LRIH" %}
* stack의 peek\(\)보다 커지면? 물이 가둬지는 상태임.
* stack의 이전 막대의 높이 \(없으면 물을 못가두니 패스\) 와 현재 막대의 높이의 min값이 가두는 기준이 되는 높이임
* Time : $$O(N)$$
* Space: $$O(N)$$

```java
// 4 2 0 3 2 5
// stack: 4
//        4 2
//        4 2 0
//                  (2-0) * (3-2) = 2
//        4 2
//                  (4-2) * (3-1) = 4
//        4 3 2
//                  (3-2) * (5-4) = 1
//        4 3
//                  (4-3) * (5-1) = 4
//        4
//                  0

class Solution {
    public int trap(int[] height) {
        Stack<Integer> stack = new Stack<>();
        
        int sum = 0;
        for(int i=0; i<height.length; i++) {
            while(!stack.isEmpty() && height[stack.peek()] < height[i]) {
                int currentHeight = height[stack.pop()];
                if (stack.isEmpty()) {
                    break;
                }
                
                int tallerHeight = Math.min(height[stack.peek()], height[i]);
                
                int left = stack.peek()+1;
                int right = i;
                
                sum += (tallerHeight - currentHeight) * (right - left);
            }
            
            stack.push(i);
        }
        
        return sum;
    }
}
```
{% endtab %}

{% tab title="Two Pointer" %}
* 이 문제에서는 끝판왕 풀이임
* leftMax &lt;= rightMax 라면? leftMax - height만큼 물이 반드시 가둬질 거라고 보장할 수 있음.
* Time : $$O(N)$$
* Space: $$O(N)$$

```java
/*
[4 2 0 3 2 5]

left    right   leftMax rightMax    sum
0       5       0       0           0
1       5       4       0           0
1       4       4       5           0
2       4       4       5           2
3       4       4       5           6
4       4       4       5           7      
5       4       4       5           9
*/
class Solution {
    public int trap(int[] height) {
        int left = 0, right = height.length-1;
        
        int leftMax=0, rightMax=0;
        
        int sum = 0;
        while(left <= right) {
            if (leftMax <= rightMax) {
                leftMax = Math.max(leftMax, height[left]);
                sum += (leftMax - height[left]);
                
                left += 1;
            }
            else {
                rightMax = Math.max(rightMax, height[right]);
                sum += (rightMax - height[right]);
                
                right -= 1;
            }
        }
        
        return sum;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/trapping-rain-water/](https://leetcode.com/problems/trapping-rain-water/)

## Tag

`#left-right` `#stack` `#two-pointer`

