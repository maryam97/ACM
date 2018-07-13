import re

while True:
    str = input().strip()
    if str == "*":
        break
    check = re.match(r'^[-+]?(\d(\.\d+)?)([eE][-+]?\d+)?$', str)
    if check:
        print('%s is legal.' % str)
    else:
        print('%s is illegal.' % str)