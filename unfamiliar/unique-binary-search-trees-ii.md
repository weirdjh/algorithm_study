# Unique Binary Search Trees II

## Problem



 Given an integer `n`, return _all the structurally unique **BST'**s \(binary search trees\), which has exactly_ `n` _nodes of unique values from_ `1` _to_ `n`. Return the answer in **any order**.

\*\*\*\*

## 

![](../.gitbook/assets/image%20%2819%29.png)

.

.

.









## Idea

* Divide and conquer



## Code 

```java
class Solution {
    public List<TreeNode> generateTrees(int n) {
        
        return generateTrees(1, n);
    }
    
    public List<TreeNode> generateTrees(int s, int e) {
        List<TreeNode> ans = new ArrayList<>();
        
        if (s > e) {
            ans.add(null);
            return ans;
        }
        
        for(int i=s; i<=e; i++) {
            List<TreeNode> lefts = generateTrees(s, i-1);
            List<TreeNode> rights = generateTrees(i+1, e);
            
            for(TreeNode left: lefts) {
                for(TreeNode right: rights) {
                    TreeNode node = new TreeNode(i);
                    node.left = left;
                    node.right = right;
                    
                    ans.add(node);
                }
            }
        }
        
        return ans;
    }
    
   
}
```

## Ref

* [https://leetcode.com/problems/unique-binary-search-trees-ii/](https://leetcode.com/problems/unique-binary-search-trees-ii/)

## Tag

`#binarySearchTree` `#divide-and-conquer`

