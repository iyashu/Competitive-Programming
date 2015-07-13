#include<iostream>
using namespace std;
int main()
{
int x;
cin>>x;
while(x--)
{
    cout<<endl;
    long long n,p;
    int a[100];
    for(int i=0;i<100;i++)a[i]=0;
    cin>>n;
    p=n;
    while(n--)
    {
        long long m;
        cin>>m;
        int carry=0;
        for(int i=99;i>=0;i--)
        {
        a[i]=a[i]+carry+(m%10);
        if(a[i]>9)carry =1;else carry =0;
        a[i]=a[i]%10;
        m=m/10;
        }
    }int k=0;
    for(int i=0;i<100;i++){if(a[i]==0)k=k+1;else break;}
    long long y,r=0;
    for(int j=k;j<100;j++)
    {
        y=(r*10)+a[j];
        r=y%p;
    }if(r==0)cout<<"YES"<<endl;else cout<<"NO"<<endl;
}
return 0;
}
