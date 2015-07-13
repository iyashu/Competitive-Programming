#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,temp;
void solve()
{
    scanf("%lld",&n);
    ll ans = 0;
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&temp);
        if(temp!=1)flag = 1;
        ans = ans^temp;
    }
    if((flag && ans) || (!flag && n%2==0))
    {
        printf("John\n");
    }
    else
    {
        printf("Brother\n");
    }
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
