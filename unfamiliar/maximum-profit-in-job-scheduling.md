# Maximum Profit in Job Scheduling

## Problem

We have `n` jobs, where every job is scheduled to be done from `startTime[i]` to `endTime[i]`, obtaining a profit of `profit[i]`.

You're given the `startTime`, `endTime` and `profit` arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time `X` you will be able to start another job that starts at time `X`.

## Example

```text
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120

Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
```

.

.

.



## Idea

* DP \(Max sum 찾는 문제 어케 풀지~?\)

## Complexity

* Time : $$O(NlogN)$$ 
* Space: $$O(NlogN)$$

## Code 

{% tabs %}
{% tab title="dp" %}


```java
// 1. dp[i] = Max(dp[i-1], Max(dp[j]) + profit[i])

class Solution {
    class Job {
        int startTime;
        int endTime;
        int profit;
        
        Job(int startTime, int endTime, int profit) {
            this.startTime = startTime;
            this.endTime = endTime;
            this.profit = profit;
        }
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        Job[] jobs = new Job[endTime.length];
        for(int i=0; i<endTime.length; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }
        
        Arrays.sort(jobs, (x,y) -> Integer.compare(x.endTime, y.endTime));
        
        int[] dp = new int[jobs.length+1];
        
        for(int i=1; i<=jobs.length; i++) {
            dp[i] = jobs[i-1].profit;
            
            int beforeMax = 0;
            for(int j=1; j<i; j++) {
                if (jobs[j-1].endTime <= jobs[i-1].startTime) {
                    beforeMax = Math.max(beforeMax, dp[j]);
                }
            }
            dp[i] += beforeMax;
            
            dp[i] = Math.max(dp[i-1], dp[i]);
        }
        
        return dp[jobs.length];
    }
}
```
{% endtab %}

{% tab title="dp+binarySearch" %}


```java
// 1. dp[i] = Max(dp[i-1], Max(dp[j]) + profit[i])
// 2. Search Index using Binary Search

class Solution {
    class Job {
        int startTime;
        int endTime;
        int profit;
        
        Job(int startTime, int endTime, int profit) {
            this.startTime = startTime;
            this.endTime = endTime;
            this.profit = profit;
        }
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        Job[] jobs = new Job[endTime.length];
        for(int i=0; i<endTime.length; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }
        
        Arrays.sort(jobs, (x,y) -> Integer.compare(x.endTime, y.endTime));
        
        int[] dp = new int[jobs.length+1];
        
        for(int i=1; i<=jobs.length; i++) {
            dp[i] = jobs[i-1].profit;
            
            int beforeMaxIdx = binarySearch(jobs, jobs[i-1].startTime, 0, i-2);
            if (beforeMaxIdx >= 0) {
                dp[i] += dp[beforeMaxIdx+1];
            }
            
            dp[i] = Math.max(dp[i-1], dp[i]);
        }
        
        return dp[jobs.length];
    }
    
    public int binarySearch(Job[] jobs, int startTime, int left, int right) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if (jobs[mid].endTime <= startTime) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return right;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/maximum-profit-in-job-scheduling/](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)

## Tag

`#schedule` `#maxsum` `#dp` `#binary search`

