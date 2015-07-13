#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double n,x;
        cin>>n;
        x=1000000000000000000.0/n;
        cout.precision(8);cout.setf(ios::fixed,ios::floatfield);cout<<(x/1000000000000000000.0)+2<<endl;
    }
}
