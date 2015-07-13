#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    ll temp = t;
    while(t--)
    {
        ll r;
        scanf("%lld",&r);
        r = (r*r)<<2LL;
        double ans = (double)r + 0.25;
        printf("Case %lld: %.2lf\n",temp-t,ans);
    }
}
