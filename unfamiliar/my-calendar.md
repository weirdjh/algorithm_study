# My Calendar

## Problem

You are implementing a program to use as your calendar.

The event can be represented as a pair of integers `start` and `end` that represents a booking on the half-open interval `[start, end)`, the range of real numbers `x` such that `start <= x < end`.

Implement the `MyCalendar` class:

* `MyCalendar()` Initializes the calendar object.
* `boolean book(int start, int end)` Returns `true` if the event can be added to the calendar successfully without causing a **double booking**. Otherwise, return `false` and do not add the event to the calendar.







.

.

.



## Idea

* binary search!?
* overlap check !?

## Code 

{% tabs %}
{% tab title="Prevent Double" %}
* insert new one where possible

```java
// 10: 20
// 25: 30
// 20: 25 ?

class MyCalendar {
    
    List<int[]> tasklist;

    public MyCalendar() {
        tasklist = new ArrayList<>();
    }
    
    public boolean book(int start, int end) {
        Integer idx = binarySearch(tasklist, start, end);
        if (idx == null) {
            return false;
        }
        
        tasklist.add(idx, new int[]{start, end});
        
        return true;
    }
    
    // [25], 20 -> 0
    // [10], 20 -> 1
    // [10, 25], 20 -> 1
    private Integer binarySearch(List<int[]> tasklist, int start, int end) {
        int left = 0, right = tasklist.size()-1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            int taskStart = tasklist.get(mid)[0];
            int taskEnd = tasklist.get(mid)[1];
            
            // Valid case -> [ ] s e / s e [ ]
            if (taskEnd <= start) {
                left = mid + 1;
            }
            
            else if (end <= taskStart) {
                right = mid - 1;
            }
            
            // Double booking case -> [s ] e / s [e] / s [] e / [s e]
            else {
                return null;
            }
        }
        
        return left;
    }
}
```
{% endtab %}

{% tab title="Prevent Triple" %}
* check overlapped case

```java
class MyCalendarTwo {
    
    List<int[]> calanders;
    List<int[]> overlaps;

    public MyCalendarTwo() {
        calanders = new ArrayList<>();
        overlaps = new ArrayList<>();
    }
    
    public boolean book(int start, int end) {
        for(int[] overlap: overlaps) {
            // [s e], s [e], s[]e, [s]e
            if (overlap[0] < end && start < overlap[1]) {
                return false;
            }
        }
        
        for(int[] calander: calanders) {
            // [s e], s [e], s[]e, [s]e
            if (calander[0] < end && start < calander[1]) {
                overlaps.add(new int[]{Math.max(calander[0], start), Math.min(calander[1], end)});
            }
        }
        
        calanders.add(new int[]{start, end});
        
        return true;
    }
}
```
{% endtab %}

{% tab title="How many duplicate?" %}
* ordered map을 사용하자
* 특정 범위 시작 : `+1` / 끝: `-1`

```java
class MyCalendarTwo {
    
    TreeMap<Integer, Integer> deltas;

    public MyCalendarThree() {
        deltas = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        deltas.put(start, deltas.getOrDefault(start, 0)+1);
        deltas.put(end, deltas.getOrDefault(end, 0)-1);
        
        int ans = 0;
        int count = 0;
        for(int duplicateCount: deltas.values()) {
            count += duplicateCount;
            ans = Math.max(ans, count);
        }
        
        return ans;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/my-calendar-i/](https://leetcode.com/problems/my-calendar-i/)
* [https://leetcode.com/problems/my-calendar-ii/](https://leetcode.com/problems/my-calendar-ii/)
* [https://leetcode.com/problems/my-calendar-iii/](https://leetcode.com/problems/my-calendar-iii/)

## Tag

`#Binary-Search` `#duplicate-range` `#overlap` 

