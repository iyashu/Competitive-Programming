#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

ll fibo[75];

void fibonacci()
{
	fibo[0] = 1;
	fibo[1] = 2;
	fibo[2] = 3;
	for(int i=3;i<75;i++)
	{
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
}
int main()
{
	int t;
	fibonacci();
	scanf("%d",&t);
	while(t--)
	{
		ll n ;
		scanf("%lld",&n);
		//printf("%lld\n",fibo[n]);
		if (binary_search(fibo,fibo+73,n))
		{
			printf("1");
			ll temp = lower_bound(fibo,fibo+73,n)-fibo;
			for(int i=0;i<temp;i++)
				printf("0");
			printf("\n");
			continue;
		}
		else
		{
			ll temp = lower_bound(fibo,fibo+73,n)-fibo;
			int ans[temp];
			ans[0]=1;
			for(int i=1;i<temp;i++)
			{
				ans[i] = 0;
			}
			n = n-fibo[temp-1];
			//cout<<n<<endl;
			while(1)
			{
				
				ll num = lower_bound(fibo,fibo+73,n)-fibo;
				if (fibo[num] == n)
					ans[temp-num-1] = 1;
				else
					ans[temp-num] = 1;
				if (binary_search(fibo,fibo+73,n))
					break;
				else 
					n = n-fibo[num-1];
			}
			for(int i=0;i<temp;i++)
				printf("%d",ans[i]);
			printf("\n");
		}
	}
}
