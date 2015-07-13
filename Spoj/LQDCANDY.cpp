#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k,m=0,r,p;
        cin>>n;
        p=n;
        for(long long i=0;;i++)
        if(pow(2.0,i*1.0)>=n){r=pow(2.0,i*1.0);break;}
        cout<<r<<" ";
        long long a[70];
        for(long long i=0;;i++)
    {
        a[i]=n%2;
        n=n/2;
        if(n==0){k=i; break;}
    }
    
    for(int i=0;i<=k;i++)
    {if (a[i]==1) break;
        if(a[i]==0)m++;}
    for(long long i=0;i<70;i++)
        if(pow(2.0,i*1.0)==p){k=k-1;break;}
        cout<<k+1-m<<endl;
    }
}
