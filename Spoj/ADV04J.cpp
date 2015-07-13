#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r=0;
        cin>>n;
        for(;;)
        {
        if(n==2||n==3)break;
        if(n%2==1)n=n+1;
        n=n/2;
        r=r+1;
        }
        if(n==2)cout<<r+2<<endl;
        else cout<<r+3<<endl;
    }
}
