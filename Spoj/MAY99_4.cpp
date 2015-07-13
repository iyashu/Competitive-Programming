#include<iostream>
using namespace std;
main()
{
    int m,n;
    int a[200];
    a[0]=1;
    for(int i=1;i<200;i++)a[i]=0;
    cin>>m>>n;
    if(m<n)cout<<"-1"<<endl;
    else{
    m=m-1;
    n=n-1;
    if(n<(m/2))n=m-n;
    for(int j=n+1;j<=m;j++)
        {
            for(int i=0;i<200;i++)
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
        for(int i=199;i>=0;i--)
        {
            if(a[i]%10==0) count++;
            else break;
        }
        long long y,r=0;
        for(int j=1;j<=(m-n);j++)
        {
        for(int i=(199-count);i>=0;i--)
        {
        y=(r*10)+a[i];
        r=y%j;
        a[i]=y/j;
        }
        }
        int k=0;
        for(int i=199-count;i>=0;i--)
        {
            if(a[i]%10==0) k++;
            else break;
        }
        long long s,p=0;
        for(int i=199-(count+k);i>=0;i--)
        {
        s=(p*10)+a[i];
        p=s%10000007;
        a[i]=s/10000007;
        }
        cout<<p<<endl;
        }
        return 0;
}
