# Two-Edge-Connected Graph

## Problem

Find if graph is two-edge-connected.

## Example

{% hint style="info" %}
`sample input`:   
edges = \[  
    \[1, 2, 5\],  
    \[0, 2\],  
    \[0, 1, 3\],  
    \[2, 4, 5\],  
    \[3, 5\],  
    \[0, 3, 4\],  
\]

`sample output`:   
true
{% endhint %}

.

.

.



## Idea

* High-Graph Connectivity

![](../.gitbook/assets/image%20%281%29.png)

* Find `Bridge` in graph + Check if all connected
* Bridge 찾기!
  * Parent가 아닌 Ancestor로의 back edge가 존재하지 않는다면!?
  * = discovery time을 줄여줄 친구가 없다?
  * = minimum discovery time이 업데이트가 안됐다?

## Complexity

* Time : O\(V+E\)
* Space: O\(V\)

## Code

```java
import java.util.*;

class Program {
  public boolean twoEdgeConnectedGraph(int[][] edges) {
	
		boolean[] visited = new boolean[edges.length];
    Arrays.fill(visited, false);
    
    int[] discoveryTimes = new int[edges.length];
    int[] minDiscoveryTimes = new int[edges.length];
    
    int[] prevNodes = new int[edges.length];
		Arrays.fill(prevNodes, -1);

    for(int i=0; i<edges.length; i++) {
      if (visited[i]) {
        continue;
      }
      
      dfs(i, 0, edges, prevNodes, visited, discoveryTimes, minDiscoveryTimes);
    }
		
		// just One Node
		if (edges.length <= 1) {
			return true;
		}
    
    for(int i=0; i<edges.length; i++) {
      int prev = prevNodes[i];
			
			//	just one node apart...
			if (prev == -1 && edges[i].length == 0) {
				return false;
			}
			
			// found bridge! ... not two-edge-connected!
      if (prev != -1 && discoveryTimes[i] == minDiscoveryTimes[i]) {
        return false;
      }
    }  

    return true;
  }
  
  public void dfs(int curNode, int discoveryTime, int[][] edges, int[] prevNodes, 
                  boolean[] visited, int[] discoveryTimes, int[] minDiscoveryTimes) {

    visited[curNode] = true;
      
    discoveryTimes[curNode] = discoveryTime;
    minDiscoveryTimes[curNode] = discoveryTime;
  
    for(int nextNode: edges[curNode]) {
      // visit next node
      if (!visited[nextNode]) {
        prevNodes[nextNode] = curNode;

        dfs(nextNode, discoveryTime + 1, edges, prevNodes, visited, discoveryTimes, minDiscoveryTimes);      
        minDiscoveryTimes[curNode] = Math.min(minDiscoveryTimes[curNode], minDiscoveryTimes[nextNode]);
      }
      
      // next node is ancestor
      else if (prevNodes[curNode] != nextNode) {
        minDiscoveryTimes[curNode] = Math.min(minDiscoveryTimes[curNode], discoveryTimes[nextNode]);
      }   
    }
  }
}
```

## Ref

{% embed url="https://www.cs.umd.edu/class/fall2017/cmsc451-0101/Lects/lect04-edge-connectivity.pdf" %}



## Tag

`#graph` `#back-edge` `#bridge` `#dfs`

