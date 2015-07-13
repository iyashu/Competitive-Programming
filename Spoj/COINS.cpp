#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
ll ans[1000][2];
int id;
ll cal(ll n)
{
	if(n<12)return n;
	for(int i = 0;i<id;i++)
		if(ans[i][0] ==n)return ans[i][1];
	ll temp = cal(n>>1)+cal(n/3)+cal(n>>2);
	temp = (temp>n?temp:n);
	ans[id][0]= n;
	ans[id++][1] = temp;
	return  temp;
}
int main()
{
	ll n;
	while(scanf("%lld",&n)>0)
	{
		id =0 ;
		printf("%lld\n",cal(n));
	}
}
