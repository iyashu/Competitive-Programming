#include<stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define MAX 163000000
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
            if(!ans[kill[i]])
             ans[kill[i]]=i;
            else ans[kill[i]]=MIN(i,ans[kill[i]]);
    int k,t;
    scanf("%d",&t);
    ans[1]=1;
    while(t--)
    {
               scanf("%d",&k);
               if(ans[k])printf("%d\n",ans[k]);
               else printf("-1\n");
    }
    
    return 0;
}
