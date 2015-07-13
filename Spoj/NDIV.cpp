#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#define MAX 31684
#define LMT sqrt(MAX)

#define chk_bit(to,x) (to[x>>6]&(1<<((x>>1)&31)))
#define set_bit(to,x) (to[x>>6]|=(1<<((x>>1)&31)))
//chk_bit check whether the flag at x is 1 or 0...1 means not a prime ...0 means probably it is a prime..
//set_bit sets the value of x as 1....
int flag[(MAX>>6)+1] = {0};
int primes[3410];
using namespace std;
void sieve()
{
	primes[0]=2;
	primes[1] = 3;
	int i,j,idx=2;
	/*for(j=4;j<=MAX;j+=2)		
		flag[j]=1;*/
	for(i=9;i<MAX;i+=6)set_bit(flag,i);	//flag[i] = 1;
	for(i=6;i<=LMT;i+=6)
	{
		int a = i-1;
		int b = i+1;
		if(!chk_bit(flag,a))
		{
			int k = a<<1;
			for(j=a*a;j<=(MAX);j+=k)
				if(!chk_bit(flag , j))
				set_bit(flag,j);
		}
		if(!chk_bit(flag,b))
		{
			int k = b<<1;
			for(j=b*b;j<=(MAX);j+=k)
				if(!chk_bit(flag ,j))
				set_bit(flag,j);
		}

	}
	for(i=6;i<MAX;i+=6)
	{
		int a = i-1;
		int b = i+1;
		if(!chk_bit(flag,a))
			primes[idx++] = a ; 
		if(!chk_bit(flag,b))
			primes[idx++] = b;
	}
	//for(i=0;i<3410;i++)
	//	printf("%d\n",primes[i]);

}
inline int count(int& num , int multiple)
{
	int cnt = 0;
	while(!(num%multiple))
		{
			num/=multiple;
			cnt++;
		}
		return cnt;
}
void segmentedSieve(int a ,int b,int m)
{
	// Boundary Contraints !!


	if(a==1 && m==1){printf("1\n");return;} 
	if(m==1 || b<a){printf("0\n");return;}
	if(b==1 && m!=1){printf("0\n");return;}
	if(b<2)return;

	//ans : array defines number of proper divisors of all the number between a to b!
	int* ans = new int [b-a+1];
	fill(ans,ans+1+b-a,1);
	
	//smallest prime multiple greater then a 
	int small;
	
	//ar : array containing the number from a to b
	int* ar = new int[b-a+1];
	for(int i=0;i<=b-a;i++)
		ar[i] = i+a;

	// Calculating the number of divisors of all the numbers from a to b 
	for(int i=0;primes[i]*primes[i]<=b;i++)
	{
		//finding the smallest primes[i] multiple greater than a
		small = (a+primes[i] - 1)/primes[i];
		small*=primes[i];
		
		for(int temp = primes[i];small<=b;small+=temp)
		{
				int cnt = count(ar[small-a],temp);
				ans[small-a] *= (cnt+1); 

		}
	}

	//check whether any prime number is remaining !
	for(int i=0;i<=(b-a);i++)
	{
		if(ar[i]!=1)
		{
			ans[i]<<=1;
		}
	}
	int num = 0;
	//calcute the number of such n divisors in range[a,b]!
	for(int i=0;i<=(b-a);i++)
		{
			if(ans[i] == m)num++;
		}
	printf("%d\n",num);
}
void solve()
{
	int a,b,m;
	scanf("%d%d%d",&a,&b,&m);
	sieve();
	segmentedSieve(a,b,m);
}
int main()

{
	int t;
	t=1;
	//scanf("%d",&t);
	while(t--)
	{
		solve();

	}
	
}
