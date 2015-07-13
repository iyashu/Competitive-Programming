#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[101][101][2];
void solve()
{
    ll num,n,k;
    scanf("%lld%lld%lld",&num,&n,&k);
    ll temp = dp[n][k][0] + dp[n][k][1];
    printf("%lld %lld\n",num,temp);
}
int main()
{
    int t;
    scanf("%d",&t);
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    for(int i=2;i<101;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0] ;
            if(j-1>=0)dp[i][j][1]+= dp[i-1][j-1][1];
        }
    }
    while(t--)
    {
        solve();
    }
}
