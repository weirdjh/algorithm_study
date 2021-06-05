# Maximum Height by Stacking Cuboids

## Problem

Given `n` `cuboids` where the dimensions of the `ith` cuboid is `cuboids[i] = [widthi, lengthi, heighti]` \(**0-indexed**\). Choose a **subset** of `cuboids` and place them on each other.

You can place cuboid `i` on cuboid `j` if `widthi <= widthj` and `lengthi <= lengthj` and `heighti <= heightj`. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return _the **maximum height** of the stacked_ `cuboids`.

## Example

{% hint style="info" %}
`sample input`: \[ \[50,45,20\], \[95,37,53\], \[45,23,12\]\]

`sample output`: 190
{% endhint %}



.

.

.



## Idea

1. sorting을 통해 항상 height이 제일 크게 만들어준다
2. sorting을 통해 cuboids들이 increasing 상태로 되도록 한다.
3. height기준으로 LIS를 함.

## Complexity

* Time : $$O(N^2)$$
* Space: $$O(N)$$

## Code 

* 왜 height을 max로 놓고 구하면 답이 될 수 있는지에 대한 간략한 증명
* [https://leetcode.com/problems/maximum-height-by-stacking-cuboids/discuss/970589/Proof%3A-why-only-consider-longest-edge-as-height](https://leetcode.com/problems/maximum-height-by-stacking-cuboids/discuss/970589/Proof%3A-why-only-consider-longest-edge-as-height)
* 왜 pure LIS에서 처럼 binary search를 쓰지 않음?
  * 3D -&gt; 1D로 바꿀 수가 없음. \(russian doll envelop 문에서 처럼...\)

```java
class Solution {
    public int maxHeight(int[][] cuboids) {
        for(int i=0; i<cuboids.length; i++) {
            Arrays.sort(cuboids[i]);
        }
        
        Arrays.sort(cuboids, new CuboidComparator());
        
        int[] dp = new int[cuboids.length];
        int max = 0;
        
        for(int i=0; i<cuboids.length; i++) {
            dp[i] = findBeforeMaxHeightSum(dp, cuboids, i) + cuboids[i][2];
            if (max < dp[i]) {
                max = dp[i];
            }
        }
        
        return max;
    }
    
    public int findBeforeMaxHeightSum(int[] dp, int[][] cuboids, int i) {
        
        int max = 0;
        for(int j=0; j<i; j++) {
            if (cuboids[j][0] <= cuboids[i][0] && 
                cuboids[j][1] <= cuboids[i][1] &&
                cuboids[j][2] <= cuboids[i][2]) {
                if(max < dp[j]) {
                    max = dp[j];
                }
            }        
        }
        
        return max;
    }
    
    
    class CuboidComparator implements Comparator<int[]> {
        public int compare(int[] c1, int[] c2) {
            if (c1[0] != c2[0]) {
                return c1[0] - c2[0];
            }
            
            if (c1[1] != c2[1]) {
                return c1[1] - c2[1];
            }
            
            return c1[2] - c2[2];
        }
    }
}
```

## Ref

{% embed url="https://leetcode.com/problems/maximum-height-by-stacking-cuboids/" %}





## Tag

`#dp` `#LIS` `#sorting` 

