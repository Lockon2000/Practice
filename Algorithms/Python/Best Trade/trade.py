# Here are three different implementations for algorithms that solve the best trade problem.
# trade_dp is of time complexity O(n) and similar space complexity.
# trade_kadane is of time complexity O(n) and space complexity O(1).
# trade_kadane_correct is of time complexity O(n) and space complexity O(1).
# NOTE: trade_kadane is not correct in this form as found in the book
# computer science distilled. As shown in the second example, the
# output of the trade_kadane algorithm is obviously incorrect.

def trade_dp(prices):
    B = [None for _ in range(len(prices))]
    B[0] = 0
    sell_day = 0
    best_profit = 0

    for n in range(1, len(prices)):
        if prices[n] < prices[B[n-1]]:
            B[n] = n
        else:
            B[n] = B[n-1]
        
        profit = prices[n] - prices[B[n]]
        if profit > best_profit:
            sell_day = n
            best_profit = profit

    return (sell_day, B[sell_day])


def trade_kadane(prices):
    sell_day = 0
    buy_day = 0
    best_profit = 0

    for s in range(1, len(prices)):
        if prices[s] < prices[buy_day]:
            b = s
        else:
            b = buy_day
        
        profit = prices[s] - prices[b]
        if profit > best_profit:
            sell_day = s
            buy_day = b
            best_profit = profit

    return (sell_day, buy_day)

def trade_kadane_correct(prices):
    minimum_price_day = 0   # You need to hold tab of the minimum price so far to be able to calculate correct profits
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
                                            
    return (best_sell_day, best_buy_day)


# Example 1
prices =  [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

print(f"{prices=}, {len(prices)=}")
print(f"{trade_dp(prices)=}")               # Output "(9, 0)"
print(f"{trade_kadane(prices)=}")           # Output "(9, 0)"
print(f"{trade_kadane_correct(prices)=}")   # Output "(9, 0)"

# Example 2
prices =  [3, 3, 1, 2, 5, 7, 11, 9]

print(f"{prices=}, {len(prices)=}")
print(f"{trade_dp(prices)=}")               # Output "(6, 2)"
print(f"{trade_kadane(prices)=}")           # Output "(6, 0)" WRONG!!!
print(f"{trade_kadane_correct(prices)=}")   # Output "(6, 2)" Correct again!

# Example 3
prices =  [3, 4, 40, 3, 1, 2, 5, 7, 11, 9]

print(f"{prices=}, {len(prices)=}")
print(f"{trade_dp(prices)=}")               # Output "(2, 0)"
print(f"{trade_kadane(prices)=}")           # Output "(2, 0)"
print(f"{trade_kadane_correct(prices)=}")   # Output "(2, 0)"
