#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;
ll MOD;
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
    ll n;
    scanf("%lld%lld",&n,&MOD);
    ll ans = fibo(n+2);
    ans-=1;
    ans<<=1;
    ans-=(n%MOD);
    while(ans<0)ans+=MOD;
    ans = ans%MOD;
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
