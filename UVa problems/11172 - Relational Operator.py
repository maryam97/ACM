#def main():
n = int(input())
for _ in range(n):
    s = input()
    a, b = [int(v) for v in s.split()]
    if a < b:
        print ("<")
    elif a > b:
        print (">")
    else:
        print ("=")
#if __name__ == '__main__':
 #   main()
