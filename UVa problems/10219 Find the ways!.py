coef = []
def bin_coef(n, k):
    coef = [[0]*(n+1) for _ in range(n+1)]
    coef[n][0] = coef[n][n] = 1
    #if n > len(coef):
    coef[n][k] = bin_coef(n-1, k-1) + bin_coef(n-1, k)
    return coef[n][k]

while True:
    n, k = input().split()
    n, k = int(n), int(k)
    ans = bin_coef(n,k)
    print(len(ans))