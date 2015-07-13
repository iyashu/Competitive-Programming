#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double a,b,c,x;
        cin>>a>>b>>c;
        x=(a*b*c)/(((b*c)+(c*a)+(a*b))+(2.0*sqrt(a*b*c*(a+b+c))));
        cout.precision(6);cout.setf(ios::fixed,ios::floatfield);cout<<x<<endl;
    }
}
