#include<stdio.h>
long long gcd(long long x, long long y)
{
	while(y) y^=x^=y^=x%=y;
	return x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,p,i;
        scanf("%lld",&n);
        p=n/2;
        for( i=p;i>=1;i--)
        {
            if(gcd(i,n)==1) {printf("%lld\n",i);break;}
        }
    }
}
