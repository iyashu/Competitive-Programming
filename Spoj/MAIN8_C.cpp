#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ar[50005];
ll n,k;
bool check(ll val)
{
    ll temp =n;
    ll K = k;
    if(val==0)return true;
    int i =0;
    while(i<n && ar[i]>=val)
    {
        if(K<=0)return true;
        K-=(ar[i++]/val);
    }
    if(K<=0)return true;
    return false;
}
void solve()
{
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++)scanf("%lld",&ar[i]);
    sort(ar,ar+n,greater<ll>());
    ll high = ar[0];
    ll low = 0;
    ll ans = 0;
    while(low<=high)
    {
        if(high-low<=1)
        {
            if(check(high))ans = high;
            else ans = low;
            break;
        }
        ll mid = low+high;
        mid>>=1;
        if(check(mid))low = mid;
        else high = mid-1;
    }
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
