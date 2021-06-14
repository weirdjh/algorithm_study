# Path Sum

## Problem

Given the `root` of a binary tree and an integer `targetSum`, return _the number of paths where the sum of the values along the path equals_ `targetSum`.

The path does not need to start or end at the root or a leaf, but it must go downwards \(i.e., traveling only from parent nodes to child nodes\).

## Example

![](../.gitbook/assets/image%20%2818%29.png)

```text
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3

Explanation: The paths that sum to 8 are shown.
```

.

.

.



## Idea

* Recursive \(Choose or Not\)
* Presum

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(1)$$

## Code 

{% tabs %}
{% tab title="recursive" %}


```java
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return 0;
        }
        
        // Choose
        int count = findPath(root, 0, targetSum);
        
        // Or not
        if (root.left != null) {
            count += pathSum(root.left, targetSum);
        }
        
        if (root.right != null) {
            count += pathSum(root.right, targetSum);
        }
        
        return count;
    }
    
    public int findPath(TreeNode node, int sum, int targetSum) {
        int count = 0;
        
        if (sum + node.val == targetSum) {
            count += 1;
        }
        
        if (node.left != null) {
            count += findPath(node.left, sum + node.val, targetSum);
        }
        
        if (node.right != null) {
            count += findPath(node.right, sum + node.val, targetSum);
        }
        
        return count;
    }
}
```
{% endtab %}

{% tab title="Presum" %}


```java
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return 0;
        }
        
        Map<Integer, Integer> presum = new HashMap<>();
        presum.put(0, 1);
        
        return pathSum(root, 0, targetSum, presum);
    }
    
    public int pathSum(TreeNode node, int sum, int targetSum, Map<Integer, Integer> presum) {
        
        sum += node.val;
        
        int count = 0;
        
        if (presum.containsKey(sum - targetSum)) {
            count += presum.getOrDefault(sum - targetSum, 0);    
        }
        
        presum.put(sum, presum.getOrDefault(sum, 0) + 1);
        
        if (node.left != null) {
            count += pathSum(node.left, sum, targetSum, presum);
        }
        
        if (node.right != null) {
            count += pathSum(node.right, sum, targetSum, presum);
        }
        
        presum.put(sum, presum.getOrDefault(sum, 1) - 1);
        
        return count;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/path-sum-iii/](https://leetcode.com/problems/path-sum-iii/)

## Tag

`#dfs` `#presum` `#hashmap` `#path` `#graph` 

