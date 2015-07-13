#include<stdio.h>
#define MAX 1000500
int kill[MAX];
int ans[MAX];
int main(){
    
    int i,j;
    for(i=2;i<MAX;i++)
            kill[i]=i;
    for(i=2;i<MAX;i++)
            if(kill[i]==i)
            for(j=i;j<MAX;j+=i)
               kill[j]=(kill[j]/i)*(i-1);
     for(i=2;i<MAX;i++)
             ans[kill[i]]=1;
    int a,b,c,k,t;
    scanf("%d",&t);
    while(t--)
    {
               scanf("%d%d%d%d",&a,&b,&c,&k);
               if(ans[k]==1)printf("Yes\n");
               else printf("No\n");
    }
    
    return 0;
}
