# The Skyline Problem

## Problem

![](.gitbook/assets/image%20%2821%29.png)

**Example 1:**

```text
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]

Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. 
The red points in figure B represent the key points in the output list.
```





.

.

.



## Idea

* 어떻게 하면 가려진 빌딩을 무시하고 지나갈 수 있을까?

## Complexity

* Time: $$O(nlogn)$$\(PriorityQueue -&gt; n^2\)
* Space: $$O(n)$$

## Code 

```java
// buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]

// heights: [[2, -10], [9, 10], [3, -15], [7, 15], [5, -12], [12, 12], [15, -10], [20, 10], [19, -8], [24, 8]]

// -> sort: [[2, -10], [3, -15], [5, -12], [7, 15], [9, 10], [12, 12], [15, -10], [19, -8], [20, 10], [24, 8]]
/*
index   height  prev    cur     pq              ret
2       -10     0       10      [10,0]          add [2,10]
3       -15     10      15      [15,10,0]       add [3,15]
5       -12     15      15      [15,12,10,0]    x
7       15      15      12      [12,10,0]       add [7,12]
9       10      12      12      [12,0]          x
12      12      12      0       [0]             add [12,0]
15      -10     0       10      [10,0]          add [15,10]
19      -8      10      10      [10,8,0]        x
20      10      10      8       [8,0]           add [20,8]
24      8       8       0       [0]             add [24,0]

*/

class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> ret = new ArrayList<>();
        
        List<int[]> heights = new ArrayList<>();
        
        for(int[] building: buildings) {
            heights.add(new int[] {building[0], -building[2]});
            heights.add(new int[] {building[1], building[2]});
        }
         
        Collections.sort(heights, (a,b) -> {
            // sort with index
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            // sort with height
            return a[1] - b[1];
        });
        
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> (b - a));
        pq.offer(0);
        
        int prev = 0;
        for(int[] height: heights) {
            if(height[1] < 0) {
                pq.offer(-height[1]);
            } else {
                pq.remove(height[1]);
            }
            
            int cur = pq.peek();
            if (prev != cur) {
                List<Integer> skyline = new ArrayList<>();
                skyline.add(height[0]);
                skyline.add(cur);
                
                ret.add(skyline);
                
                prev = cur;
            }
        }
        
        return ret;
        
    }
}
```

## Ref

* [https://leetcode.com/problems/the-skyline-problem/](https://leetcode.com/problems/the-skyline-problem/)

## Tag

`#priority-queue`

