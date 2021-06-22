# Single-Threaded CPU

## Problem



You are given `n`​​​​​​ tasks labeled from `0` to `n - 1` represented by a 2D integer array `tasks`, where `tasks[i] = [enqueueTimei, processingTimei]` means that the `i​​​​​​th`​​​​ task will be available to process at `enqueueTimei` and will take `processingTimei` to finish processing.

You have a single-threaded CPU that can process **at most one** task at a time and will act in the following way:

* If the CPU is idle and there are no available tasks to process, the CPU remains idle.
* If the CPU is idle and there are available tasks, the CPU will choose the one with the **shortest processing time**. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
* Once a task is started, the CPU will **process the entire task** without stopping.
* The CPU can finish a task then start a new one instantly.

Return _the order in which the CPU will process the tasks._

## Example

```text
Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
```

.

.

.



## Idea

* Keep two conditions

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(N)$$

## Code 



{% tabs %}
{% tab title="pq" %}
```java
class Solution {
    class Task {
        int id;
        int startTime;
        int processingTime;
        
        Task(int id, int startTime, int processingTime) {
            this.id = id;
            this.startTime = startTime;
            this.processingTime = processingTime;
        }
    }
    
    class TaskCompare implements Comparator<Task> {
        @Override
        public int compare(Task a, Task b) {
            if (a.startTime == b.startTime) {
                return a.processingTime - b.processingTime;
            }
            
            return a.startTime - b.startTime;
        }
    }
    
    class WaitCompare implements Comparator<Task> {
        @Override
        public int compare(Task a, Task b) {
            if (a.processingTime == b.processingTime) {
                return a.id - b.id;
            }
            
            return a.processingTime - b.processingTime;
        }
    }
    
    public int[] getOrder(int[][] tasks) {
        PriorityQueue<Task> taskQ = new PriorityQueue<>(new TaskCompare());
        PriorityQueue<Task> waitQ = new PriorityQueue<>(new WaitCompare());
        
        for(int i=0; i<tasks.length; i++) {
            taskQ.offer(new Task(i, tasks[i][0], tasks[i][1]));
        }
        
        int idx = 0;
        int[] ans = new int[tasks.length];
        
        int time = 0;
        while(!taskQ.isEmpty() || !waitQ.isEmpty()) {
            while (!taskQ.isEmpty() && taskQ.peek().startTime <= time) {
                waitQ.offer(taskQ.poll());
            }
            
            if(waitQ.isEmpty()) {
                Task currentTask = taskQ.poll();
                time += (currentTask.startTime + currentTask.processingTime);
                ans[idx++] = currentTask.id;
                
                continue;
            }
            
            Task currentTask = waitQ.poll();
            time += currentTask.processingTime;
            ans[idx++] = currentTask.id;
        }
        
        return ans;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/single-threaded-cpu/](https://leetcode.com/problems/single-threaded-cpu/)

## Tag

`#priority-queue` `#schedule` 

