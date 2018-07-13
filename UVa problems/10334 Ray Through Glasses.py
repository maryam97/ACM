"""
fib = [];

def fibo():

    fib.append(1)
    fib.append(1)
    for i in range(2,1002):
        fib.append(fib[i-1] + fib[i-2])
    return

fibo()
while(True):
    try:
        n = int(input())
        print(fib[n+1])
    except EOFError:
        break;

"""