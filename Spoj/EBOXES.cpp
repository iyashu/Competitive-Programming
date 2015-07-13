#include<iostream>
using namespace std;
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        int n,k,t,f;
        cin>>n>>k>>t>>f;
        f=(f-n)/(k-1);
        f=n+(f*k);
        cout<<f<<endl;
    }
    return 0;
}
