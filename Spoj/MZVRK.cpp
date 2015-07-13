#include <iostream>
#include <stdio.h>
#include <math.h>
#define ll unsigned long long
using namespace std;
ll cal(ll n)
{
    ll ans = 0;
    ll curr = 1;
    ll next = 2;
    while(curr<=n)
    {
        ll temp = (n-curr)/next;
        temp++;
        ans+=(temp*curr);
        curr=next;
        next<<=1;
    }
    return ans;
}

int main()
{
    ll n,m;
    scanf("%llu%llu",&n,&m);
    printf("%llu\n",cal(m)-cal(n-1));
}
