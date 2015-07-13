#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    while(x--)
    {
    int m,n;
    int a[100];
    a[0]=1;
    for(int i=1;i<100;i++)a[i]=0;
    cin>>m>>n;
    m=m-1;
    n=n-1;
    if(n<(m/2))n=m-n;
    for(int j=n+1;j<=m;j++)
        {
            for(int i=0;i<100;i++)
            {
                a[i]=a[i]*j;
                for(;a[i]>=10;i++)
                {
                    a[i+1]=(a[i]/10)+(a[i+1]*j);
                    a[i]=a[i]%10;
                    if(a[i+1]<10)
                    {
                        i=i+1;
                        break;
                    }    
                }
            }
        }
        int count=0;
        for(int i=99;i>=0;i--)
        {
            if(a[i]%10==0) count++;
            else break;
        }
        long long y,r=0;
        for(int j=1;j<=(m-n);j++)
        {
        for(int i=(99-count);i>=0;i--)
        {
        y=(r*10)+a[i];
        r=y%j;
        a[i]=y/j;
        }
        }
        int k=0;
        for(int i=99-count;i>=0;i--)
        {
            if(a[i]%10==0) k++;
            else break;
        }
        for(int i=99-(count+k);i>=0;i--)
        cout<<a[i];
        cout<<endl;
    }
   
    return 0;    
}
