# Heap Construction & Heap Sort

## Problem

* Implement a MinHeap.
  * Build Heap
  * Insert
  * Remove
  * Peek

## Example

{% hint style="info" %}
`sample input`: 

```
nums = [48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41]
```

`sample output`: 

```
MinHeap(array)
buildHeap(array): [-5 2 6 7 8 8 24 391 24 56 12 24 48 41]
insert(76): [-5 2 6 7 8 8 24 391 24 56 12 24 48 41 76]
peek(): -5
remove(): [2 7 6 24 8 8 24 391 76 56 12 24 48 41]
remove(): [6 7 8 24 8 24 24 391 76 56 12 41 48]
```
{% endhint %}



.

.

.



## Idea

1. sift up / sift down
2. build heap -&gt; sift down : $$O(N)$$
3. insert -&gt; add & sift up: $$O(logN)$$
4. remove -&gt; sift down : $$O(logN)$$

## Code 

{% tabs %}
{% tab title="Heap" %}


```java
import java.util.*;

class Program {
  static class MinHeap {
    List<Integer> heap = new ArrayList<Integer>();

    public MinHeap(List<Integer> array) {
      heap = buildHeap(array);
    }

    public List<Integer> buildHeap(List<Integer> array) {
      for(int i=array.size() / 2; i>=0; i--) {
				siftDown(i, array.size()-1, array);
			}
      return array;
    }
    
    public int peek() {
      return heap.get(0);
    }

    public int remove() {
			int target = heap.get(0);
			
			heap.set(0, heap.get(heap.size()-1));
      siftDown(0, heap.size() - 1, heap);
			
			heap.remove(heap.size() - 1);
			
      return target;
    }

    public void insert(int value) {
      heap.add(value);
			siftUp(heap.size() - 1, heap);
    }

    public void siftDown(int currentIdx, int endIdx, List<Integer> heap) {
			
      int idx = currentIdx;
			
			while(2 * idx + 1 <= endIdx) {
				int leftChildIdx = 2*idx + 1;
				int rightChildIdx = 2*idx + 2;
				
				int leftChildValue = heap.get(leftChildIdx);
				int rightChildValue = (rightChildIdx <= endIdx)? heap.get(rightChildIdx) : Integer.MAX_VALUE;
				
				if (heap.get(idx) < leftChildValue && heap.get(idx) < rightChildValue) {
					break;	
				}
				
				int nextChild = (leftChildValue < rightChildValue)? leftChildIdx : rightChildIdx;
				swap(idx, nextChild, heap);
				
				idx = nextChild;
			}
    }

    public void siftUp(int currentIdx, List<Integer> heap) {
			int idx = currentIdx;
      while(idx >= 0) {
				int nextIdx = (idx - 1) / 2;
				if (heap.get(idx) >= heap.get(nextIdx)) {
					break;
				}
				swap(idx, nextIdx, heap);
				idx = nextIdx;
			}
    }
		
		public void swap(int i, int j, List<Integer> heap) {
			int tmp = heap.get(i);
			heap.set(i, heap.get(j));
			heap.set(j, tmp);
		}
  }
}

```
{% endtab %}

{% tab title="Heap Sort" %}
* if 오름차순 정렬
  * MaxHeap 생성
  * swap & siftDown \(끝 index를 줄여가면서... max값이 차례로 고정됨\)

```java
import java.util.*;

class Program {
  public static int[] heapSort(int[] array) {
	
		int[] heap = buildMaxHeap(array);
		
		for(int i=array.length-1; i>0; i--) {
			swap(0, i, heap);
			siftDown(0, i-1, heap);
		}
		
    return heap;
  }
	
	public static int[] buildMaxHeap(int[] array) {
		for(int i=array.length/2 - 1; i>=0; i--) {
			siftDown(i, array.length-1, array);
		}
		
		return array;
	}
	
	public static void siftDown(int startIdx, int endIdx, int[] heap) {
		int currentIdx = startIdx;
		
		while(currentIdx * 2 + 1 <= endIdx) {
			int leftChildIdx = currentIdx * 2 + 1;
			int rightChildIdx = currentIdx * 2 + 2;
			
			int leftChildValue = heap[leftChildIdx];
			int rightChildValue = (rightChildIdx <= endIdx) ? heap[rightChildIdx] : Integer.MIN_VALUE;
			
			if (heap[currentIdx] > leftChildValue && heap[currentIdx] > rightChildValue) {
				break;
			}
			
			int nextIdx = (leftChildValue > rightChildValue)? leftChildIdx : rightChildIdx;
			
			swap(currentIdx, nextIdx, heap);
			
			currentIdx = nextIdx;
		}
	}
	
	public static void swap(int i, int j, int[] array) {
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

```
{% endtab %}
{% endtabs %}



## Tag

`#heap`

