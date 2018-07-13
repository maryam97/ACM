"""
n = int(input())
for i in range(n):
    a, b = input().split()
   # print (a," ", b)
    ar = a[::-1]
    br = b[::-1]
    ans = str(int(ar) + int(br))
    print(int(ans[::-1]))
"""