#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		string tmp = a;
		a=a+b;
		b = b+tmp;
		if(a==b)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
