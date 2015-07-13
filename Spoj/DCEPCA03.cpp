#include<stdio.h>
#define MAX 10002
unsigned phi[MAX];
void ETF()
{
	unsigned i, j,k;
	phi[1] = 1;
	for(i=2; i<MAX; i++)
	{
		if(!phi[i])
		{
			phi[i] = i-1;
			for(j=(i<<1); j<MAX; j+=i)
			{
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
	for(k=2;k<=MAX;k++)phi[k]=phi[k-1]+phi[k];
}

int main()
{
	unsigned t, n;
	ETF();
	for(scanf("%d",&t);t;t--)
	{
		scanf("%d",&n);
		long long x=1;
		x=x*phi[n]*phi[n];
		printf("%lld\n",x);
	}
	return 0;
}
