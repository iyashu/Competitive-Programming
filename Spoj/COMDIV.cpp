#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
void swap(int&,int&);
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y,i,r=0;
        scanf("%d%d",&x,&y);
        if(x<y)swap(x,y);
        for(;;)
       {
        i=x%y;
        if(i==0) break;
        x=y;
        y=i;
       }
       float d=sqrt(y*1.0);
       for(int j=1;j<=d;j++)
       if(y%j==0)r=r+2;
       if(d-int(d)==0)r=r-1;
       printf("%d\n",r);
    }
    return 0;
}
void swap(int& x,int& y)
{
    int n;
    n=x;
    x=y;
    y=n;
}
