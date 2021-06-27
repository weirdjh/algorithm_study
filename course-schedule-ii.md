# Course Schedule II

## Problem



There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

* For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return _the ordering of courses you should take to finish all courses_. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.

**Example 1:**

```text
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]

Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. 
So the correct course order is [0,1].
```



.

.

.



## Idea

* Prerequisite!

## Complexity

* Time: $$O(V+E)$$
* Space: $$O(V+E)$$

## Code 

```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        if (numCourses <= 0) {
            return new int[]{};
        }
        
        final int[] inDegree = new int[numCourses];
        final HashMap<Integer, List<Integer>> adj = new HashMap<>();
        
        // initialize
        for (int i = 0; i < numCourses; i++) {
            inDegree[i] = 0;
            adj.put(i,  new ArrayList<Integer>());
        }
        
        for (int[] prerequisite: prerequisites){
            int start = prerequisite[1];
            int end = prerequisite[0];
            
            adj.get(start).add(end);
            inDegree[end] += 1;
        }
        
        final int[] order = new int[numCourses];
        int orderIdx = 0;
        
        final Queue<Integer> queue = new LinkedList<Integer>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }
        
        while(!queue.isEmpty()) {
            final int current = queue.poll();
            order[orderIdx++] = current;
            
            for (int next: adj.get(current)) {
                if (inDegree[next] > 0) {                    
                    inDegree[next] -= 1;
                }
                if (inDegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }
        
        return (orderIdx == numCourses) ? order : new int[]{};
    }
}
```

## Ref

* [https://leetcode.com/problems/course-schedule-ii/](https://leetcode.com/problems/course-schedule-ii/)

## Tag

`#topological-sort`

