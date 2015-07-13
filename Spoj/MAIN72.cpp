#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int flag[100005];
int ar[101];
ll W[101][100001];
void solve()
{
    ll n,temp;
    scanf("%lld",&n);
    ll sum = 0;
    ll ans = 0;
    int j = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&temp);
        if(!temp)continue;
        ar[j++] = temp;
        sum+=temp;
    }
    n = j;
    for(int i=0;i<=n;i++)W[i][0] = 1;
    for(int i=1;i<=sum;i++)W[0][i] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            W[i][j] = W[i-1][j];
            if(j>=ar[i-1])W[i][j]|=W[i-1][j-ar[i-1]];
        }
    }
    for(int i=1;i<=sum;i++)if(W[n][i])ans+=i;
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
