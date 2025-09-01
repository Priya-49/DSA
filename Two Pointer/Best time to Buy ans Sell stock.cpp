/*
Problem: (Leetcode 121)
Best Time to Buy and Sell Stock

You are given an array 'prices' where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy and a different day in the future to sell.
Return the maximum profit you can achieve. If you cannot achieve any profit, return 0.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.

Approach:
1. Initialize minPrice to INT_MAX to track the minimum price seen so far.
2. Initialize maxProfit to 0.
3. Traverse the prices array:
   - Update minPrice if the current price is smaller.
   - Calculate potential profit = current price - minPrice.
   - Update maxProfit if this potential profit is greater.
4. Return maxProfit.

Time Complexity: O(n) - single traversal of the array.
Space Complexity: O(1) - constant extra space used.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int j = 0; j < prices.size(); j++) {
            minPrice = min(minPrice, prices[j]);
            maxProfit = max(maxProfit, prices[j] - minPrice);
        }
        return maxProfit;
    }
};

