#include <stdio.h>
#define MAX 1000000
#define LMT 1000
#define ll long long
#define MOD 1000000007
int pfactor[1000010];ll ar[1000001];
long long int mcount[1000010], mval[1000010];

int main() 
{
    int i,j,x;
	mval[1] = mcount[1] = 1;
	for(i=1; i<=MAX; i++) pfactor[i] = i;
	for(i=2; i<=LMT; i++)
		if(pfactor[i]==i)
			for(j=i<<1; j<=MAX; j+=i)
				if(pfactor[j]==j)
					pfactor[j] = i;
					for(i=2, x; i<=MAX; i++)
	{
		x = i;
		mcount[i] = 1;
		while(x%pfactor[i]==0)
		{
			mcount[i] *= pfactor[i];
			x /= pfactor[i];
		}
	}
	for(i=2; i<=MAX; i++)
		mval[i] = mval[i/pfactor[i]]+mcount[i]*(mcount[i]-mcount[i]/pfactor[i])*mval[i/mcount[i]];
	int t, n;
	long long res,a;
	ll b,k,z=1;ar[0];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%lld%lld",&a,&b);k=b;
	    ll c=1;
	    for(i=1;i<=a-1;i++)
	    ar[i] = i;
	   // for(int i=0;i<=b;i++)cout<<ar[i]<<endl;
	    while(k>1)
          {
              if(z==pfactor[k])c=c*pfactor[k];
              else c=pfactor[k];
          for(j=c;j<=a-1;j+=c)
          {
              ar[j]/=pfactor[k];
          }
          z=pfactor[k];
          k/=pfactor[k];
          }
          ll sum=0;	
          for(i=1;i<=a-1;i++)sum+=ar[i];
          sum*=b;
          res = mval[b]-1;
		if(res&1) res *= (b>>1);
		else res>>=1, res*=b;
		res += b;
		sum=(res-sum)%MOD;
          printf("%lld\n",sum);
    }
}
