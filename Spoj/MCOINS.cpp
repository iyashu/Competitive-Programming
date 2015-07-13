#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ar[1000002];
int main()
{
    ll k,l,n;
    scanf("%lld%lld%lld",&k,&l,&n);
    ar[0] = 0;
    ar[1] = 1;
    for(int i=2;i<1000002;i++)
    {

        ll temp = i-k>=0?ar[i-k]:1;
        ll tmp = i-l>=0?ar[i-l]:1;
        ar[i] = !(ar[i-1]&temp&tmp);
    }
    ll temp;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&temp);
        if(ar[temp])printf("A");
        else printf("B");
    }
    puts("");

}
