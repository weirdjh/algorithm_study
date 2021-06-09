---
description: '- Solve various linked list question'
---

# Linked List



{% tabs %}
{% tab title="Add Two Number 2" %}
## Problem



![](../.gitbook/assets/image%20%2817%29.png)



```text
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
```

## Idea

* list 거꾸로 부터 더해야하기 때문에 까다로운 문제
* reverse를 해버렷

## Code

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        int carry = 0;
        ListNode ans = null;
        while(l1 != null || l2 != null) {
            int sum = carry;
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            
            ListNode newNode = new ListNode(sum % 10);
            newNode.next = ans;
            ans = newNode;
            
            carry = sum / 10;
        }
        
        if (carry == 1) {
            ListNode newNode = new ListNode(1);
            newNode.next = ans;
            ans = newNode;
        }
        
        return ans;
    }
    
    public ListNode reverseList(ListNode head) {
        ListNode curNode = head;
        
        while(curNode.next != null) {
            ListNode nextNode = curNode.next;
            curNode.next = nextNode.next;
            nextNode.next = head;
            
            head = nextNode;
        }
        
        return head;
    }
}
```
{% endtab %}

{% tab title="Partition List" %}
## Problem

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.

![](../.gitbook/assets/image%20%2815%29.png)

```text
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```

## Idea

* dummy node 두개를 이용

## Code

```java
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummy1 = new ListNode(0);
        ListNode dummy2 = new ListNode(0);
        
        ListNode left = dummy1;
        ListNode right = dummy2;
        
        while(head != null) {
            if (head.val < x) {
                left.next = head;
                left = left.next;
            }
            else {
                right.next = head;
                right = right.next;
            }
            
            head = head.next;
        }
        // Attention! Avoid Cycle!
        right.next = null;
        
        left.next = dummy2.next;
        
        return dummy1.next;
    }
}
```
{% endtab %}

{% tab title="Palindrome Linked List" %}
## Problem



Given the `head` of a singly linked list, return `true` if it is a palindrome.

**Example 1:**![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```text
Input: head = [1,2,2,1]
Output: true
```

## Idea

* Reverse list

## Code

```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head.next == null) {
            return true;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        ListNode slow = dummy, fast = dummy;
        
        // 0 1 2 3
        // 0 1 2 3 4
        while(fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow = slow.next;
        
        // For odd case
        if (fast.next != null) {
            slow = slow.next;
        }
        
        // 1 2
        // 1 2 / 3
        // 1 2 / 3 4
        ListNode left = head;
        ListNode right = reverseList(slow);
        
        while(right != null) {
            if (right.val != left.val) {
                return false;
            }
            right = right.next;
            left = left.next;
        }
        
        return true;
    }
    
    public ListNode reverseList(ListNode head) {
        ListNode curNode = head;
        
        // 1 -> "2" -> 3
        // 2 -> 1 -> "3"
        while(curNode.next != null) {
            ListNode nextNode = curNode.next;
            
            curNode.next =  nextNode.next;
            nextNode.next = head;
            
            head = nextNode;
        }
        
        return head;
    }
}
```
{% endtab %}
{% endtabs %}





## Ref

* [https://leetcode.com/problems/add-two-numbers-ii/](https://leetcode.com/problems/add-two-numbers-ii/)
* [https://leetcode.com/problems/partition-list/](https://leetcode.com/problems/partition-list/)
* [https://leetcode.com/problems/palindrome-linked-list/](https://leetcode.com/problems/palindrome-linked-list/)



## Tag

`#linked-list`

