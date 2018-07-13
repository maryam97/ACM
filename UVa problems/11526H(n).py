import math
t = int(input())

for i in range(t):
    n = int(input())
    if not n: print(0)
    elif n == 1: print(1)
    elif n == 2: print(3)
    elif n == 3: print(5)
    else:
        sum = num = n
        pre = 0
        i = 2
        mul = 0
        till = int(math.sqrt(n))
        #print(till)
        for tt in range(till):
            pre = n // (i)
            i = i + 1
            num = num - pre
            sum = sum + (num * (++mul))
            sum = sum + pre
            num = pre

        sum = sum + ((mul + 1) * (pre - till - 1))
        print(int(sum))



