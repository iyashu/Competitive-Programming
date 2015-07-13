#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

#define MAX 1000000
#define chk_bit(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define set_bit(x) (flag[x>>6]|=(1<<((x>>1)&31)))

using namespace std;


int primes[78500];
//ll start[10000];
//ll end[10000];
//Just uncomment to use the function ....

char flag[MAX+1] = {0};
void sieve_of_eros()
{
	primes[0]=2;
	flag[0] = flag[1] = 1;
	primes[1] = 3;
	int i,j,idx=2;		//idx take the account of number of primes..
	for(i=9;i<MAX;i+=6)flag[i]=1;	//flag[i] = 1;
	for(i = 4;i<=MAX;i+=2)flag[i]=1;
	for(i=6;i<=sqrt(MAX);i+=6)
	{
		int a = i-1;
		int b = i+1;
		if(!flag[a])
		{
			int k = a<<1;				//making increment of 2*a inorder to avoid even number...
			for(j=a*a;j<=(MAX);j+=k)	
				if(!flag[j])
				flag[j] = 1;
		}
		if(!flag[b])
		{
			int k = b<<1;
			for(j=b*b;j<=(MAX);j+=k)
				if(!flag[j])
				flag[j] = 1;
		}

	}

	for(i=6;i<MAX;i+=6)
	{
		int a = i-1;
		int b = i+1;
		if(!flag[a])
			primes[idx++] = a ; 
		if(!flag[b])
			primes[idx++] = b;
		
	}
}
void facto(ll factor[],int len,ll multi[],int current,long long result,vector<ll>& divisors,ll tmp)
{
	if(current ==len){divisors.push_back(result);return;}
	for(int i=0;i<=multi[current];i++)
	{
		facto(factor,len,multi,current+1,result,divisors,tmp);
		result*=factor[current];
	}
}
int main()
{
	sieve_of_eros();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld",&n);
		if(n&1){printf("0\n");continue;}
		n>>=1;
		ll factor[1000] = {0};
		ll power[100] ={0};
		bool* check = new bool[1000000];
			m = n;
			int f=0;
			ll ans = 1;
			for(ll i =0;i<78498 && primes[i]*primes[i]<=n;i++)
			{
				if(n%primes[i]==0)
				{
					
					factor[f] = primes[i];
					check[primes[i]] = 1;
					while(n%primes[i] ==0)
					{
						n/=primes[i];
						power[f]++;
					}
					ans*=(power[f]+1);
					f++;

				}
			}
			long long chk = 0;
			if(n>1){chk+=n;factor[f] = n;power[f++]++;ans<<=1;}
			ans-=f;
			printf("%lld",ans);
			vector<ll>divisors;
			facto(factor,f,power,0,1,divisors,chk);
			int num = int(divisors.size());
			sort(divisors.begin(),divisors.begin()+num);
			//cout<<"\n"<<num<<endl;
			std::vector<ll>::iterator it=divisors.begin();
			for (; it!=divisors.end() && (*it <=1000000); ++it)
			{
				if(flag[*it] && *it!=chk)
				printf(" %lld",*it);
			}
			for(;it!=divisors.end();it++)
			{
				if(chk!= *it)
					printf(" %lld",*it);
			}
			//cout<<"YES"<<endl;
			printf("\n");

	}
	return 0;

}

