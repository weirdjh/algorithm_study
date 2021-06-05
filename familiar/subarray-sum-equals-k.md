# Subarray Sum Equals K

## Problem

 Given an array of integers `nums` and an integer `k`, return _the total number of continuous subarrays whose sum equals to `k`_.

## Example

{% hint style="info" %}
`sample input`: 

```
nums = [1,2,3], k = 3
```

`sample output`: 2 ... \(\[1,2\] , \[3\]\)
{% endhint %}



.

.

.



## Idea

1. HashMap을 이용해서 presum을 저장해줌 \(two pointer는 사용 불가... 누적 합이 increasing임을 보장할 수 없기때문\)

## Complexity

* Time : $$O(N)$$
* Space: $$O(N)$$

## Code 

```java
// a+b+c+d
// c+d = k
// sum(a+b+c+d) - k

class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        
        int count = 0;
        
        int presum = 0;
        for(int num: nums) {
            presum += num;
            if (presum == k) {
                count += 1;   
            }
            if (map.containsKey(presum - k)) {
                count += map.get(presum - k);
            }
            map.put(presum, map.getOrDefault(presum, 0) + 1);
        }
        
        return count;
    }
}
```

## Ref

{% embed url="https://leetcode.com/problems/subarray-sum-equals-k/" %}





## Tag

`#hashmap`

