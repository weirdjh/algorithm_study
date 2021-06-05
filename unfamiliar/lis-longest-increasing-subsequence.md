# LIS \(Longest Increasing Subsequence\)

## Problem

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

## Example

{% hint style="info" %}
`sample input`: \[10, 9, 2, 5, 3, 7, 101, 18\]

`sample output`: 4 \(2, 3, 7, 18...\)
{% endhint %}



.

.

.



## Idea

1. dp사용 \(현재까지 가장 긴 LIS를 저장!\)

   $$dp[i] = max(dp[j]) + 1)$$  where \(a\[i\] &lt; a\[j\] && i &lt; j\)

2. binary search 사용 \([https://en.wikipedia.org/wiki/Patience\_sorting](https://en.wikipedia.org/wiki/Patience_sorting)\)

## Complexity

* Time : O\($$NlogN$$\)
* Space: O\($$N$$\)

## Code 

{% tabs %}
{% tab title="LIS" %}


```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] incr = new int[nums.length];
        int[] parent = new int[nums.length];
        Arrays.fill(parent, -1);
        
        int size = 0;
        for(int i=0; i<nums.length; i++) {
            int pos = binarySearch(nums, incr, size, nums[i]);
            if (pos > 0) {
                parent[i] =  incr[pos-1];
            }
            
            // update piles
            incr[pos] = i;
            
            if (pos >= size) {
                size += 1;
            }
        }
        
        // Get LIS array using parent pointer
        int current = incr[size-1];
        int[] lis = new int[size];
        for(int i=0; i<size; i++) {
            lis[i] = nums[current];
            current = parent[current];
        }
        
        /*
        for(int i=0; i<size; i++) {
            System.out.println(lis[i]);
        }
        */
        
        return size;
    }
    
    // Return Left Position for update piles!
    public int binarySearch(int[] nums, int[] incr, int size, int target) {
    
        // Attention to `size-1`
        int left = 0, right = size - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;

            if (nums[incr[mid]] < target) {
                left = mid + 1;    
            }
            else if (nums[incr[mid]] > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        
        return left;
    }
}
```
{% endtab %}

{% tab title="Russian Doll Envelopes" %}
You are given a 2D array of integers `envelopes` where `envelopes[i] = [wi, hi]` represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return _the maximum number of envelopes you can Russian doll \(i.e., put one inside the other\)_.

```java
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        
        // - Sorting the width reduces the problem by one dimension.
        // - Sorting height in descending order when there is a tie 
        //   prevents such a sequence to be included in the solution.
        Arrays.sort(envelopes, new EnvelopeComparator());
        
        int[] incr = new int[envelopes.length];
        
        int size = 0;
        for(int i=0; i<envelopes.length; i++) {
            int pos = binarySearch(envelopes, incr, size, envelopes[i][1]);
              
            incr[pos] = i;
            
            if (pos >= size) {
                size += 1;
            }
        }
        
        return size;
    }
    
    public int binarySearch(int[][] envelopes, int[] incr, int size, int target) {
        int left = 0, right = size - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;

            if (envelopes[incr[mid]][1] < target) {
                left = mid + 1;    
            }
            else if (envelopes[incr[mid]][1] > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        
        return left;
    }
    
    class EnvelopeComparator implements Comparator<int[]> {
        public int compare(int[] e1, int[] e2) {
            if (e1[0] == e2[0]) {
                return e2[1] - e1[1];
            }
            
            return e1[0] - e2[0];
        }
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

{% embed url="https://leetcode.com/problems/longest-increasing-subsequence/" %}

{% embed url="https://leetcode.com/problems/russian-doll-envelopes/" %}





## Tag

`#LIS` `#Russian Doll Envelope` 

