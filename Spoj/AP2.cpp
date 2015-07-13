#include<iostream>
using namespace std;
int main()
{
 int a;
 long long x,d,n,i;
 cin>>a;
for(;a>0;a--)
{
    cin>>x>>d>>n;
    n=2*n/(x+d);
    cout<<n<<endl;
    d=(d-x)/(n-5);
    x-=2*d;
    cout<<x;
    for(i=1;i<n;i++)
    {
      cout<<" "<<x+i*d;
    }
    cout<<endl;
}   
return 0;
}
