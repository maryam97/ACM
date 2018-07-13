"""
import math

n = int(input())
for i in range (1 , n+1):
    word = str(input())
    l = len(word)
    ans = math.factorial(l)
    for j in range (65, 92):
        ans //= math.factorial(word.count(chr(j)))
    print('Data set %d: %d' %(i , ans))
"""