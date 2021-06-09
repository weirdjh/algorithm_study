# Number of Digit One

## Problem

Given an integer `n`, count _the total number of digit_ `1` _appearing in all non-negative integers less than or equal to_ `n`.  


## Example

{% hint style="info" %}
```
Input: n = 13
Output: 6
```
{% endhint %}



.

.

.



## Idea

* 수학 문제.
* 일의 자리,십의 자리,백의 자리...
* 문제가 어려운 건 아냐...하지만 코딩이 엄청나게 헷갈려...극복 방안 필요함.

## Code 

```java
// 1410065408
// 10000000 ~ 19999999 : 10000000 * (  + 1)
//  1000000 ~  1999999 :  1000000 * (2 + 1)
//   100000 ~   199999 :   100000 * (23 + 1)
//    10000 ~    19999 :    10000 * (235 + 0)
// ...
//      100 ~      199 :      100 * (23503) + (123+1)
//       10 ~       19 :       10 * (235034 + 1)
//        1 ~          :        1 * (2350342 + 1)



class Solution {
    public int countDigitOne(int n) {
        long tenSquare = 1;
        
        int count = 0;
        while(n / tenSquare != 0) {
            long currentNumber = n % (tenSquare * 10);
                        
            // 큰 자릿 수
            count += (tenSquare * (n / (tenSquare * 10))); 
            
            // 자신 포함 자릿 수
            if (currentNumber / tenSquare > 1) {
                count += tenSquare;
            }
            
            if (currentNumber / tenSquare == 1) {
                count += ((currentNumber % tenSquare) + 1);
            }
            
            tenSquare = tenSquare * 10;
        }
        
        return count;
    }
}
```

## Ref

* [https://leetcode.com/problems/number-of-digit-one/](https://leetcode.com/problems/number-of-digit-one/)





## Tag

`#math` `#count` 

