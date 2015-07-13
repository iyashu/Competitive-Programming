#include<stdio.h>
int a[1000001]={0};int ans[1000001][11]={{0}};
int main()
{
    for(int i=2;i<1000001;i++)
    {
        if(a[i]==0)
        {
            for(int j=i;j<1000001;j+=i)
            {
                a[j]++;
            }
        }
    }
    for(int i=2;i<1000001;i++)
    {
        if(a[i]<11)
        {
            ans[i][a[i]]=1;    
        }
        for(int j=0;j<11;j++)
        {
            ans[i][j]+=ans[i-1][j];
        }
        
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        int k;
        k=ans[b][n]-ans[a-1][n];
        printf("%d\n",k);
    }
    return 0;
}
