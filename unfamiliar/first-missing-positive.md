# First Missing Positive

## Problem

Given an unsorted integer array `nums`, find the smallest missing positive integer.



## Example

{% hint style="info" %}
```
Input: nums = [7,-1,8,3,9,11,1,12]
Output: 2
```
{% endhint %}



.

.

.



## Idea

* N 보다 같거나 큰 수가 나왔다는 것?
* 0보다 같거나 작은 수가 나왔다는 것?
* 1..N-1까지 한 번 씩  나왔다면 ?: N
* 안나왔다면?두둥!

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(1)$$ .... use existing array

## Code 

```java
// 4 8 7 1 5 2 3 -> 6

class Solution {
    public int firstMissingPositive(int[] nums) {
        
        int n = nums.length;
        
        int sum = 0;
        for(int i=0; i<nums.length; i++) {
            if (nums[i] > 0) {
                sum += nums[i];
            }
            // eliminate unrelated cases
            if (nums[i] <= 0 || nums[i] >= n) {
                nums[i] = 0;
            }
        }
        
        // Use nums as a Hash!
        // every element is in range[0, n)
        for(int i=0; i<nums.length; i++) {
            nums[nums[i] % n] += n;
        }
        
        // We can find out if empty elemnent is exists in range[0,n)
        for(int i=1; i<nums.length; i++) {
            if (nums[i] / n == 0) {
                return i;
            }
        }
        
        // We need to find if eveny element is exists in range[0,n)

        // Consider such two cases which makes hash full!
        // [0 1 2 ... n-1]
        // [1 2 3 .. n]
        if (sum == n * (n+1) / 2) {
            return n + 1;
        }
        
        return n;
    }
}
```

## Ref

* [https://leetcode.com/problems/first-missing-positive/](https://leetcode.com/problems/first-missing-positive/)
* 




## Tag

`#missing-number` `#hash` `#swap` 

