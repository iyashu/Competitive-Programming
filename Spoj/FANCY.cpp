#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char st[100];
void solve()
{
    scanf("%s",st);
    int len = strlen(st);
    ll ans = 1;
    for(int i=1;i<len;i++)
    {
        if(st[i]==st[i-1])ans<<=1LL;
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
