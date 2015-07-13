#include <bits/stdc++.h>
#define MOD 314159
typedef long long ll;
using namespace std;
ll E[1000006];
ll O[1000006];
void solve()
{
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",E[n]);
}
int main()
{
    int t;
    scanf("%d",&t);
    O[1] = 1;
    E[1] = 9;
    for(int i=2;i<1000006;i++)
    {
        E[i] = E[i-1]*9 + O[i-1];
        O[i] = O[i-1]*9 + E[i-1];
        E[i] = E[i]%MOD;
        O[i] = O[i]%MOD;
    }
    while(t--)
    {
        solve();
    }
}
