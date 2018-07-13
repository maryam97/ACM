fact = [1,1]

for i in range(2, 1001):
    fact.append(i*fact[i-1])

while True:
    try:
        a = int(input())
        print("%d!\n%d" %(a, fact[a]))
    except EOFError:
        break