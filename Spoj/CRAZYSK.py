t = int(raw_input())
for i in range(t):
    a, b = [int(x) for x in raw_input().split()]
    c = int(a)
    while (c-b)>=0:
        a+=(c/b)
        c=(c/b)+(c%b)
    print a
    
