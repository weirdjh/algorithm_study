# Couples Holding Hands

## Problem

* N Couples sit randomly in 2N seats arranged in a row.
* Couple could be denoted as a pair of \(2k-2, 2k-1\) where 0 &lt; k &lt;=N
* Find minimum number of swaps so that every couple is sitting side by side.

## Example

```text
Input: row = [0, 2, 1, 3]
Output: 1

Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
```

.

.

.



## Idea

* permutation \(+ how can I get minimum?\)

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(1)$$ .... use existing array

## Code 

{% tabs %}
{% tab title="Permutation" %}
* Find All possibles
* Eliminate some conditions
* Time : $$O(N^2 + a)$$ , Space: $$O(N^2 + a)$$ 

```java
// [0,4,3,1,2,5]
class Solution {
    public int minSwapsCouples(int[] row) {
    
        // start index could be start from 1
        return minSwapsCouples(row, 1, 0);
    }
    
    public int minSwapsCouples(int[] row, int idx, int count) {
        if (idx == row.length) {
            return count;
        }
        
        int min = Integer.MAX_VALUE;
        
        for(int i=idx; i<row.length; i++) {
            
            swap(row, idx, i);
            
            // row [0,idx] is fixed
            if (idx >= 1 && (idx % 2 == 1 && !checkRightCouple(row, idx))) {
                swap(row, idx, i);    
                continue;
            }
            
            // Change nothing is the best case
            if (i == idx) {
                int currentMin = minSwapsCouples(row, idx+1, count);
                swap(row, idx, i);        
                
                return currentMin;
            }
                
            int currentMin = minSwapsCouples(row, idx+1, count+1);
            
            min = Math.min(min, currentMin);
            
            swap(row, idx, i);
        }
        
        return min;
    }

    // 0 1 (o)
    // 1 2 (x)
    public boolean checkRightCouple(int[] row, int i) {
        // Not a couple
        if (Math.abs(row[i] - row[i-1]) != 1) {
            return false;    
        }
        
        if (Math.min(row[i], row[i-1]) % 2 != 0) {
            return false;
        }
        
        return true;
    }
    
    public void swap(int[] row, int i, int j) {
        int tmp = row[i];
        row[i] = row[j];
        row[j] = tmp;
    }
}
```
{% endtab %}

{% tab title="Simple Search And Swap" %}
* Same Logic with first solution \(`Permutation`\)
* Idea : No change if possible \(idx % 2 == 0\)
* Time : $$O(N^2)$$ , Space: $$O(N^2)$$

```java
class Solution {
    public int minSwapsCouples(int[] row) {
     
        int count = 0;
        for(int idx=0; idx<row.length; idx++) {
            
            if (idx % 2 == 0) {
                continue;
            }

            int coupleIdx = findCoupleIndex(row, row[idx-1], idx);

            swap(row, idx, coupleIdx);
            
            if (coupleIdx != idx) {
                count += 1;   
            }
        }
        
        return count;
    }

    // 0 1 (o)
    // 1 2 (x)
    public int findCoupleIndex(int[] row, int target, int idx) {
        
        int coupleIdx = -1;
        for(int i=idx; i<row.length; i++) {
            if (Math.abs(row[i] - target) != 1) {
                continue;
            }

            if (Math.min(row[i], target) % 2 != 0) {
                continue;
            }
            
            coupleIdx = i;
        }
        
        return coupleIdx;
    }
    
    public void swap(int[] row, int i, int j) {
        int tmp = row[i];
        row[i] = row[j];
        row[j] = tmp;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/couples-holding-hands/](https://leetcode.com/problems/couples-holding-hands/)



## Tag

`#cyclic-sort` `#union-find` `#greedy` 

