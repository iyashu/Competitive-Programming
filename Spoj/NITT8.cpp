#include <iostream>
#include <stdio.h>
#include <string>
#define ll long long

using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	ll ans = 1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll* ar = new ll[n];
		for(int i = 0;i<n;i++)
		{
			scanf("%lld",&ar[i]);
		}
		ll* start = ar;
		ll temp ;
		ll* end = ar+n-1;
		ll ans = 0;
		while(start<end)
		{
			if(*start > *end)
			{
				temp = (end-start)*(*end);
				end--;
			}
			else 
			{
				temp =(end-start)*(*start);
				start++;

			}
			if(temp>ans)ans = temp;

		}
		printf("%lld\n",ans);
		//delete [] ar;

	}
}
