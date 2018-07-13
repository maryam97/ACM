def gcd(a ,b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

while(True):
    a = input().split()
    if a[0] == "0":
        break
    vec = []
    for i in range (1,len(a)-1):
        num = int(a[i])
        vec.append(num - int(a[0]))

    ans = vec[0]
    for i in range(1 , len(vec)):
        ans = gcd(ans, vec[i])
    print(abs(ans))
