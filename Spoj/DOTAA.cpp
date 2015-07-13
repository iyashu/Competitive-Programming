#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int m,n,d,c=0;
    cin>>m>>n>>d;
    int a;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        if(a>d){int r=0;for(int j=0;a>d;j++){a=a-d;r=r+1;}c=c+r;}
    }
    if(c>=n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;    
}
