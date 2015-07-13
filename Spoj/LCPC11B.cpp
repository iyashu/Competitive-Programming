#include<cstdio>
#include<cmath>
long long count(long long a,long long b,long long k);
long long ar[10000];
int main()
{
    int t;
    scanf("%d",&t);
    for(int q=1;q<=t;q++)
    {
              long long a,b,n,i=2,k=0;
              scanf("%lld%lld%lld",&a,&b,&n);
              long long ans=b-a+1;
              while(n!=1)
              {
                         if(n%i==0)
                         {
                                 ar[k]=-1*i;
                                 long long x=k;
                                 k++;
                                 for(long long j=0;j<x;j++)
                                 {
                                         ar[k]=-1*ar[j]*i;
                                         k++;
                                 }
                                 while(n%i==0)n/=i;
                                 for(long long j=x;j<k;j++)
                                 {
                                         if(ar[j]<0) ans-=count(a,b,-1*ar[j]);
                                         else ans+=count(a,b,ar[j]);
                                 }
                         }
                         i++;
                         if(i*i>n)i=n;
              }
              printf("Case #%d: %lld\n",q,ans);
    }
    return 0;
}
long long count(long long a,long long b,long long k)
{
     return floor(b/k)-floor((a-1)/k);
}
