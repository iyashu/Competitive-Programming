from math import *
import sys
N, W, T, R = map(long, sys.stdin.readline().split())
t= factorial(N)/(factorial(W)*factorial(T)*factorial(R))
t=t%1000000007
print t
