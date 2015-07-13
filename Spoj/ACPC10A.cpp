#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        float a,b,c;
        cin>>a>>b>>c;
        if (a==b||b==c||c==a) break;
        {if((2*b)==(a+c)) cout<<"AP "<<c+(b-a)<<endl;
        else cout<<"GP "<<(b*c)/a<<endl;}
    }
    return 0;
}
