# Count Complete Tree Nodes

## Problem

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to [**Wikipedia**](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees), every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.

## Example

![](../.gitbook/assets/image%20%282%29.png)

.

.

.



## Idea

* 언제 left subtree / right subtree가 complete일까?

## Complexity

* Time : $$O((logN)^2)$$ 
* Space: $$O(logN)$$ 

## Code 

```java
// find height of left most node
// for both left subtree and right subtree

// 1. if (left heigth == right height)
//        : at least left subtree is complete
// 2. if (left height > right height)
//        : at least right subtree is complete

class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        int left = leftDepth(root.left);
        int right = leftDepth(root.right);
        
        if (left == right) {
            return 1 + ((1 << left) - 1) + countNodes(root.right);
        }
        if (left > right) {
            return 1 + ((1 << right) -1) + countNodes(root.left);
        }
        
        return -1;        
    }
    
    public int leftDepth(TreeNode node) {
        int count = 0;
        TreeNode curNode = node;
        while(curNode != null) {
            curNode = curNode.left;
            count += 1;
        }
        return count;
    }
}
```



## Ref

[https://leetcode.com/problems/count-complete-tree-nodes/](https://leetcode.com/problems/count-complete-tree-nodes/)

## Tag

`#tree` `#complete-binary-tree`

