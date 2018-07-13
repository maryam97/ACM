triangle = [0,]
d = 1
for i in range(1,10**6//2):
    triangle.append(triangle[-1] + d)
    triangle.append(triangle[-1] + d)
    d += 1
for i in range(1,len(triangle)):
    triangle[i] += triangle[i-1]

while True:
    a = int(input())
    if a < 3:
        break
    print(triangle[a - 3])