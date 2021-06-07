# Search in Rotated Sorted Array

## Problem

There is an integer array `nums` sorted in ascending order \(with **distinct** values\).

Prior to being passed to your function, `nums` is **rotated** at an unknown pivot index `k`

 For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

 Given the array `nums` **after** the rotation and an integer `target`, return _the index of_ `target` _if it is in_ `nums`_, or_ `-1` _if it is not in_ `nums`.

## Example

{% hint style="info" %}
`sample input`: 

```
nums = [4,5,6,7,0,1,2], target = 0
```

```
sample output: 4
```
{% endhint %}



.

.

.



## Idea

* left sorted / right sorted 인 상황을 분리해서 생각해보자

## Code 

{% tabs %}
{% tab title="Find Index \(Distinct\)" %}
* element들은 모두 distinct
* target의 index를 찾는 문제.
  * input : `nums = [4,5,6,7,0,1,2], target = 0`
  * output : 4

```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Right side is sorted
            if (nums[mid] <= nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            
            // Left side is sorted
            else {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        
        return -1;
    }
}
```
{% endtab %}

{% tab title="Check if exists \(Duplicate\)" %}
* element들의 duplicate 허용.
* target이 존재하는지 판단하는 문제
  * input : `nums = [2,5,6,0,0,1,2], target = 0`
  * output : `true`

```java
class Solution {
    public boolean search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // Skip check
            // Duplicate && Not equals to target
            if((nums[left] == nums[right]) && (nums[left] != target)) {
                left += 1;
                right -= 1;
            }
            
            // Right side is definitely sorted
            else if (nums[mid] <= nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            
            // Left side is definitely sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        
        return false;
    }
}
```
{% endtab %}

{% tab title="Find Minimum \(Distinct\)" %}
* element들은 모두 distinct
* minimum 값을 찾는 문제
  * input : `nums = [4,5,6,7,0,1,2]`
  * output : 0

```java
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        
        int min = Integer.MAX_VALUE;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            // All Sorted
            if (nums[left] < nums[mid] && nums[mid] < nums[right]) {
                return Math.min(min, nums[left]);
            }
            
            // Right side is sorted
            else if (nums[mid] < nums[right]) {
                min = Math.min(min, nums[mid]);
                right = mid - 1;
            }
            
            // Left side is sorted
            else {
                min = Math.min(min, nums[left]);
                left = mid + 1;
            }
        }
        
        return min;
    }
}
```
{% endtab %}

{% tab title="Find Minimum \(Duplicate\)" %}
* element들의 duplicate 허
* minimum 값을 찾는 문제
  * input : `nums = [2,2,2,0,1]`
  * output : 0

```java
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        
        int min = Integer.MAX_VALUE;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
        
            // Duplicate!    
            if (nums[left] == nums[right]) {
                min = Math.min(min, nums[left]);
                left += 1;
                right -= 1;
            }
            
            // Right side is sorted
            else if (nums[left] <= nums[mid]) {
                min = Math.min(min, nums[left]);
                left = mid + 1;
            }
            
            // Left side is sorted
            else {
                min = Math.min(min, nums[mid]);
                right = mid - 1;
            }
        }
        
        return min;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/search-in-rotated-sorted-array/](https://leetcode.com/problems/search-in-rotated-sorted-array/)
* [https://leetcode.com/problems/search-in-rotated-sorted-array-ii/](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
* [https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
* [https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)





## Tag

`#binary_search` `#duplicate`

