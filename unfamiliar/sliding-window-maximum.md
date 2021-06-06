# Sliding Window Maximum

## Problem

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return _the max sliding window_.

## Example

{% hint style="info" %}
`sample input`: 

```
nums = [1,3,-1,-3,5,3,6,7], k = 3
```

```
sample output: [3,3,5,5,6,7]

Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3 
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5 
 1  3  -1 [-3  5  3] 6  7       5 
 1  3  -1  -3 [5  3  6] 7       6 
 1  3  -1  -3  5 [3  6  7]      7
```
{% endhint %}



.

.

.



## Idea

* 계속해서 max를 들고 있으려면 어떤 방법을 사용해야할까?
  * priority queue?
  * deque?
* window밖으로 벗어난 친구들은 어떻게 처리?

## Complexity

* Time : $$O(N)$$
* Space: $$O(N)$$

## Code 

{% tabs %}
{% tab title="Priority Queue" %}
* Priority Queue \(Max heap을 통해 해결해보자\)
* queue.pop\(\)의 index가 window밖의 것이라면 -&gt; 제
* optimal풀이 아님
  * Time : $$O(NlogK)$$

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] ans = new int[nums.length - k + 1];
        int idx = 0;
        
        PriorityQueue<Integer[]> pq = new PriorityQueue<>(k+1, (x,y) -> y[0]-x[0]);
        
        for(int i=0; i<k; i++) {
            pq.offer(new Integer[] {nums[i], i});
        }
        ans[idx++] = pq.peek()[0];
        
        for(int i=k; i<nums.length; i++) {
            pq.offer(new Integer[] {nums[i], i});
            while(!pq.isEmpty() && pq.peek()[1] <= i-k) {
                pq.poll();
            }
            
            ans[idx++] = pq.peek()[0];
        }
        
        return ans;
    }
}
```
{% endtab %}

{% tab title="Deque" %}
* 현재 보는 값 보다 queue에 들어있는 값이 작다면? 
  * 이 값들은 중요하지 않음... 전부 제거
* queue의 첫 값의 index가 window밖으로 밀려났다면? 제

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] ans = new int[nums.length - k + 1];
        int idx = 0;
        
        Deque<Integer> dq = new ArrayDeque<>();
        
        for(int i=0; i<nums.length; i++) {
            while(!dq.isEmpty() && nums[dq.getLast()] < nums[i]) {
                dq.removeLast();
            }
            dq.add(i);
            
            // 사실 index가 i-k보다 작아지는 경우는 없음
            // 왜냐하면, i-k인 매 경우에 체크가 되기 때문.
            if (dq.getFirst() <= i-k) {
                dq.removeFirst();
            }
            
            if (i >= k-1) {
                ans[idx++] = nums[dq.getFirst()];
            }
        }
        
        return ans;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/sliding-window-maximum/](https://leetcode.com/problems/sliding-window-maximum/)

## Tag

`#priority-queue` `#deque` `#sliding-window` `#heap`

