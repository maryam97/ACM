tc = int(input())
for i in range(tc):
    try:
            s = input()
            e = eval(s)
            if '-' in s:
                print('ERROR')
            else:
                print(e)
    except:
        print('ERROR')
