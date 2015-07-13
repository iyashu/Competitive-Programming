#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
        int friends, money,count=0;
        scanf("%d%d",&friends,&money);
        int* a=new int[friends];
        for(int i=0;i<friends;i++)
        {
                scanf("%d",&a[i]);
        }
        sort(a,a+friends);
        for(int i=0;i<friends;i++)
        {
                if(binary_search(a+i+1,a+friends,money-a[i]))count++;
             
               
        }
       printf("%d\n",count);
}
return 0;
}
