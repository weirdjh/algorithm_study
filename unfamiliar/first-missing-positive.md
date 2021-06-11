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

{% tabs %}
{% tab title="Hash" %}


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
{% endtab %}

{% tab title="Swap" %}
* Find right position of each number. -&gt; `1 x 3 4 5 x 7 8 x x`
* if all numbers are located in their place... return n + 1

```java
public class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
                
        return n + 1;
    }
    
    private void swap(int[] nums, int i, int j) {
        nums[i] ^= nums[j];
        nums[j] ^= nums[i];
        nums[i] ^= nums[j];
    }
}
/*
[7,-1,8,3,9,11,1,12], n = 8


// Find right position of 7 -> index of 6
i = 0    nums[0] = 7 / nums[0] - 1 = 6 : swap(0,6) [1,-1,8,3,9,11,7,12]
         nums[0] = 1 / nums[0] - 1 = 0 : same... pass
         
i = 1    nums[1] = -1 : pass
i = 2    nums[2] = 8  : pass
i = 3    nums[3] = 3  / nums[3] - 1 = 2 : swap(3,2) [1,-1,3,8,9,11,7,12]
         nums[3] = 8  : pass
         
i = 4    nums[4] = 9  : pass
i = 5    nums[5] = 11 : pass
i = 6    nums[6] = 7  / nums[6] - 1 = 6 : same... pass
i = 7    nums[7] = 12 : pass
*/
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/first-missing-positive/](https://leetcode.com/problems/first-missing-positive/)
* 




## Tag

`#missing-number` `#hash` `#swap` 

