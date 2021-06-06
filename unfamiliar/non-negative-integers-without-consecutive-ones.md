# Non-negative Integers without Consecutive Ones

## Problem

 Given a positive integer `n`, return the number of the integers in the range `[0, n]` whose binary representations **do not** contain consecutive ones.

## Example

{% hint style="info" %}
`sample input`: 5

`sample output`: 5 \( 0, 1, 10, 100, 101 ... exclude 11\)
{% endhint %}



.

.

.



## Idea

1. 10111011 -&gt; 범위를 나눠보자!
2. length가 k인 이진수에서 찾을 수 있는 number of non-consecutive-1 의 개수는?

## Complexity

* Time : O\($$N$$\)
* Space: O\($$N$$\)

## Code 

```java
// x <= 110011

// 000000 ~ 011111 : dp[5]

// 100000 ~ 101111 : dp[4]

// 110000 ~ 110001 : dp[1]

// 110010 : dp[0]

// x <= 101
// 000 ~ 011 : dp[2] -> 000, 010, 001
// 101 : dp[0] -> 100

//  + 101


class Solution {
    public int findIntegers(int n) {
        
        String b = getBinary(n);
        
        int[] dp = new int[b.length()+1];
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<b.length(); i++) {
            dp[i] = dp[i-1] + dp[i-2];   
        }
        
        int ret = 0;
        boolean prebit = false;
        for(int i=0; i<b.length(); i++) {
            if (b.charAt(i) == '1') {
                ret += dp[b.length()- i - 1];
                
                // 11 이 되면 -> 다음으로 진행 불가
                // ex) 111010
                // 1. 000000 ~ 011111
                // 2. '1'00000 ~ '1'01111 ... '1' is fixed
                // 3. '11' is fixed ...!!
                if (prebit) {
                    return ret;
                }
                prebit = true;
            }
            else {
                prebit = false;
            }
        }
        
        // Plus one for itself!
        return ret + 1;
    }
    
    public String getBinary(int n) {
        String b = "";
        while(n != 0) {
            b = Integer.toString(n % 2) + b;
            n /= 2;
        }
        return b;
    }
}
```

## Ref

* [https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)

## Tag

`#dp` `#binary` 

