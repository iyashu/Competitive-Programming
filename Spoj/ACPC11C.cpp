#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffffffffffffLL
using namespace std;
ll ar[100005];
ll sum[100005] = {0};
void solve()
{
    ll n;
    scanf("%lld",&n);
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++)scanf("%lld",&ar[i]),sum[i+1]=sum[i]+ar[i];
    ll ans = INF;
    for(int i=0;i<n;i++) ans = min(ans,min(sum[i]*2+ sum[n]-sum[i+1],sum[i]+2*(sum[n]-sum[i+1])));
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
