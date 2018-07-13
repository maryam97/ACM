while(True):
    try:
        a, b = input().split()

    except EOFError:
        break
    baseA, baseB = [], []
    for i in range(2, 37):
        try:
            baseA.append((i,int(a,i)))
        except ValueError:
            pass
    for i in range(2, 37):
        try:
            baseB.append((i,int(b,i)))
        except ValueError:
            pass
    ans = []
    for i in baseA:
        for j in baseB:
            if(i[1] == j[1]):
                ans = i[0], j[0]
                break
        if len(ans) != 0:
            break
    if len(ans) == 0:
        print("%s is not equal to %s in any base 2..36" %(a, b))
    else:
        print("%s (base %d) = %s (base %d)" %(a, ans[0], b, ans[1]))