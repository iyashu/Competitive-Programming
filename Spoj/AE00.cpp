#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int i,j,count=0,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sqrt(i*1.0);j++)
        {
            if (i%j==0)
            {count++;}
        }
    }
    printf("%d\n",count);
    return 0;
}
