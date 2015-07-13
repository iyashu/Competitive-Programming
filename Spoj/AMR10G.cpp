#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,d,md;
        scanf("%d%d",&n,&k);
        int a[20000];
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        md=a[k-1]-a[0];
        for(int i=0;i+k<=n;i++)
        {
            d=a[k+i-1]-a[i];
            md=min(d,md);
        }
        printf("%d\n",md);
    }
}
