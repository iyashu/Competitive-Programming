#include <bits/stdc++.h>
typedef long long ll;
#define MOD 100000007
using namespace std;
ll dp[1025][1025];
int h[1025];
int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        ll n,m,temp;
        scanf("%lld%lld",&n,&m);
        //memset(dp,0,sizeof(dp));
        memset(h,0,sizeof(h));
        dp[0][0] = 1;
        ll maxi = -1;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&temp);
            for(int j=0;j<1024;j++)
            {
                dp[i][j] = (dp[i-1][j] + dp[i-1][temp^j])-MOD;
                if(dp[i][j]<0)dp[i][j]+=MOD;
            }
        }
        ll ans = 0;
        for(int i=0;i<m;i++)scanf("%lld",&temp),h[temp] = 1;
        for(int i=0;i<=1024;i++)
        {
            if(!h[i])ans+=dp[n][i];
        }
        printf("Case %d: %lld\n",tt,ans%MOD);
        for(int i=0;i<=n;i++)for(int j=0;j<=maxi;j++)dp[i][j] = 0;
    }
}
