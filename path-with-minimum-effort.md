# Path With Minimum Effort

## Problem



You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` \(i.e., **0-indexed**\). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference** in heights between two consecutive cells of the route.

Return _the minimum **effort** required to travel from the top-left cell to the bottom-right cell._

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/04/ex1.png)

```text
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2

Explanation: 
The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```





.

.

.



## Idea

* smaller diff first!

## Complexity

* Time: $$O(mnlog(mn))$$
* Space: $$O(mn)$$

## Code 

```java
class Solution {
    
    int[] dirX = new int[]{-1, 0, 1, 0};
    int[] dirY = new int[]{0, -1, 0, 1};
    
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        
        int[][] efforts = new int[m][n];
        for(int[]e: efforts) {
            Arrays.fill(e, Integer.MAX_VALUE);
        }
        
        efforts[0][0] = 0;
        
        // x,y,effort
        PriorityQueue<int[]> pq = new PriorityQueue<>((x,y) -> Integer.compare(x[2], y[2]));
        pq.offer(new int[]{0, 0, 0});
        
        while(!pq.isEmpty()) {
            int[] current = pq.poll();
            int x = current[0];
            int y = current[1];
            int effort = current[2];
            
            if (x == n-1 && y == m-1) {
                return effort;   
            }
            
            for(int i=0; i<4; i++) {
                int nextX = x + dirX[i];
                int nextY = y + dirY[i];
                
                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
                    continue;
                }
                
                int nextEffort = Math.max(effort, Math.abs(heights[nextY][nextX] - heights[y][x]));
                
                // Do next if it betters
                if (efforts[nextY][nextX] > nextEffort) {
                    efforts[nextY][nextX] = nextEffort;
                    pq.offer(new int[] {nextX, nextY, nextEffort});
                }
                
            }
            
        }
        
        return -1;
        
    }
}
```

## Ref

* [https://leetcode.com/problems/path-with-minimum-effort/](https://leetcode.com/problems/path-with-minimum-effort/)

## Tag

`#Dijkstra`

