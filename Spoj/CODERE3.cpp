#include<stdio.h>
using namespace std;
int LIS (int a[],int n)
{
    int* lis=new int[n];
    for(int i=0;i<n;i++)
    lis[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && lis[i]<lis[j]+1)
            lis[i]=lis[j]+1;
        }
    }
    int* lds=new int[n];
    for(int i=0;i<n;i++)lds[i]=1;
    for(int i=n-2;i>=0;i--)
    for(int j=n-1;j>i;j--)
    if(a[i]>a[j] && lds[i]<lds[j]+1)
    lds[i]=lds[j]+1;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(max<(lis[i]+lds[i]-1))
        max=(lis[i]+lds[i]-1);
    }
    return max;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int* a=new int[n];
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        printf("%d\n",LIS(a,n));
        
    }
}
