# Multiply Strings

## Problem



Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.

**Note:** You must not use any built-in BigInteger library or convert the inputs to integer directly.

## Example

```text
Input: num1 = "123", num2 = "456"
Output: "56088"
```

.

.

.



## Idea

* Store result integer into array!

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(N)$$

## Code 

```java
class Solution {
    public String multiply(String num1, String num2) {
        
        int m = num1.length(), n = num2.length();
        
        int[] pos = new int[m + n];
        
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int idx = (m-1) + (n-1) - (i + j);
                
                int sum = pos[idx] + (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
             
                pos[idx] = sum % 10;
                pos[idx+1] += (sum / 10);
            }
        }
        
        int idx = m + n - 1;
        while(idx >= 0 && pos[idx] == 0) {
            idx -= 1;
        }
        
        StringBuilder sb = new StringBuilder();
        
        for(int i=idx; i>=0; i--) {
            sb.append(pos[i]);
        }
        
        // Attention!
        if (sb.length() == 0) {
            return "0";
        }
        
        return sb.toString();
    }
}
```

## Ref

* [https://leetcode.com/problems/multiply-strings/](https://leetcode.com/problems/multiply-strings/)

## Tag

`#add_number` `#math`

