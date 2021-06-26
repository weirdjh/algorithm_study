# Minimum Number of Refueling Stops

## Problem

A car travels from a starting position to a destination which is `target` miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array `stations` where `stations[i] = [positioni, fueli]` indicates that the `ith` gas station is `positioni` miles east of the starting position and has `fueli` liters of gas.

The car starts with an infinite tank of gas, which initially has `startFuel` liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return _the minimum number of refueling stops the car must make in order to reach its destination_. If it cannot reach the destination, return `-1`.

Note that if the car reaches a gas station with `0` fuel left, the car can still refuel there. If the car reaches the destination with `0` fuel left, it is still considered to have arrived.

**Example 1:**

```text
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2

Explanation: We start with 10 liters of fuel.

We drive to position 10, expending 10 liters of fuel.  
We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  
We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
```





.

.

.



## Idea

* sum of fuels -&gt; total distance

## Complexity

* Time: $$O(n^2)$$
* Space: $$O(n)$$

## Code 

```java
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((x,y) -> Integer.compare(y,x));
        pq.offer(startFuel);
        
        int count = -1;
        int totalDist = 0;
        
        for(int[] station: stations) {
            while(totalDist < station[0]) {
                if (pq.isEmpty()) {
                    return -1;
                }
                totalDist += pq.poll();
                count += 1;
            }
            
            pq.offer(station[1]);
        }
        
        while (totalDist < target) {
            if (pq.isEmpty()) {
                return -1;
            }
            totalDist += pq.poll();
            count += 1;
        }
        
        return count;
    }
}
```

## Ref

* [https://leetcode.com/problems/minimum-number-of-refueling-stops/](https://leetcode.com/problems/minimum-number-of-refueling-stops/)

## Tag

`#jump` `#priority-queue` `#fuel-station`

