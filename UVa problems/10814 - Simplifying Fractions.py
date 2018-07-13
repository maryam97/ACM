def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

tc = int(input())
for t in range(tc):
    a, b = input().split('/')
    a = int(a)
    b = int(b)
    c = gcd(a, b)
    print("%d / %d" %((a//c),(b//c)))