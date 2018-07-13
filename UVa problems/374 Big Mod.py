tc = 0
while True:
    try:
        if tc:
            input()
        b, p, m = int(input()), int(input()), int(input())
        tc += 1

    except:
        break

    print(pow(b, p, m))