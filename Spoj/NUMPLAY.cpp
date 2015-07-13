import sys
ans = [0,4]
p1 = 1
p3 = 1
p5 = 1
p7 = 1
for i in xrange(2,10001):
  n1 = p3
  n7 = p5
  n5 = p3 + p7
  n3 = p1 + p7
  p1,p3,p5,p7 = n1,n3,n5,n7
  temp = n1+n5 + n7 + n3
  ans.append(temp)
t = sys.stdin.readline()
t = int(t)
for i in range(t):
  n = int(sys.stdin.readline())
  sys.stdout.write(str(ans[n])+'\n')
