# Pizza With 3n Slices

## Problem

There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

* You will pick **any** pizza slice.
* Your friend Alice will pick next slice in anti clockwise direction of your pick. 
* Your friend Bob will pick next slice in clockwise direction of your pick.
* Repeat until there are no more slices of pizzas.

Sizes of Pizza slices is represented by circular array `slices` in clockwise direction.

Return the maximum possible sum of slice sizes which you can have.

![](../.gitbook/assets/image%20%2813%29.png)

## Example

{% hint style="info" %}
`sample input`: 

```text
slices = [1,2,3,4,5,6]
```

`sample output`: 

```text
10
```
{% endhint %}



.

.

.



## Idea

1. circular array -&gt; 한 칸 씩 띄우면서 최댓값 구하기?
2. array에서 k개 element를 이용하여 max값 구하기?

## Complexity

* Time : O\($$N^2$$\)
* Space: O\($$N$$\)

## Code 

{% tabs %}
{% tab title="House Robber" %}
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return _the maximum amount of money you can rob tonight **without alerting the police**_.

* array에서 인접하지 않는 elements의 maxsum을 구하는 문
* 선택하거나 / 혹은 하지 않거나

```java
class Solution {
    // time: O(N), space: O(N)
    public int rob(int[] nums) {
        int[] dp = new int[nums.length+1];
        
        dp[1] = nums[0];
        for(int n=2; n<=nums.length; n++) {
            dp[n] = Math.max(dp[n-1], dp[n-2] + nums[n-1]);
        }
        
        return dp[nums.length];
    }

    // optimized!
    // time: O(N), space: O(1)
    public int rob(int[] nums) {
        int before = 0;
        int current = nums[0];
        
        for(int n=1; n<nums.length; n++) {
            int tmp = current;
            current = Math.max(current, before + nums[n]);
            before = tmp;
        }
        
        return current;
    }
}
```
{% endtab %}

{% tab title="House Robber 2" %}
* 기본적으로 `House Robber`와 같은 문제.
* 하지만 array가 circular임.
* idea : `0~N-1` `1~N` 두 가지 케이스에 대해 dp 계

```java
// time: O(N), space: O(N)
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        
        int[] toRight = new int[nums.length + 1];
        
        toRight[1] = nums[0];
        for(int i=2; i<nums.length; i++) {
            toRight[i] = Math.max(toRight[i-1], toRight[i-2] + nums[i-1]);
        }
        
        int[] toLeft = new int[nums.length + 1];
        
        toLeft[nums.length-1] = nums[nums.length-1];
        for(int i=2; i<nums.length; i++) {
            int n = nums.length - i;
            toLeft[n] = Math.max(toLeft[n+1], toLeft[n+2] + nums[n]);
        }
        
        return Math.max(toRight[nums.length-1], toLeft[1]);
    }
}

// time: O(N), space: O(1)
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        
        return Math.max(
            rob(nums, 0, nums.length - 1),
            rob(nums, 1, nums.length)
        );
    }
    
    public int rob(int[] nums, int start, int end) {
        int before = 0;
        int current = nums[start];
        
        for(int i=start+1; i<end; i++) {
            int tmp = current;
            current = Math.max(current, before + nums[i]);
            before = tmp;
        }
        
        return current;
    }
}
```
{% endtab %}

{% tab title="Pizza With 3n Slices" %}


```java
// time: O(N^2), space: O(N^2)
class Solution {
    public int maxSizeSlices(int[] slices) {
        if(slices.length == 3) {
            return Math.max(Math.max(slices[0],slices[1]), slices[2]);
        }
        
        return Math.max(
            maxSizeSlicesHelper(slices, 0, slices.length / 3),
            maxSizeSlicesHelper(slices, 1, slices.length / 3)
        );
    }
    
    public int maxSizeSlicesHelper(int[] slices, int start, int k) {
       
        int[][] dp = new int[slices.length][k + 1];
        
        dp[1][1] = slices[start];
        
        for(int i=2; i<slices.length; i++) {
            for(int j=1; j<=k; j++) {
                dp[i][j] = Math.max(dp[i-1][j], dp[i-2][j-1] + slices[start + i-1]);
            }
        }
        
        return dp[slices.length - 1][k];
        
    }
}
```
{% endtab %}

{% tab title="Find MaxSum of K elements" %}


```java
// time: O(N^2), space: O(N^2)
class Solution {
    public int maxSizeSlices(int[] array, int k) {
        int[][] dp = new int[array.length + 1][k + 1];
        
        dp[1][1] = array[0];
        
        for(int i=2; i<array.length; i++) {
            for(int j=1; j<=k; j++) {

                // choose or not!
                dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-1] + array[i-1]);
            }
        }
        
        return dp[slices.length - 1][k];
        
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

{% embed url="https://leetcode.com/problems/house-robber/" %}

{% embed url="https://leetcode.com/problems/house-robber-ii/" %}

{% embed url="https://leetcode.com/problems/pizza-with-3n-slices/" %}





## Tag

`#house-robber` `#dp` `#circular-array`    

