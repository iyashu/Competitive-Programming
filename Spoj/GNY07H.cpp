#include<stdio.h>
int cal(int n)
{
    if(n==0||n==1) return 1;
    else if(n==2) return 5;
    else if (n==3) return 11;
    return cal(n-1)+5*cal(n-2)+cal(n-3)-cal(n-4);
} 
int main()
{
    int i,n,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    
    {
           scanf("%d",&n);
           printf("%d%",i);
           printf(" ");
           printf("%d\n",cal(n));
    }
}
