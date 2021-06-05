# Candy

## Problem

There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:

* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.

Return _the minimum number of candies you need to have to distribute the candies to the children_.  

## Example

{% hint style="info" %}
`sample input`: 

```text
ratings = [1,0,2]
```

`sample output`: 

```text
5 (2, 1, 2 candies respectively)
```



`sample input`: 

```text
ratings = [1,2,2]
```

`sample output`: 

```text
4 (1, 2, 1 candies respectively)
```
{% endhint %}

.

.

.



## Idea

1. left -&gt; right / right -&gt; left 두 번 순회 ... 증가 / 감소 저장  `(Space: O(N))`
2. up / down / peak 정보를 저장 `(Space: O(1))`
   1. up의 경우 1, 2, 3... 순으로 가지만
   2. down의 경우도 1, 2, 3... 으로 output에 더해준다는 생각

## Complexity

* Time : O\(N\)
* Space: O\(1\)

## Code 

{% tabs %}
{% tab title="1st" %}


```java
// input:  1 2 3 3 2 5 2
// output: 1 2 3 2 1 2 1

// l->r : 1 2 3 1 1 2 1
// r->l : 1 1 1 2 1 2 1
// max  : 1 2 3 2 1 2 1

class Solution {
    public int candy(int[] ratings) {
        int[] toRight = new int[ratings.length];
        Arrays.fill(toRight, 1);
        
        int[] toLeft = new int[ratings.length];
        Arrays.fill(toLeft, 1);
        
        for(int i=1; i<ratings.length; i++) {
            if (ratings[i-1] < ratings[i]) {
                toRight[i] = toRight[i-1] + 1;
            }
        }
        
        for(int i=ratings.length-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                toLeft[i] = toLeft[i+1] + 1;
            }
        }
        
        int minCandies = 0;
        for(int i=0; i<ratings.length; i++) {
            minCandies += Math.min(toRight[i], toLeft[i]);
        }
        
        return minCandies;
    }
}
```
{% endtab %}

{% tab title="2nd" %}
* 내려가는 동안은 peek 유지! 올라가기 시작하면 peek은 0부터 다.

```java
class Solution {
    public int candy(int[] ratings) {
        
        int up = 0;
        int down = 0;
        int peek = 0;
        
        int minCandies = 1;
        
        for(int i=1; i<ratings.length; i++) {
            if (ratings[i-1] < ratings[i]) {
                down = 0;
                up += 1;
                peek = up;    // little confused part!
                minCandies += (1 + up);        
            }
            else if (ratings[i-1] == ratings[i]) {
                up = down = peek = 0;
                minCandies += 1;
            }
            else {
                up = 0;
                down += 1;
                if (peek >= down) {
                    minCandies += (down); 
                }
                else {
                    minCandies += (1 + down);
                }
            }
        }
        
        return minCandies;
    }
}
```
{% endtab %}
{% endtabs %}



## Ref

{% embed url="https://leetcode.com/problems/longest-string-chain/" %}



{% embed url="https://www.geeksforgeeks.org/chocolate-distribution-problem-set-2/?ref=rp" %}



## Tag

`#left-right` `#increasing-decreasing` `#array`

