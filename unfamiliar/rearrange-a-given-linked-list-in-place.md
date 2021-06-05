# Rearrange a given linked list in-place

## Problem

Given a singly linked list L0 -&gt; L1 -&gt; … -&gt; Ln-1 -&gt; Ln. Rearrange the nodes in the list so that the new formed list is : L0 -&gt; Ln -&gt; L1 -&gt; Ln-1 -&gt; L2 -&gt; Ln-2 … You are required to do this in place without altering the nodes’ values.

## Example

{% hint style="info" %}
`sample input`:   1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6  
`sample output`: 1 -&gt; 6 -&gt; 2 -&gt; 5 -&gt; 3 -&gt; 4  


`sample input`:   1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5  
`sample output`: 1 -&gt; 5 -&gt; 2 -&gt; 4 -&gt; 3
{% endhint %}

.

.

.



## Idea

1. 절반을 나누기 + 뒤에거 뒤집기 + 합치기
2. recursion
   1. slow+fast를 통해 recursive 하게 depth를 늘려감.
   2. `fast == null` or `fast.next == null`이라면 중간값을 찾아줄 수 있음 \(홀짝 주의\)
   3. recursive stack을 통해 리스트 순서 조정 

## Complexity

* Time : O\(N\)
* Space: O\(1\)

## Code

{% tabs %}
{% tab title="1st\_divide" %}
## 절반을 나누기 + 뒤에거 뒤집기 + 합치기

* 절반 나누기

```java
// 1
// slow : 1

// 1 -> 2
// slow : 1

// 1 -> 2 -> 3
// slow : 2

// 1 -> 2 -> 3 -> 4
// slow : 2
Node slow = head;
Node fast = slow.next;

// fast == null ... odd case
// fast.next == null .. even case
while (fast != null && fast.next != null) {
    slow = slow.next;
    fast = fast.next.next;
}
```

* 뒤에거 뒤집기

```java
// 1 -> 2 -> 3

// curr: 1, prev: null
// "1" -> null

// curr: 2, prev: 1
// "2" -> 1 -> null

// curr: 3, prev: 2
// "3" -> 2 -> 1 -> null

Node reverselist(Node head) {
    Node prev = null;
    Node curr = head;
    
    while (curr != null) {
        Node next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    node = prev;
    
    return node;
}
```

* 합치기

```java
// Assign dummy Node
node = new Node(0);
  
// curr is the pointer to this dummy Node, which
// will be used to form the new list
Node curr = node;
while (node1 != null || node2 != null) {

    // First add the element from first list
    if (node1 != null) {
        curr.next = node1;
        curr = curr.next;
        node1 = node1.next;
    }

    // Then add the element from second list
    if (node2 != null) {
        curr.next = node2;
        curr = curr.next;
        node2 = node2.next;
    }
}

// Assign the head of the new list to head pointer
node = node.next;
```
{% endtab %}

{% tab title="2nd\_resursion" %}
## Recursion

```java
import java.util.*;

// dfs
// 1 -> add(6) -> (1 next) 2 // return 6
// 		2-> add(5) -> (2 next) 3 // return 5
//				3-> add (4) / return 4

// return head(1)

// Make me confusion!!?? -> fast / slow pointer problem
// 1. must check linked list size < 2
// 2. odd / even check!!! really confused.
// 3. make "leafNode.next = null"
// 4. Manage node for return

public Node rearrangeLinkedList(Node head) {
		if (head.next == null) {
			return head;
		}
	
		dfs(head, head.next);
		
		return head;
}
	
public Node dfs(Node slow, Node fast) {

		// Odd case
		// ex. 1 2 3 4 5
		if (fast == null){
			Node nextNode = slow.next;
			slow.next = null;
			
			return nextNode;
		} 
		
		// Even case
		// ex. 1 2 3 4 5 6
		if (fast.next == null) {
			Node nextNode = slow.next.next;
			slow.next.next = null;
			
			return nextNode;
		}
		
		Node insertNode = dfs(slow.next, fast.next.next);
		
		Node nextNode = slow.next;
		Node insertNextNode = insertNode.next;
		
		slow.next = insertNode;
		insertNode.next = nextNode;
		
		return insertNextNode;
}
```
{% endtab %}
{% endtabs %}



## Ref

[https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/](https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/)



## Tag

`#singly-linked-list` `#recursion`

