#!/usr/bin/python3
"""
Module for making change with minimum coins
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins: List of coin denominations (positive integers)
        total: Target amount to reach

    Returns:
        Fewest number of coins needed, or -1 if impossible
    """
    if total <= 0:
        return 0

    if not coins:
        return -1

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
