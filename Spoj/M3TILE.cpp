#include<stdio.h>
int main()
{
    int i,n,a[35];
    a[0]=1;a[2]=3;
    a[1] = 0;
    for (i=3;i<35;i++)
    {
        if(i&1) a[i] = 0;
        else a[i] = 4*a[i-2] - a[i-4];
    }
    while(scanf("%d",&n) && n!=-1)
    
    {
           printf("%d\n",a[n]);
    }
}
