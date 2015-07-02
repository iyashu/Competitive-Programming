#include<stdio.h>
#define C 10000007
int modu(int a,int b);
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k))
    {
        if(n==0)break;
        n=((((2*modu(n-1,k))%C+modu(n,k))%C+(2*modu(n-1,n-1)))%C+(modu(n,n)))%C;
        printf("%d\n",n);
    }
    return 0;
}
inline int modu(int a,int b)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y)%C;
        }
        y = (y*y)%C;
        b /= 2;
    }
    return x%C;
}
