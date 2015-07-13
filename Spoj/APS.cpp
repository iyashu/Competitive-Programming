#include <stdio.h>
#include <iostream>
const int MAX = 10000000, LMT = 3162, LEN = 664580;
long long small[10000010];

void smallest() {
	long long i, j, k;
	small[0]=0;small[1]=0;
	for(i=2; i<=MAX; i++) small[i] = ((i&1)==0)? 2 : i;
	for(i=3; i<=LMT; i+=2)
		if(small[i]==i)
			for(j=i; j<=MAX; j+=i)
				if(small[j]==j)
					small[j] = i;
	for(i=1; i<=MAX; i++)small[i]=small[i]+small[i-1];
		
	}				
int main()
{
    int t;
    scanf("%d",&t);
    smallest();
    while(t--)
    {
        int n;
    scanf("%d",&n);printf("%lld\n",small[n]);
}    
}
