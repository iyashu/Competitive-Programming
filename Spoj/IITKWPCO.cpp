#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i])
           {
               int k=lower_bound(a+i+1,a+n,2*a[i])-a;
               if(a[k] && a[k]==2*a[i])
               {cnt++;a[k]=0;a[i]=0;}
           } 
        }
        printf("%d\n",cnt);
    }
}
