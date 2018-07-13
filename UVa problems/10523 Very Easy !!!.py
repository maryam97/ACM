"""
while(True):
    try:
        n , a = input().split()
        ans = 0
        for i in range(1,int(n)+1):
            ans += (i*(pow(int(a),i)))
        print(int(ans))
    except EOFError:
        break
"""