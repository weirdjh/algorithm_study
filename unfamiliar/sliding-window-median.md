# Sliding Window Median

## Problem

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

* For examples, if `arr = [2,3,4]`, the median is `3`.
* For examples, if `arr = [1,2,3,4]`, the median is `(2 + 3) / 2 = 2.5`.

You are given an integer array `nums` and an integer `k`. There is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return _the median array for each window in the original array_. Answers within `10-5` of the actual value will be accepted.

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
[1  3  -1] -3  5  3  6  7       1 
 1 [3  -1  -3] 5  3  6  7      -1
 1  3 [-1  -3  5] 3  6  7      -1 
 1  3  -1 [-3  5  3] 6  7       3 
 1  3  -1  -3 [5  3  6] 7       5 
 1  3  -1  -3  5 [3  6  7]      6
```
{% endhint %}



.

.

.



## Idea

* median을 찾으려면?
* brute force -&gt; $$O(NK)$$, K를 어떻게 줄일건데?

## Complexity

* Time : $$O(NlogK)$$
* Space: $$O(N)$$

## Code 

{% tabs %}
{% tab title="Find Median from Data Stream" %}
* 숫자가 계속 추가가능할 때, 각 status에서 median값을 구하는 문제.
* ```text
  Explanation

  MedianFinder medianFinder = new MedianFinder();
  medianFinder.addNum(1);    // arr = [1]
  medianFinder.addNum(2);    // arr = [1, 2]
  medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
  medianFinder.addNum(3);    // arr[1, 2, 3]
  medianFinder.findMedian(); // return 2.0
  ```
* size가 1아래로 차이나는 두개의 priority queue \(Lower MaxHeap / Upper MinHeap\) 사

```java
class MedianFinder {
    
    // Max heap
    private PriorityQueue<Integer> lowerPQ;
    
    // Min heap
    private PriorityQueue<Integer> upperPQ;

    /** initialize your data structure here. */
    public MedianFinder() {
        lowerPQ = new PriorityQueue<Integer>((x,y)-> Integer.compare(y,x));
        upperPQ = new PriorityQueue<Integer>((x,y)-> Integer.compare(x,y));
    }
    
    public void addNum(int num) {
        lowerPQ.offer(num);
        upperPQ.offer(lowerPQ.poll());
        
        if (lowerPQ.size() < upperPQ.size()) {
            lowerPQ.offer(upperPQ.poll());
        }
    }
    
    public double findMedian() {
        if (lowerPQ.size() == upperPQ.size()) {
            return (lowerPQ.peek() + upperPQ.peek()) / 2.0;
        }
        
        return lowerPQ.peek();
    }
}

```
{% endtab %}

{% tab title="Sliding Window Median" %}
* java의 Priority Queue의 remove는 O\(N\)임.
* 따라서 이 풀이는 O\(NK\)임 ... heap으로 대체해야함.

```java
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        
        double[] medians = new double[nums.length - k + 1];
        int medianIndex = 0;
        
        MedianQueue mq = new MedianQueue();
        
        for(int i=0; i<nums.length; i++) {
            mq.insert(nums[i]);
            
            if (mq.size() == k) {
                medians[medianIndex++] = mq.getMedian();
                
                // index주의!!
                // i == k-1 일때, mq.size() == k가 되므로...
                mq.remove(nums[i-k+1]);
            }
        }
        
        return medians;
    }
    
    class MedianQueue {
        
        private int k;
        
        private PriorityQueue<Integer> lowerMaxPQ = new PriorityQueue<>((x,y) -> Integer.compare(y, x));
        private PriorityQueue<Integer> upperMinPQ = new PriorityQueue<>((x,y) -> Integer.compare(x, y));
        
        public void insert(int num) {
            lowerMaxPQ.offer(num);
            upperMinPQ.offer(lowerMaxPQ.poll());
            
            if (lowerMaxPQ.size() < upperMinPQ.size()) {
                lowerMaxPQ.offer(upperMinPQ.poll());
            }
        }
        
        public int size() {
            return lowerMaxPQ.size() + upperMinPQ.size();
        }
        
        public double getMedian() {
            if (lowerMaxPQ.size() == upperMinPQ.size()) {
                return ((long)lowerMaxPQ.peek() + upperMinPQ.peek()) / 2.0;
            }
            
            return lowerMaxPQ.peek();
        }
        
        public boolean remove(int num) {
            return lowerMaxPQ.remove(num) || upperMinPQ.remove(num);
        }
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

{% embed url="https://leetcode.com/problems/find-median-from-data-stream/" %}

{% embed url="https://leetcode.com/problems/sliding-window-median/" %}







## Tag

`#priority-queue` `#heap` `#sliding-window` `#median`

