def P(k):
    a = [6,2,4,8]
    if k<1:
        return 1
    else:
        return a[k%4]
def L(n):
    a = [1,1,2,6,4]
    if n<5:
        return a[n]
    else:
        return (P(n/5)*L(n/5)*L(n%5))%10
import sys,os
while 1:
    try:
        line=sys.stdin.readline()
        k=int(line)
    except:
        break
    print L(k)
