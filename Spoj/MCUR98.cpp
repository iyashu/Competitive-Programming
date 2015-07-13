#include<stdio.h>
int ar[1000001]={0};
int main()
{
    int i,j,k;
    for(i=1;i<1000000;i++)
    {
        j=i;k=j;
        while(j>0)
        {
            k+=j%10;
            j/=10;
        }
        ar[k]=1;
    }
    for(i=1;i<1000000;i++)
    {
        if(ar[i]==0)printf("%d\n",i);
    }
}
