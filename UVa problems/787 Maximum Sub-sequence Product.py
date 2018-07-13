while(True):
    lst=[]
    try:
        for i in input().split():
            if int(i) != -999999: lst.append(int(i))
            else :
                ans = -100000000000000000
                for l in range(len(lst)):
                    s = 1
                    for x in range(l, -1, -1):
                        s *= lst[x]
                        if (ans < s): ans = s
                        if not s : break
                print (ans)
                break

    except: break