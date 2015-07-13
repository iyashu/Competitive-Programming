#include<iostream>
#include<cmath>
long long comb(int m,int n);
using namespace std;
int main()
{
    int ca;
    cin>>ca;
    while(ca--)
    {
    int e,f,g;
    cin>>e>>f>>g;
    long long t;
    long long p,u,v,w;
    t=comb((e+f),g)-(comb(e,g)+comb(f,g)+(comb(e,3)*comb(f,(g-3)))+(comb(e,2)*comb(f,(g-2)))+(comb(e,1)*comb(f,(g-1))));
    cout<<t<<endl;
    }
    return 0;
}
long long comb(int m,int n)
{
    if(m<n) return 0;
    else{
    int a[100];
    a[0]=1;
    for(int i=1;i<100;i++)a[i]=0;
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
        long long s=0;
        for(int i=0;i<=99-(count+k);i++)
         s=s+(a[i]*pow(10.0,i));
        return s;}
}
