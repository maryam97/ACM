cat = [1]
a = 1
for n in range(1,301):
    a = (2 * ((2 * n) - 1))* cat[n - 1]
    a //= (n + 1)
    cat.append(a)
fact = [1,1]
for n in range(2,301):
    fact.append(fact[n-1]*n)

while(True):
    n = int(input())
    if n == 0:
        break
    print(cat[n] * fact[n])