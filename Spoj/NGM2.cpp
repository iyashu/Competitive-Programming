#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define gcd __gcd
using namespace std;
vector<ll> v;
int main()
{
    ll n,k,temp;
    scanf("%lld%lld",&n,&k);
    int flag = 1;
    for(int i=0;i<k;i++)
    {
        scanf("%lld",&temp);
        if(temp<0)temp = -temp;
        else if(temp==0)
        {flag = 1;continue;}
        v.pb(temp);
    }
    k = v.size();
    temp = 1LL<<k;
    ll ans = n;
    for(ll i=1;i<temp;i++)
    {
        int cnt = __builtin_popcount(i);
        ll mul = 1LL;
        for(ll j=0;j<k;j++)
        {
            if(i&(1LL<<j))
                mul = (mul*v[j])/(gcd(mul,v[j]));
        }
        //cout<<i<<" "<<mul<<endl;
        if(cnt&1)ans-=(n/mul);
        else ans+=(n/mul);
    }
    printf("%lld\n",ans);

}
