
def sol(dice_left, score, x):
    if dice_left == 0:
        if score >= x: return 1
        else: return 0
    if memo[dice_left][score] != -1: return memo[dice_left][score]
    ans = 0
    for i in range(1, 7):
        ans += sol(dice_left - 1, score + i, x)
    memo[dice_left][score] = ans
    return ans


def gcd(a, b):
    if b == 0: return a
    else: return gcd(b, a % b)

while(True):
    n, x = input().split()
    n, x = int(n), int(x)
    if (not n) and (not x): break
    memo = [[-1] * 160 for i in range(26)]
    s = sol(n, 0, x)
    m = int(pow(6.0, n))
    g = gcd(s,m)
    if s == m: print(1)
    elif not s: print(0)
    else:print("%d/%d" %(s//g, m//g))