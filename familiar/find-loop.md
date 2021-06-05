# Find Loop

## Problem

Given the head of a Singly Linked List that contains a loop, find the node from which the loop originates.

## Example

{% hint style="info" %}
`sample input`:   
head = 0 -&gt; 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6  
                                           ^             v  
                                           9 &lt;- 8 &lt;- 7

`sample output`:   
head = 4 -&gt; 5 -&gt; 6  
             ^             v  
             9 &lt;- 8 &lt;- 7
{% endhint %}

.

.

.



## Idea

* Floyd's Cycle finding algorithm

![](../.gitbook/assets/image%20%285%29.png)



* * slow + fast pointer 를 통해서 cycle을 찾을 수 있음.
  * 언제 slow와 fast point가 만날까
    * fast pointer 간 거리 = 2 \* \(slow pointer 간 거리\)`(m + n*x + k) = 2 * (m + n*y + k)         m + k = (x-2y) * n`
    * head가 m의 위치에 간다면? fast는 m+k만큼 움직였을 것!
    * 근데? `m+k는 n의 배수` 이므로 cycle을 \(x-2y\)회 돌아서 head와 만남.

## Complexity

* Time : O\(N\)
* Space: O\(1\)

## Code

```java
import java.util.*;

class Program {
  public static LinkedList findLoop(LinkedList head) {
		if (head.next == null) {
			return null;
		}
		LinkedList fast = head.next.next;
		LinkedList late = head.next;
		
		while(fast != late) {
			if (fast.next == null) {
				return null;
			}
			fast = fast.next.next;
			late = late.next;
		}
		
		// 2 4 6 | 8 4 6 8 4 6 | 8 4 [6]
		//  
		// 1 2 3 | 4 5 6 7 8 9 | 4 5 [6] 
		//   
		// m + x*n+ k = 2*(m + y*n+ k)
		// m + d = n * (x-2y)
		
		while(head != fast) {
			head = head.next;
			fast = fast.next;
		}
		
    return fast;
  }

  static class LinkedList {
    int value;
    LinkedList next = null;

    public LinkedList(int value) {
      this.value = value;
    }
  }
}
```



## Ref

{% embed url="https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/" %}



## Tag

`#math` `#cycle` `#singly-linked-list` `#Floyd's-loop-detection`

