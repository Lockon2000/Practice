class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maximalProfit = 0
        currentPrice = 10_001
        for price in prices:
            if price <= currentPrice:
                currentPrice = price
            else:
                maximalProfit += price - currentPrice
                currentPrice = price
        
        return maximalProfit