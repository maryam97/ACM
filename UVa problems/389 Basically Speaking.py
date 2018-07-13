"""
def numTobase(n , b):
    if n == 0:
        return ['0']
    dig = []
    while n >= 1:
        dig.append(str(int(n%b)))
        if int(dig[-1]) > 9:
            dig[-1] = chr(55 + int(dig[-1]))
        n/=b
    return dig[::-1]

while(1):
    try:
        a,b,c = input().split()
        a = int(a,int(b))
        ans = numTobase(a, int(c))
        if(len(ans) > 7):
            print("%7s" %("ERROR"))
        else:
            print("%7s" %(''.join(ans)))
    except EOFError:
        break;
"""