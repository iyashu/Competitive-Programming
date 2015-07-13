#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x;
        int k,a[30];
        cin>>x;
        for(int i=0;;i++)
    {
        a[i]=x%5;if(a[i]==0)a[i]=5;
        x=x/5;
        if(a[i]==5)x=x-1;
        if(x==0){k=i; break;}
    }
    for(int i=k;i>=0;i--)
   { if(a[i]==1)printf("m");
    if(a[i]==2)printf("a");
    if(a[i]==3)printf("n");
    if(a[i]==4)printf("k");
    if(a[i]==5)printf("u");}
    cout<<endl;
    }
    return 0;
}
