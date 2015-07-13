#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
long long convert(long long x)
{
	int temp=0;
	while(x>=pow(2.0,temp))
		temp++;
	int j=temp-1,ans=0;
	while(x!=0)
	{
		if(x&1)
		ans+=pow(2.0,j);
		x=x>>1;
		j--;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long x;
		scanf("%lld",&x);
		if(x&1)
			{printf("%lld\n",x );continue;}
		while(!(x&1))
		{
			x=x>>1;
		}
		printf("%lld\n",convert(x));
	}
}
