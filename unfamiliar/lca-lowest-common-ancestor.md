# LCA \(Lowest Common Ancestor\)

## Problem

Find Lowest Common Ancestor of two given nodes in a tree

## Example



{% hint style="info" %}
`sample input`: 

root : 3  
node1 : 7  
node2:  6
{% endhint %}

![](../.gitbook/assets/image%20%286%29.png)



{% hint style="info" %}
`sample output:`5
{% endhint %}

.

.

.



## Idea

1. Binary Search Tree 인 경우?
2. Binary Tree인 경우?
   1. Parent pointer가 있는 경우?
   2. Child pointer만 있는 경우?
3. N-ary Tree인 경우?
   1. follow up: 임의의 두 노드 사이의 거리는?

## Complexity

* Time : $$O(N)$$
* Space: $$O(N)$$

## Code 

{% tabs %}
{% tab title="BST" %}
* Binary Search Tree의 특징을 이용하자
  * 왼쪽 작음 / 오른쪽 
* Time : $$O(N)$$, Space: $$O(1)$$

```java
// Binary Search Tree
class Solution {
    public TreeNode lca(TreeNode node, TreeNode p, TreeNode q) {
        if (node == null) {
            return null;
        }
        
        // p, q 둘 다 node 왼쪽에 존재
        if (node.value > p.value && node.value > q.value) {
            return lca(node.left, p, q);
        }
        
        // p, q 둘 다 node 오른쪽에 존재
        if (node.value < p.value && node.value < q.value) {
            return lca(node.right, p, q);
        }
        
        
    }
}
```
{% endtab %}

{% tab title="BT\_parent" %}
* 한 쪽 먼저 부모따라 올라가면서 path를 저장
* 다른 쪽이 나중에 부모따라 올라가다가 path 중 하나에 도달하면 끝
* Time : $$O(N)$$, Space: $$O(N)$$ ... tree가 일렬종대 했을 때 worst.

```java
// 실제로 안해봄...ㅎ

// Binary Tree with parent
class Solution {
    public TreeNode lca(TreeNode p, TreeNode q) {
        Set<TreeNode> path = new HashSet<>();
        
        TreeNode curNode = p;
        while(curNode != null) {
            path.add(curNode);
            curNode = curNode.parent;
        }
        
        curNode = q;
        while(!path.contains(curNode)){
            curNode = curNode.parent;
        }
        
        return curNode;
    }
}
```
{% endtab %}

{% tab title="N-ary\_child\_path" %}
* root -&gt; p, q까지 path를 구해주는 방법.
* Time : $$O(N)$$, Space: $$O(N)$$

```java
// N-ary Tree with child

class Solution {
    public TreeNode lca(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> pathOne = new ArrayList<>();
        List<TreeNode> pathTwo = new ArrayList<>();
        
        if (!getPath(root, q, pathOne)){
        				return null;
        }

        if (!getPath(root, q, pathTwo)){
        				return null;
        }
        
        int idx = 0;
        while(idx < pathOne.size() && 
              idx < pathTwo.size() && 
              pathOne.get(idx) == pathTwo.get(idx)) {
              
              idx += 1;
        }
                
        return pathOne.get(idx - 1);
    }
    
    public boolean getPath(TreeNode curNode, TreeNode targetNode, List<TreeNode> path) {
        if (curNode == targetNode) {
            return true;
        }
    
        path.add(curNode);
        
        for(TreeNode nextNode: curNode.childNodes) {
            if (getPath(nextNode, targetNode, path)) {
                return true;
            }
        }
        
        path.remove(path.size() - 1);
        
        return false;
    }
}
```
{% endtab %}

{% tab title="BT\_child\_recursive" %}
* 왼쪽 오른쪽 체크!
* Time : $$O(N)$$, Space: $$O(N)$$

```java
// Binary Tree with child

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        
        if (root.val == p.val || root.val == q.val) {
            return root;
        }
        
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        
        if (left != null && right != null) {
            return root;
        }
        
        if (left != null && right == null) {
            return left;
        }
        
        if (left == null && right != null) {
            return right;
        }
        
        return null;
    }
}
```
{% endtab %}

{% tab title="N-ary\_child\_recursive" %}
* 기본적으로 BT와 같
* tree안에 p, q가 둘 다 있는 것을 가정함.
* 세가지 케이스 체크
  * n개의 자식 중 2개가 ok
  * 1개가 ok
  * 아무고토 음슴... 

```java
// N-ary Tree with child

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        
        if (root.val == p.val || root.val == q.val) {
            return root;
        }
        
        int count = 0;
        TreeNode oneSideFind = null;
        
        for(TreeNode next: root.childNodes) {
            TreeNode find = lowestCommonAncestor(next, p, q);
            if (find != null) {
                count += 1;
                oneSideFind = find;
            }
        }
        
        if (count == 2) {
            return root;
        }
        
        return oneSideFind;
    }
}
```
{% endtab %}
{% endtabs %}



![](https://gblobscdn.gitbook.com/assets%2F-MaZ4vjbXZuX4j8LcZDI%2F-MaiLme1HvbXb6sxnGeu%2F-Man9bnM6gU5SjCRUQGi%2Fimage.png?alt=media&token=eb3c4b0e-388f-433e-a853-9da6b8b5c426)

## Ref

{% embed url="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/" %}



## Tag

`#left-right` `#tree` `#lca`

