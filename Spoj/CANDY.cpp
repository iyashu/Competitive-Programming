#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==(-1)) break;
        float a[n];
        int k=n;
        while(n--)
        {
            float m;
            cin>>m;
            a[n]=m;
        }
        float m=0;
        int r=0;
        for(int i=0;i<k;i++)
        {m=m+a[i];}
        m=m/k;
        if((m-int(m))!=0) cout<<"-1"<<endl;
        else{for(int i=0;i<k;i++){if(a[i]>m)r=r+(a[i]-m);}cout<<r<<endl;}
    }
    return 0;
}
