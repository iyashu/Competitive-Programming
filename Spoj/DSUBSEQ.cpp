#include <iostream>
#include <stdio.h>
#include <math.h>
#define ll long long
#define MOD 1000000007 

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int len = s.length();
		//if(len==0){printf("1\n");continue;}
		ll ans =2;
		ll ar[26]= {0};
		ar[int(s[len-1] - 'A')] = 1;
		ll cal = 1;

		for(int i = len-2;i>=0;i--)
		{
			int x = int(s[i]-'A');
			cal = (ans - ar[x]+MOD)%MOD;
			ans=(ans+cal);
			ar[x]+=cal;
			ar[x]%=MOD;
		}
		printf("%lld\n",ans%MOD);
	}
}

