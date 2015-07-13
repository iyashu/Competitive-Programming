#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll ar[100005];
ll ipow(ll a,ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)ans = ans*a % MOD;
        a = a*a % MOD;
        b>>=1;
    }
    return ans;
}
int main()
{
    ar[1] = 1;
    for(int i=2;i<100001;i++){ar[i] = 2*ar[i-1] + ipow(2,i-2);while(ar[i]>=MOD)ar[i]-=MOD;}
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",i,ar[n]);
    }
}
