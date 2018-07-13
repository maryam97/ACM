import bisect
fib = [1, 2]

for i in range(2, 110):
    fib.append(fib[i-1] + fib[i-2])


tc = 0
while True:
    try:
        if tc:
            input()
        a = input()
        b = input()
        if tc:
            print("")
        tc += 1
    except:
        break

    a = a[::-1]
    b = b[::-1]
    aa = 0
    bb = 0
    for i in range(len(a)):
        aa += ((int(a[i]))*fib[i])

    for i in range(len(b)):
        bb += ((int(b[i]))*fib[i])
    ans = aa + bb
    #print(ans)
    s = ""

    #for f in fib[::-1]:
        #print("f %d" %f)
    #    if f <= ans:
     #       ans -= f
     #       s += '1'
      #  elif len(s):
       #     s += '0'
    #if not s:
     #   s = '0'
    #print(s)
    low = bisect.bisect(fib,ans,lo=0,hi=len(fib))
    if fib[low]!= ans :
        low= low-1
    #print("low %d ," %(low))
    #print (" fib %d"  %fib[low])
    for i in range(low, -1, -1):
        if ans - fib[i] >= 0:
            ans -= fib[i]
            s += '1'
        else:
            s += '0'
    if not s:
        s = '0'
    print(s)
