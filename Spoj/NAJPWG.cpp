#include <stdio.h>
#define ll long long
#define MAX 100005
ll factor[100005];
ll kill[MAX];
void phi()
{
    int i,j;
    for(i=2;i<MAX;i++)
            kill[i]=i;
    for(i=2;i<MAX;i++)
            if(kill[i]==i)
            for(j=i;j<MAX;j+=i)
               kill[j]=(kill[j]/i)*(i-1);
}
void pre()
{
    factor[0] = 0;
    int i;
    for(i=1;i<=100000;i++)
        factor[i] = factor[i-1]+kill[i];
}
int main()
{
    phi();
    pre();
    int t;
    scanf("%d",&t);
    int i;
    for(i=1;i<=t;i++)
    {
        ll n;
        scanf("%lld",&n);
        ll temp = ((n*(n+1))/2) - factor[n];
        printf("Case %d: %lld\n",i,temp-1);
    }
    return 0;
}
