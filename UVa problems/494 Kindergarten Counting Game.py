import re
while True:
    try:
        ss = re.sub("[^a-zA-Z]", " ", input())
        print(len(ss.split()))
    except EOFError:
        break

