# Permutation

## Problem

Permutation related Problem  


* Find all the possible permutations of `nums` when
  * elements of `nums` are distinct 
  * `nums` might have duplicate elements
  * sum of every pair of adjacent elements are perfect square

## 



.

.

.



## Idea

* 기본적으로 Backtracking

## Code 

{% tabs %}
{% tab title="Perm\_Distinct" %}
* Find all the possible permutations
* array `nums` of distinct integers

```java
// [1 2 3 4]

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        
        permute(nums, 0, ans);
        
        return ans;
    }
    
    public void permute(int[] nums, int idx, List<List<Integer>> ans) {
        if (idx == nums.length - 1) {
            ans.add(toList(nums));
            return;
        }    
        
        for(int i = idx; i < nums.length; i++) {
            swap(idx, i, nums);
            
            permute(nums, idx + 1, ans);
            
            swap(idx, i, nums);
        }
    }
    
    public void swap(int i, int j, int[] nums) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    public List<Integer> toList(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int value : nums) {
            result.add(value);
        }
        
        return result;
    }
}
```
{% endtab %}

{% tab title="Perm\_Duplicate" %}
* Find all the possible permutations
* array `nums` , that might contain duplicates

```java
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        
        permute(nums, 0, ans);
        
        return ans;
    }
    
    public void permute(int[] nums, int idx, List<List<Integer>> ans) {
        if (idx == nums.length - 1) {
            ans.add(toList(nums));
            return;
        }   
        
        
        Set<Integer> appeared = new HashSet<>();
        for(int i = idx; i < nums.length; i++) {
        
            // No duplicate elements are allowed
            if (!appeared.add(nums[i])) {
                continue;
            }
            
            swap(idx, i, nums);
            
            permute(nums, idx + 1, ans);
            
            swap(idx, i, nums);
        }
    }
    
    public void swap(int i, int j, int[] nums) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    public List<Integer> toList(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int value : nums) {
            result.add(value);
        }
        
        return result;
    }
}
```
{% endtab %}

{% tab title="Perm\_Squareful" %}
* 인접하는 두 원소의 합이 제곱 수인 경우만 찾아보자!
* 이미 swap을 마치고 fix 가 된 자릿수는 squareful한지 체크할 수 있음!

```java
class Solution {
    public int numSquarefulPerms(int[] A) {
        return numSquarefulPerms(A, 0);
    }
    
    public int numSquarefulPerms(int[] A, int i) {        
        if (i == A.length) {
            return 1;
        }
        
        int sum = 0;
        Set<Integer> seen = new HashSet<>();
        
        for(int j=i; j<A.length; j++) {
            if (!seen.add(A[j])) {
                continue;
            }
            
            swap(A, i, j);
                       
            if (i == 0 || (i >= 1 && checkSquare(A[i] + A[i-1]))) {
                sum += numSquarefulPerms(A, i+1);   
            }
            
            swap(A, i, j);
        }
        
        return sum;
    }
    
    public void swap(int[] A, int i, int j) {
        int tmp  = A[i];
        A[i]  = A[j];
        A[j] = tmp;
    }
    
    public boolean checkSquare(int target) {
        double root = Math.sqrt(target);
        
        return root == Math.floor(root);
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/permutations/](https://leetcode.com/problems/permutations/)
* [https://leetcode.com/problems/permutations-ii/](https://leetcode.com/problems/permutations-ii/)
* [https://leetcode.com/problems/number-of-squareful-arrays/](https://leetcode.com/problems/number-of-squareful-arrays/)



## Tag

`#permutation` `#duplicate` `#back-tracking`

