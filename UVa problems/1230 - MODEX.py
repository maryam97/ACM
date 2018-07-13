import math

tc = int(input())
for t in range(tc):
    x, y, n = input().split()
    x , y, n = int(x), int(y), int(n)

    print(pow(x,y,n))
zero = input()