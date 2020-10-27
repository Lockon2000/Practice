"""
    URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
"""


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minimum_price_day = 0
        best_sell_day = 0
        best_buy_day = 0
        best_profit = 0

        for d in range(1, len(prices)):
            if prices[d] < prices[minimum_price_day]:
                minimum_price_day = d
            else:
                profit = prices[d] - prices[minimum_price_day]
                if profit > best_profit:
                    best_sell_day = d
                    best_buy_day = minimum_price_day
                    best_profit = profit

        return best_profit