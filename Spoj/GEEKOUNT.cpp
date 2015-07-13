#include<iostream>
#include<stdio.h>
#include<math.h>
#define LL long long

using namespace std;
LL digit[] = {1,3,5,7,9};
LL solve(LL n)
{

	LL x = n;
	int m =0;
	while(x>0)
	{
		x/=10;
		m++;

	}
	x = n;
	int a[15] = {0};
	bool flg = false;
	for(int i=m;i>0;i--)
	{
		if(x%10 == 0)a[i] = 0;
		else
		a[i] += x%10;
		if(a[i]==0)
		{
			a[i-1] = -1;
			if(a[1] ==-1)flg = true;
			for(int j=i;j<=m;j++)
				a[j]  = 9;
		}
		x/=10;
	}
	if(flg && a[1] == 9)a[1] = 0;
	
	for(int i=1;i<=m;i++)
	{
		if(a[i] ==0)continue;
		if(!(a[i]&1))
		{
			a[i] = a[i]-1;
			for(int j =i+1;j<=m;j++)
				a[j] = 9;
			break;
		}
	}
	LL cnt = 0;
	
	for(int i=1;i<=m;i++)
	{
		if(a[i]==0)continue;
		LL temp = (LL)(a[i]-1);
		temp = temp>>1;
		temp = (temp+1) *((LL)pow(5.0,m-i));
		cnt+=temp;
	}
	cnt=n-cnt;
	
	return cnt;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
}
