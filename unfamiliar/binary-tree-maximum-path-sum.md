# Binary Tree Maximum Path Sum

## Problem

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return _the maximum **path sum** of any path_.



## Example

{% hint style="info" %}
`sample output`: 42
{% endhint %}

![](../.gitbook/assets/image%20%284%29.png)

.

.

.



## Idea

* ending to current node / so far 

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(logN)$$ 

## Code 

{% tabs %}
{% tab title="max\_sum\_path" %}


```java
class Solution {
    public int maxPathSum(TreeNode root) {
	    if(root == null) {
				return 0;
			}
			
			return pathSum(root)[1];		
    }
	  
		// return: {
		// 	max sum of path ending here,  
		//	max sum of path so far,
		//}
		public static int[] pathSum(TreeNode node) {
			if (node == null) {
				return new int[] {0, Integer.MIN_VALUE};
			}
			
			int[] left = pathSum(node.left);
			int[] right = pathSum(node.right);
			
			return new int[] {
				node.val + findMax(0, left[0], right[0]),
				findMax(left[1], right[1], 
	              node.val + findMax(0, left[0], right[0]), 
	              node.val + left[0] + right[0]
	            )
			};
		}
		
		public static int findMax(int... values) {
			int max = Integer.MIN_VALUE;
			for(int value: values) {
				if (max < value) {
					max = value;
				}
			}
			return max;
		}
}
```
{% endtab %}

{% tab title="max\_diameter" %}
* Return max diameter of a Binary Tree
* The diameter of a binary tree is defined as the length of its longest path.

```java
class Solution {

  public int binaryTreeDiameter(TreeNode tree) {
    
		int[] res = binaryTreeDiameterHelper(tree);
		
		return res[1] - 1;
  }
	
	public int[] binaryTreeDiameterHelper(TreeNode tree) {
		if (tree == null) {
			return new int[] {0, 0};
		}
		
		int[] left = binaryTreeDiameterHelper(tree.left);
		int[] right = binaryTreeDiameterHelper(tree.right);
	
		int maxEnding = 1 + Math.max(left[0], right[0]);
		int maxSoFar = Math.max(1 + left[0] + right[0], 
														Math.max(left[1], right[1]));
		
		return new int[] {maxEnding, maxSoFar};
	}
}
```
{% endtab %}

{% tab title="max\_univalue\_path" %}
*  return _the length of the longest path, where each node in the path has the same value_. This path may or may not pass through the root.

```java
class Solution {
    public int longestUnivaluePath(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        return longestUnivaluePathHelper(root)[1] - 1;
    }
    
    // return: {endHere, soFar}
    public int[] longestUnivaluePathHelper(TreeNode node) {
        if (node == null) {
            return new int[] {0, 0};
        }
        
        int[] left = longestUnivaluePathHelper(node.left);
        int[] right = longestUnivaluePathHelper(node.right);
        
        int leftEndHere = 0;
        if(node.left != null && node.left.val == node.val) {
            leftEndHere += left[0];
        }
        
        int rightEndHere = 0;
        if(node.right != null && node.right.val == node.val) {
            rightEndHere += right[0];
        }
        
        int endHere = 1 + Math.max(leftEndHere, rightEndHere);
        
        int soFar = Math.max(
            1 + leftEndHere + rightEndHere, Math.max(left[1], right[1])
        );
        
        return new int[] {endHere, soFar};
    }
}
```
{% endtab %}
{% endtabs %}



## Ref

{% embed url="https://leetcode.com/problems/binary-tree-maximum-path-sum/" %}

{% embed url="https://leetcode.com/problems/diameter-of-binary-tree/" %}

{% embed url="https://leetcode.com/problems/longest-univalue-path/" %}



## Tag

`#binary_tree` `#dfs` `#kadane's algorithm`

