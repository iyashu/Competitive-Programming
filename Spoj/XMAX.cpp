#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
// Gaussian Elimination
ll ar[100005];
int main()
{
    ll n,temp;
    scanf("%llu",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%llu",&ar[i]);
    }
    sort(ar,ar+n,greater<ll>());
    long long pos = 63;
    while((ar[0]&(1ULL<<pos))==0)pos--;
    for(int i=0;pos>=0;--pos)
    {
        ll t = i;
        temp = 1ULL<<pos;
        while(t<n && ((ar[t]&temp)==0))t++;
        if(t>=n)continue;
        swap(ar[t],ar[i]);
        for(int j=0;j<n;j++)
        {
            if(j!=i && ((ar[j]&temp)!=0))ar[j] = ar[j]^ar[i];
        }
        i++;
    }
    ll ans = 0;
    for(int i=0;i<n;i++)ans^=ar[i];
    printf("%lld\n",ans);
}
