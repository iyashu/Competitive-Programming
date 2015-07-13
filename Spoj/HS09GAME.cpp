#include<iostream>
#include<stdio.h>
int moves[]={2,3,5};
using namespace std;
int main()
{
    int t;
    int nim[]={0,0,1,1,2,2,3};
    scanf("%d",&t);
    while(t--)
    {
        int n,ans=0;
        scanf("%d",&n);
        int* a=new int[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            ans=ans^nim[a[i]%7];
        }
        if (ans==0)printf("Robert wins.\n");
        else
        {
            printf("Julia wins.\n");
            int move=-1,heap=-1;
            for(int j=2;j>=0;j--)
            {
                for(int i=0;i<n;i++)
                {
                    if(a[i]>=moves[j])
                    {
                        int r=ans^nim[a[i]%7]^nim[(a[i]-moves[j])%7];
                        if(r==0)
                        {
                            heap=i;
                            move=moves[j];
                            goto step;
                        }
                    }
                }
            }
            step: printf("Take %d sticks from heap number %d.\n", move, heap+1);
        }
    }
}
