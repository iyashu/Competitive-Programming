#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll B,X,Y,k;
        scanf("%lld %lld%lld%lld",&k,&B,&X,&Y);
        ll ans = 0;
        ll j = 0;
        while(X>0 || Y>0)
        {
            ll temp = (X%B)+(Y%B);
            temp = temp%B;
            ans = ans + temp*pow(B,j);
            X/=B;
            Y/=B;
            j++;
        }
        printf("%lld %lld\n",k,ans);
    }
}
