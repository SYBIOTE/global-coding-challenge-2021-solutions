from itertools import accumulate
import math
import os
import random
import re
import sys

def portfolio_profit_maximisation(maxSum, a, b):
    a = list(reversed(a))
    b = list(reversed(b))
    stack = []
    total, score = 0, 0

    while a:
        item = a.pop()
        if (total + item) <= maxSum:
            total += item
            score += 1
            stack.append(item)
        else: break
    
    maxScore = score

    while b:
        
        item = b.pop()
        total += item
        score += 1
        while total > maxSum and stack:
            total -= stack.pop()
            score -= 1
        if total <= maxSum and score > maxScore: maxScore = score
    
    return maxScore 
    # Write your code here

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    maxSum = int(first_multiple_input[2])

    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))
    result = portfolio_profit_maximisation(maxSum, a, b)

    print(result)