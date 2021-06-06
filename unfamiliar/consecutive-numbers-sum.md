# Consecutive Numbers Sum

## Problem

Given a positive integer `n`, how many ways can we write it as a sum of consecutive positive integers?

## Example

{% hint style="info" %}
`sample input`: n = 5

`sample output`: 2 ... \(5, 2+3\)
{% endhint %}



.

.

.



## Idea

1. 누적합과 two pointer를 이용해서 풀었었음 ... TLE
   1. 이 방법은 HashMap을 통한 누적합 prefix저장을 이용할 수도 있음.
2. n개 숫자의 합이 $$n*a + sum(0..n)$$ 임 을 이용하여 풀 수 있음.

## Complexity

* Time : $$O(N)$$
* Space: $$O(1)$$

## Code 

* 
{% tabs %}
{% tab title="Optimal" %}


```java
// N
// K                    = 1K
// K + (K+1)            = 2K + 1
// K + (K+1) + (K+2)    = 3K + (1+2)
// K + ... +(K+a)       = aK + (1+2+..+a)
class Solution {
    public int consecutiveNumbersSum(int n) {
        
        int count = 0;
        
        // 9 
        // i=1: 9%1 == 0
        // i=2: (9-1) % 2 == 0
        // i=3: (9-3) % 3 == 0
        // i=4: (9-6) % 4 
        // i=5: (9-10) % 4
        int b = 0;
        for(int i=1; i<=n; i++){
            b += i;
            
            if (n < b) {
                break;
            }
            
            if ((n-b) % i == 0) {
                count += 1;
            }
        }
        
        return count;
    }
}
```
{% endtab %}

{% tab title="two pointer" %}


```java
// 15
//   1 2 3 4 5 6 7 8 + (15)
// 0 1 3 6 10 15 21 28 36
// s e
// s           e     
//   s           e
//       s       e
//         s        e
//                s e
class Solution {
    public int consecutiveNumbersSum(int n) {
        int[] acc = new int[n+1];
        for(int i=1; i<n; i++) {
            acc[i] = acc[i-1] + i;
        }
        
        int m = n / 2 + 1;
        
        int count = 0;
        
        int s = 0;
        int e = 1;
        while(e <= m) {
            if (acc[e] - acc[s] > n) {
                s += 1;
            }
            else if (acc[e] - acc[s] < n) {
                e += 1;
            }
            else {
                s += 1;
                e += 1;
                count += 1;
            }
        }
        
        return count + 1;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/consecutive-numbers-sum/](https://leetcode.com/problems/consecutive-numbers-sum/)



## Tag

`#Math` `#two-pointer` `#accumulate` 

