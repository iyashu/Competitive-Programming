#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>m;
         a[i]=0;
        for(int j=1;m>0;j++)
        {m=m/5;
        a[i]=a[i]+m;}
    }
    for(int k=0;k<n;k++)
    cout<<a[k]<<endl;
    return 0;
    
}
