# Course Schedule III

## Problem

There are `n` different online courses numbered from `1` to `n`. You are given an array `courses` where `courses[i] = [durationi, lastDayi]` indicate that the `ith` course should be taken **continuously** for `durationi` days and must be finished before or on `lastDayi`.

You will start on the `1st` day and you cannot take two or more courses simultaneously.

Return _the maximum number of courses that you can take_.

## Example

{% hint style="info" %}
`sample input`: 

```
courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
```

`sample output`: 3
{% endhint %}



.

.

.



## Idea

1. Greedy하게 처리 ...  후보정을 해줌.

## Complexity

* Time : $$O(NlogN)$$
* Space: $$O(NlogN)$$

## Code 

* end time기준으로 sorting \(똑같은 종류의 courses를 선택하더라도 endtime이 커야 유리함\)
* 일단 넣고 보자
* 오래걸**렸**던 친구를 제외

```java
// [100  200]
// [200  1100]
// [1000 1250]
// [100  1400]
// [200  1600]
// [2000 3200]

class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (x,y) -> Integer.compare(x[1], y[1]));
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (x,y) -> Integer.compare(y, x)
        );
        
        int sum = 0;
        for(int[] course: courses) {
            sum += course[0];
            pq.offer(course[0]);
            
            if (sum > course[1]) {
                int beforeMaxDuration = pq.poll();
                sum -= beforeMaxDuration;
            }
        }
        
        return pq.size();        
    }
}
```

## Ref

{% embed url="https://leetcode.com/problems/course-schedule-iii/" %}





## Tag

`#priority-queue` `#schedule`

