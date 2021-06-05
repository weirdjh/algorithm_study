# Delete Node in a BST

## Problem

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference \(possibly updated\) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

## Example

![](../.gitbook/assets/image%20%2810%29.png)



.

.

.



## Idea

1. 세가지 케이스가 있음.
   1. no child
   2. one child
   3. two children
2. recursive하게 풀이

## Complexity

* Time : O\($$logN$$\)
* Space: O\($$1$$\)

## Code 

```java
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        
        // Search Key
        if (root.val > key) {
            root.left = deleteNode(root.left, key);
            return root;
        }
        if (root.val < key) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        
        // Found Key!
        if (root.left != null && root.right != null) {
            TreeNode changeNode = findLeftMostNode(root.right);
            root.val = changeNode.val;
            
            // change value is done.
            // Delete remained one.
            root.right = deleteNode(root.right, changeNode.val);
            return root;
        }
        
        else if (root.left != null) {
            return root.left;
        }
        else if (root.right != null) {
            return root.right;
        }
        
        return null;     
    }
    
    public TreeNode findLeftMostNode(TreeNode node) {
        while(node.left != null) {
            node = node.left;
        }
        return node;
    }
}
```

## Ref

{% embed url="https://leetcode.com/problems/delete-node-in-a-bst/" %}





## Tag

`#BST` `#Tree` `#recursion`

