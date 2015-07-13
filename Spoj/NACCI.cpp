#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll long long
using namespace std;

ll cal(ll n,ll num,ll mod)
{
    ll T[n][n];
    ll ans[n][n];
    memset(T,0,sizeof(T));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n-1;i++)
            T[i][i+1] =1;
    for(int i=0;i<n;i++)
    {
        T[n-1][i] = 1;
        ans[i][i] = 1;
    }
    ll temp[n][n];
    while(num)
    {
        if(num&1)
        {
            memset(temp,0,sizeof(temp));
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    for(int k=0;k<n;k++)
                        temp[i][j] = temp[i][j] + ans[i][k]*T[k][j];
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    ans[i][j] = temp[i][j]%mod;
        }
        memset(temp,0,sizeof(temp));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)
            temp[i][j] = temp[i][j] + T[i][k]*T[k][j];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
            T[i][j] = temp[i][j]%mod;
        num>>=1;
    }
    ll me = 0;
    for(int i=0;i<n;i++)
        me+=(ans[0][i]*i);
    return me%mod;
}

void solve()
{
    ll n,k,l;
    scanf("%lld%lld%lld",&n,&k,&l);
    k = powl(10,k);
    printf("%lld\n",cal(n,l,k));
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
