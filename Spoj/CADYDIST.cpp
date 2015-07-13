#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)break;
        unsigned long long a[n],b[n];
        unsigned long long s=0;
        for(int i=0;i<n;i++)scanf("%llu",&a[i]);
        for(int i=0;i<n;i++)scanf("%llu",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int k=n-1;
        for(int i=0;i<n;i++)
        {
            s+=a[i]*b[k];
            k=k-1;
        }
        printf("%llu\n",s);
        
    }
}
