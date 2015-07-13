#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int x,y;
    cin>>x>>y;
    if(x<0||y<0)cout<<"No Number"<<endl;
    else if(x==0&&y==0) cout<<"0"<<endl;
    else if(x==1&&y==1)cout<<"1"<<endl;
    else if(y==x||y==x-2){
     if(x%2==0)cout<<x+y<<endl;
    else if(x%2==1) cout<<(x+y-1)<<endl;}
    else cout<<"No Number"<<endl;
    }
    return 0;
}
