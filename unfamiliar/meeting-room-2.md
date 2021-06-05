# Meeting Room 2

## Problem

 Given an array of meeting time intervals consisting of start and end times`[[s1,e1],[s2,e2],...]`\(si&lt; ei\), find the minimum number of conference rooms required.

## Example

{% hint style="info" %}
`sample input`:  \[ \[0, 30\], \[5, 10\], \[15, 20\] \]

`sample output`:  2
{% endhint %}

.

.

.



## Idea

* 기본적으로 start time기준으로 sorting이 필요하다.
* end time을 어떻게 처리할 지에 대해 두 가지 아이디어가 있음
  * priority queue를 이용 -&gt; 각 meeting이 추가 될 때 마다 필요한 방의 개수를 알 수 있음
  * two pointer를 이용 -&gt; start / end time의 관계를 걍 무시 -&gt; 방의 개수만 관심

## Complexity

* Time : O\(N\)
* Space: O\(1\) two pointer 사용 시에 optimal

## Code

{% tabs %}
{% tab title="pq\_1st" %}
1. while을 통해 현재 가능한 meeting room의 개수를 계속 구함
2. max를 update

```java
import java.util.*;

// two pointer -> s, e
// if (s.endtime <= e.starttime) -> s ++;
// else -> e ++
// update max with (e - s + 1)

class Program {

  public int requiredMeetingRooms(ArrayList<ArrayList<Integer>> meetings) {
		if (meetings.size() == 0){
			return 0;
		}
	
    Collections.sort(meetings, (x,y) -> Integer.compare(x.get(0), y.get(0)));
		
		PriorityQueue<ArrayList<Integer>> pq = 
			new PriorityQueue<>(meetings.size(), (x,y) -> Integer.compare(x.get(1), y.get(1)));
		
		int max = 0;
		
		for(int i=0; i<meetings.size(); i++) {
			ArrayList<Integer> meeting = meetings.get(i);
			
			// Attention!
			while(!pq.isEmpty() && pq.peek().get(1) <= meetings.get(0)) {
				pq.poll();
			}
			
			pq.offer(meeting);
			
			max = Math.max(max, pq.size());
		}
		
    return max;
  }
}


```
{% endtab %}

{% tab title="pq\_2nd" %}
1. while -&gt; if 로 바뀌었음
2. meeting룸 자리가 하나 나면 / 한 놈이 들어옴 \(queue사이즈 변동 없음\)
3. 자리 없으면 queue 사이즈가 늘어남
4. 최종적으로 queue사이즈를 구하면 몇개의 방이 필요한 지 알 수 있음.

```java
import java.util.*;

// two pointer -> s, e
// if (s.endtime <= e.starttime) -> s ++;
// else -> e ++
// update max with (e - s + 1)

class Program {

  public int requiredMeetingRooms(ArrayList<ArrayList<Integer>> meetings) {
		if (meetings.size() == 0){
			return 0;
		}
	
    Collections.sort(meetings, (x,y) -> Integer.compare(x.get(0), y.get(0)));
		
		PriorityQueue<ArrayList<Integer>> pq = 
			new PriorityQueue<>(meetings.size(), (x,y) -> Integer.compare(x.get(1), y.get(1)));
		
		for(int i=0; i<meetings.size(); i++) {
			ArrayList<Integer> meeting = meetings.get(i);
			
			// Attention!
			if(!pq.isEmpty() && pq.peek().get(1) <= meetings.get(0)) {
				pq.poll();
			}
			
			pq.offer(meeting);
		}
		
    return pq.size();
  }
}

```
{% endtab %}

{% tab title="Two\_pointer" %}
1. Two pointer
2. start time / end time을 sorting

```java
import java.util.*;

// 1. sort with the start time
// 2. sort with the end time

// 0 1 2 3 4 5 6 7 8 9 10 11
// x x 
//   x x x 
//         x x 
// x x x x
//               x
//                   x x
//       x x x x x x x

// s : 0 0 1 3 4 7  9
// e : 2 4 4 6 8 10 11

class Program {

  public int laptopRentals(ArrayList<ArrayList<Integer>> meetings) {
    int[] starts = new int[meetings.size()];
		int[] ends = new int[meetings.size()];
		
		for(int i=0; i<meetings.size(); i++) {
			starts[i] = meetings.get(i).get(0);
			ends[i] = meetings.get(i).get(1);
		}
		
		Arrays.sort(starts);
		Arrays.sort(ends);
		
		int usedRoom = 0;
		int e=0;
		for(int s=0; s<starts.length; s++) {
			// 겹침 -> 추가로 방이 없어도 됨.
			if (starts[s] >= ends[e]) {
				e += 1;
				usedRoom -= 1;
			}
			usedRoom += 1;
		}
		
    return usedRoom;
  }
}

```
{% endtab %}
{% endtabs %}

## Ref

[https://www.geeksforgeeks.org/minimum-halls-required-for-class-scheduling/](https://www.geeksforgeeks.org/minimum-halls-required-for-class-scheduling/)



## Tag

`#priority_queue` `#schedule` `#two_pointer`

