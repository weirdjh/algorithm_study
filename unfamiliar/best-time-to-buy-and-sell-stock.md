# Best Time to Buy and Sell Stock

## Problem

 You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

* maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.
* Find the maximum profit you can achieve. You may complete as many transactions as you like
* Find the maximum profit you can achieve. You may complete at most `k` transactions.
* After you sell your stock, you cannot buy stock on the next day \(i.e., cooldown one day\).
* Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.



## 

.

.



## Idea

* Finite State Machine



## Code 

{% tabs %}
{% tab title="infinite case" %}
```java
//   buy   sell
// s0 -> s1 -> s2
//  ->s0  ->s1
//   rest  rest

class Solution {
    public int maxProfit(int[] prices, int fee) {
    
        // These arrays can be replace by variables
        int[] s0 = new int[prices.length];
        int[] s1 = new int[prices.length];
        
        s0[0] = 0;
        s1[0] = -prices[0];
        
        for(int i=1; i<prices.length; i++) {
            s0[i] = Math.max(s0[i-1], s1[i-1] + prices[i] - fee);
            s1[i] = Math.max(s1[i-1], s0[i-1] - prices[i]);
        }
        
        return Math.max(s0[prices.length-1], s1[prices.length-1]);
    }
}
```
{% endtab %}

{% tab title="Atmost K case" %}
```java
//   buy   sell
// s0 -> s1 -> s2
//  ->s0  ->s1
//   rest  rest

public class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices.length <= 1) {
		    return 0;
        }
        
        int[][] hold = new int[k+1][prices.length];
        int[][] unhold = new int[k+1][prices.length];
        
        hold[0][0] = -prices[0];
        
        // initialize first row of "hold" state
        for(int j=1; j<prices.length; j++) {
            hold[0][j] = Math.max(hold[0][j-1], -prices[j]);
        }
        
        // initialize first column of "hold" state
        for(int i=1; i<=k; i++) {
            hold[i][0] = -prices[0];
        }
        
        for(int i=1; i<=k; i++){
            for(int j=1; j<prices.length; j++){
                unhold[i][j] = Math.max(unhold[i][j-1], hold[i-1][j-1] + prices[j]);
                hold[i][j] = Math.max(hold[i][j-1], unhold[i][j-1] - prices[j]);
            }
        }
        return Math.max(hold[k][prices.length-1], unhold[k][prices.length-1]);
    }
}
```
{% endtab %}
{% endtabs %}

## Ref

* [https://leetcode.com/problems/best-time-to-buy-and-sell-stock/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
* [https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
* [https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
* [https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
* [https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## Tag

`#buy-and-sell` `#dp` `#finite-state-machine`

