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

* base idea: permutation
* how can I get minimum?

## Complexity

* Time : $$O(N)$$ 
* Space: $$O(N)$$

## Code 

{% tabs %}
{% tab title="Permutation" %}
* Find All possibles
* Eliminate some conditions
* Time : $$O(N^2 + a)$$ , Space: $$O(N^2 + a)$$ ... recursion stack size

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
* Time : $$O(N^2)$$ , Space: $$O(1)$$
  * We can reduce time complexity to $$O(N)$$ if using additional space.
  * Store array / map which stores the position of couples.
  * Modify array / map around swap.

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

{% tab title="Using position map" %}
* Make position map of each couple
* Time : $$O(N)$$ , Space: $$O(N)$$

```java
class Solution {
    public int minSwapsCouples(int[] row) {
        int[] positionMap = makePositionMap(row);
        
        int count = 0;
        for(int idx=0; idx<row.length; idx++) {
            
            if (idx % 2 == 0) {
                continue;
            }

            int current = row[idx - 1];
            int target = row[idx];
            
            if (positionMap[current] > idx) {
                count += 1;
            }

            swap(row, idx, positionMap[current]);
            updatePosition(positionMap, current, target, idx);
        }
        
        return count;
    }
    
    public int findPartner(int person) {
        if (person % 2 == 0) {
            return person + 1;
        }
        return person - 1;
    }
    
    // 2n-1 -> 2n-2
    // 2n-2 -> 2n-1
    // row: [1 5 0 3 2 4]
    // pos: [2 5 0 4 3 1]
    public int[] makePositionMap(int[] row) {
        int[] positionMap = new int[row.length];
        
        for(int i=0; i<row.length; i++) {
            int partner = findPartner(row[i]);
            
            positionMap[partner] = i;
        }
        
        return positionMap;
    }

    // [As-Is] A-1 B-2 x x x x x A-2 x x x B-1
    // current: A-1
    //  target: B-2
    //    idx : 1
    //
    // [To-Be] A-1 A-2 x x x x x B-2 x x x B-1
    public void updatePosition(int[] positionMap, int current, int target, int idx) {        
        positionMap[findPartner(target)] = positionMap[current];
        positionMap[current] = idx;
    }
    
    public void swap(int[] row, int i, int j) {
        int tmp = row[i];
        row[i] = row[j];
        row[j] = tmp;
    }
}
```
{% endtab %}

{% tab title="Union Find" %}
* 총 couple의 수, N개 만큼 vertex가 있다고 하자.
* 어떤 위치 2i, 2i+1 에 vertex u, vertex v 로 부터 한 개씩 위치해있다고 생각할 수 있음.
* 만약 vertex u, vertex v가 다른 커플이라면 -&gt; 두 개의 vertex 사이에는 edge가 필요함.
* 따라서 couple Vertex의 edge를 추가해주다보면? 
* 다음과 같이 connect 된 component들을 올바른 커플을 매칭하려면, 각 edge들을 끊어줘야함 \(swap이 필요함\)
* \[1,2,3,4,5,0,7,8,9,6\]
  * \(0,1\) -&gt; \(4,5\) -&gt; \(2,3\)
  * \(6,7\) -&gt; \(8,9\)
  * 총 3 개의 edge를 끊어줘야함.
*  Component C 에 있는 노드의 개수를 N, Component 총 개수를 k라고 할 때,
  * 끊어야하는 edge개수 = Sum\(Nk - 1\) = N - k

```java
class Solution {
    private class UF {
        private int[] parents;
        
        // count = component 개수
        public int count;
        UF(int n) {
            parents = new int[n];
            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
            count = n;
        }
        
        private int find(int i) {
            if (parents[i] == i) {
                return i;
            }
            parents[i] = find(parents[i]);
            return parents[i];
        }
        
        public void union(int i, int j) {
            int a = find(i);
            int b = find(j);
            if (a != b) {
                parents[a] = b;
                count--;
            }
        }
    }
    public int minSwapsCouples(int[] row) {
        int N = row.length/ 2;
        UF uf = new UF(N);
        for (int i = 0; i < N; i++) {
            int a = row[2*i];
            int b = row[2*i + 1];
            uf.union(a/2, b/2);
        }
        return N - uf.count;
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/couples-holding-hands/](https://leetcode.com/problems/couples-holding-hands/)



## Tag

`#cyclic-sort` `#union-find` `#greedy` `#index-map` 

