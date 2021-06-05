# Max Points on a Line

## Problem

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane, return _the maximum number of points that lie on the same straight line_.

\(all points are unique!\)

## Example

{% hint style="info" %}
`sample input`: 

```text
points = [[1,1],[2,2],[3,3]]
```

`sample output`: 

```text
3
```
{% endhint %}



.

.

.



## Idea

1. y = a\*x + b
2. 한 점을 기준으로 \(b 고정\) -&gt; 기울기가 같은 친구들을 찾자! \(HashMap\)
3. HashMap의 key로 기울기를 gcd로 나눠줘야함.
   1. 기울기가 0 / 무한 인경우 주의할 것!
   2. points 개수가 0개, 1개일 경우 주의!

## Complexity

* Time : O\($$N^2$$\)
* Space: O\($$N$$\)

## Code 

```java
class Solution {
    public int maxPoints(int[][] points) {
        if (points.length < 2) {
            return points.length;
        }
        
        int max = 0;
        for(int i=0; i<points.length; i++) {
            
            // One point is fixed!
            // just compare slope!
            int[] p1 = points[i];
            
            Map<String, Integer> map = new HashMap<>();
            
            for(int j=i+1; j<points.length; j++) {
                int[] p2 = points[j];
                
                String key = findSlopeKey(p1, p2);
                map.put(key, map.getOrDefault(key, 1) + 1);
            }
            
            for(Integer value: map.values()){
                max = Math.max(max, value);
            }
        }
		
        return max;
    }
    
    public String findSlopeKey(int[] p1, int[] p2) {
        int numerator = p1[0] - p2[0];
        int denominator = p1[1] - p2[1];
        
        if (numerator == 0) {
            return String.format("%d:%d", 0, 0);
        }
        
        if (denominator == 0) {
            return String.format("%d:%d", 1, 0);
        }
        
        int sign = ((numerator > 0) ^ (denominator > 0)) ? -1 : 1;
        
        int gcd = gcd(Math.abs(numerator), Math.abs(denominator));
        
        return String.format("%d:%d", sign*(Math.abs(numerator) / gcd), Math.abs(denominator) / gcd);
    }

    // !!! Please Memorize this !!!
    public int gcd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
    }
}
```

## Ref

{% embed url="https://leetcode.com/problems/max-points-on-a-line/" %}



## Tag

`#HashMap` `#gcd`

