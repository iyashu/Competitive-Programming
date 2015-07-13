#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define ll long long

using namespace std;

/**
n = number of cuts ...
maximum number of piece(p)  = (n*n + n +2)/2
Read more at Lazy caterer's sequence ...

for 3 cuts maximum number of pieces is 7 ;



**/
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		double x ;
		scanf("%lld",&n);
		n = (n-1)<<3;
		x = sqrt(1.0+n);
		x = (x-1.0)/2.0;
		x = ceil(x);
		n = (ll) x;		
		printf("%lld\n",n);
	}
}
