#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int w,b;
		scanf("%d%d",&w,&b);
		if(b&1)printf("1.000000\n");
		else printf("0.000000\n");
	}
}
