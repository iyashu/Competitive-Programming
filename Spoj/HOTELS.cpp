#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
#define MAXN 300005
using namespace std;


int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll* ar = new ll[n];
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&ar[i]);
	}
	ll sum = 0;
	ll ans = -1;
	int index = 0;
	for(int i=0;i<n;i++)
	{
		if(ar[i]>m)
			continue;
		while(sum+ar[i]>m && index<i)
		{
			sum-=ar[index];
			index++;
		}
		if(sum+ar[i] <= m)
		{
			sum = sum + ar[i];
		}
		ans = max(ans,sum);
	}
	printf("%lld\n",ans);

}
