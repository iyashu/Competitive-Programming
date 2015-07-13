#include<iostream>
using namespace std;
int gcd(int x, int y)
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
        int n,m;
        scanf("%d%d",&n,&m);
        int p=gcd(n,m);
        printf("%d %d\n",m/p,n/p);
    }
}

