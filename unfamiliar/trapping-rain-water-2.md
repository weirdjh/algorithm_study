# Trapping Rain Water 2

## Problem

Given an `m x n` integer matrix `heightMap` representing the height of each unit cell in a 2D elevation map, return _the volume of water it can trap after raining_.

## Example

![](https://assets.leetcode.com/uploads/2021/04/08/trap1-3d.jpg)

```text
Input: height = 
[
    [1,4,3,1,3,2],
    [3,2,1,3,2,4],
    [2,3,3,2,3,1]
]
Output: 4
```



.

.

.



## Idea

* Trapping 1번 문제랑 똑같이 풀려고 하면 안된다젠장.
  * 가로로 한 번,세로로 한 번..가둘 수 있는 경우를 구하면 될 거라 생각했지만 오산이었다.
  * 테두리에 있는 min 값을 찾아야하는데,가로에서 찾은 min 값이 세로에 적용이 안될 수 있기 때문.
* Priority Queue를 이용해서 풀면 좋음.
  * 해당 border로 부터 가둘 수 있는 물\(?\)들을 찾아주는 것이 핵심.
* 문제 개어려워서 이거 생각하는게 신기함

## Complexity

* Time : $$O(MNlog(MN))$$
* Space: $$O(MNlog(MN))$$

## Code 

```java
/*
[1,4,3,1,3,2]
[3,2,1,3,2,4]
[2,3,3,2,3,1]
*/

class Solution {
    class Point {
        int x;
        int y;
        int height;
        public Point(int x, int y, int height) {
            this.x = x;
            this.y = y;
            this.height = height;
        }
    }
    public int trapRainWater(int[][] heightMap) {
        int n = heightMap.length;
        int m = heightMap[0].length;
        
        PriorityQueue<Point> pq = new PriorityQueue<>((x,y) -> Integer.compare(x.height, y.height));
        
        // Add border to priority queue
        for(int i=0; i<n; i++) {
            pq.offer(new Point(0, i, heightMap[i][0]));
            pq.offer(new Point(m-1, i, heightMap[i][m-1]));
        }
        for(int i=1; i<m-1; i++) {
            pq.offer(new Point(i, 0, heightMap[0][i]));
            pq.offer(new Point(i, n-1, heightMap[n-1][i]));
        }
        
        // init visited status
        boolean[][] visited = new boolean[n][m];
        
        for(int i=0; i<n; i++){
            Arrays.fill(visited[i], false);   
        }
        
        int sum = 0;
        int heightMax = 0;
        
        int[] dirX = new int[] {-1, 0, 1, 0};
        int[] dirY = new int[] {0, -1, 0, 1};
        
        // BFS with PriorityQueue
        while(!pq.isEmpty()) {
            Point current = pq.poll();
            
            if(visited[current.y][current.x]) {
                continue;
            }
            
            heightMax = Math.max(heightMax, current.height);
            
            sum += (heightMax - current.height);
            
            visited[current.y][current.x] = true;
            
            for(int i=0; i<4; i++) {
                int nextX = current.x + dirX[i];
                int nextY = current.y + dirY[i];
                
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
                    continue;
                }
                
                if (visited[nextY][nextX]) {
                    continue;
                }
                
                pq.offer(new Point(nextX, nextY, heightMap[nextY][nextX]));
            }
        }
        
        return sum;
    }
}
```

## 

## Ref

* [https://leetcode.com/problems/trapping-rain-water-ii/](https://leetcode.com/problems/trapping-rain-water-ii/)

## Tag

`#priority-queue` `#border`

