#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll N,temp;
    scanf("%lld",&N);
    ll ans = 0;
    for(int i=0;i<N;i++)
    {
        scanf("%lld",&temp);
        ans^=temp;
    }
    printf("%lld\n",ans);
}
