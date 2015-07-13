#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    while(1)
    {
        int n,m;
        long double x;
        cin>>n;
        if(n==-1) break;
        x=sqrt(((4.0*n)-1)/3);
        m=x;
        if(m%2==1 && x-int(x)==0) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}
