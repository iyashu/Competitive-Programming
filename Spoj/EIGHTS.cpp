#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long x;
		cin>>x;
		x=((x-1)*250)+192;
		cout<<x<<endl;
	}
	return 0;
}
