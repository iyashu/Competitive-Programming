#include<iostream>
#include<stdio.h>
using namespace std;
#define maxn 1000000
long long ans[maxn+2];
void sieve()
{
     int cnt=0;
     for (int i = 1; i <= maxn / 2; i++) {
   for (int j = i + i; j < maxn; j += i) {
      cnt++;
      ans[j] += i;
   }
}
ans[1] = 0;
for (int i = 3; i < maxn; i++)
   ans[i] += ans[i-1];
}
int main()
{
    int t;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);      
    }
}
