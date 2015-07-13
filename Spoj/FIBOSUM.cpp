#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll fibo(ll n)
{
   ll T[2][2] = {{0,1},{1,1}};
   ll ans[2][2] = {{1,0},{0,1}};
   ll temp[2][2] = {{0}};
   ll num = n-1;
   while(num)
   {
       if(num&1)
       {
           memset(temp,0,sizeof(temp));
           for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)
           temp[i][j] = temp[i][j] + (ans[i][k]*T[k][j]);
           for(int i=0;i<2;i++)for(int j=0;j<2;j++)ans[i][j] = (temp[i][j])%MOD;
       }
       memset(temp,0,sizeof(temp));
       for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)
       temp[i][j] = temp[i][j] + (T[i][k]*T[k][j]);
       for(int i=0;i<2;i++)for(int j=0;j<2;j++)T[i][j] = (temp[i][j])%MOD;
       num>>=1;
   }
   return (ans[0][0]+ans[0][1])%MOD;
}

void solve()
{
     ll n,m;
     scanf("%lld%lld",&n,&m);
     ll ans = (fibo(m+2)-fibo(n+1)+MOD)%MOD;
     printf("%lld\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}
