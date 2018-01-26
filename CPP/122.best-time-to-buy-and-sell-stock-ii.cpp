/*
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 *
 * algorithms
 * Easy (47.63%)
 * Total Accepted:    173.3K
 * Total Submissions: 363K
 * Testcase Example:  '[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at the
 * same time (ie, you must sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(prices.size()<2)return 0;
      int buy = prices[0];
      int profit = 0;
      int len = prices.size();
      int sell = 0;
      for(int i = 1;i<len;i++){
        if(prices[i]>prices[i-1]){
          sell = prices[i];
        }
        else{
          profit += sell-buy>0?(sell-buy):0;
          sell = 0;
          buy = prices[i];
        }
      }
      if(sell>buy){
        profit = profit+sell-buy;
      }
      return profit;
    }
};
