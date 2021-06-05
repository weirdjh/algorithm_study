# Detect Cycle in a Directed Graph

## Problem

Given a directed graph, check whether the graph contains a cycle or not.

## Example

{% hint style="info" %}
`sample input`:   
0 : \[1,3\]  
1 : \[2,3,4\]  
2 : \[0\]  
3 : \[\]  
4 : \[2,5\]  
5 : \[\]

`sample output`:   
true \(0 -&gt; 1 -&gt; 2 -&gt; 0, ... \)
{% endhint %}

.

.

.



## Idea

* Back edge\(자기자신 / 자기 부모 포함\)가 존재하는 지 찾는 a
* 기본적으로 DFS, 현재 탐색 중인 상태를 저장해함.
* 다음 노드를 봤는데 탐색중인 상태야? ... 이미 cycle이 찾아진 상황임.

\(1\) recursion stack을 이용하여 현재 탐색중인 그래프 저장  
\(2\) tri-color algorithm \(0: 방문 x / 1: 탐색 중 / 2 : 탐색 완\)

## Complexity

* Time : O\(V + E\)
* Space: O\(V\)

## Code

{% tabs %}
{% tab title="Find Backedge" %}


```java
import java.util.*;

class Program {

  public boolean cycleInGraph(int[][] edges) {
  	boolean[] visited = new boolean[edges.length];
		boolean[] visiting = new boolean[edges.length];
		Arrays.fill(visited, false);
		Arrays.fill(visiting, false);

		for(int i=0; i<edges.length; i++) {
			if (visited[i]) {
				continue;
			}
			if (findCycle(i, edges, visited, visiting)) {
				return true;
			}
		}
		
		return false;
  }
	
	public boolean cycleInGraph(int curNode, int[][] edges, boolean[] visited, boolean[] visiting) {
		visited[curNode] = true;
		
		// 방문 시작!
		visiting[curNode] = true;
		for(int destNode : edges[curNode]) {
			// cycle이 이미 발견됨!?
			if (visiting[destNode]) {
				return true;
			}
			
			if (visited[destNode]) {
				continue;
			}
			
			if (cycleInGraph(destNode, edges, visited, visiting)) {
				return true;
			}
		}
		
		// 방문 !
		visiting[curNode] = false;
		return false;
	}
	
}

```
{% endtab %}

{% tab title="Tri-Color" %}


```java
import java.util.*;

class Program {

  public boolean cycleInGraph(int[][] edges) {
		int[] visited = new int[edges.length];
		
    for(int i=0; i<edges.length; i++) {
			if (visited[i] == 2) {
				continue;
			}
			
			if(cycleInGraph(edges, visited, i)){
				return true;
			}
		}
    return false;
  }
	
	public boolean cycleInGraph(int[][] edges, int[] visited, int current) {
		visited[current] = 1;
		
		for(int next: edges[current]) {
			if (visited[next] == 1) {
				return true;
			}
			if (visited[next] == 2) {
				continue;
			}
			
			if (cycleInGraph(edges, visited, next)){
				return true;
			}
		}
		
		visited[current] = 2;
		
		return false;
	}
}
```
{% endtab %}
{% endtabs %}

## Ref

{% embed url="https://www.geeksforgeeks.org/detect-cycle-in-a-graph/" %}



## Tag

`#graph` `#cycle` `#backedge` `#tri-color` `#dfs`

