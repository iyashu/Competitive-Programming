import sys
for i in xrange(input()):
    t=sys.stdin.readline().split()
    k=set(list(t[::-1]))
    sys.stdout.write(str(len(k))+"\n")
