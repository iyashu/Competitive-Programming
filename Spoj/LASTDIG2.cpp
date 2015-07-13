#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        long long a,b,n;
        char p[1005];
       cin>>p;
       n=strlen(p);
        a=p[n-1]-'0';
        cin>>b;
        if(a==0&&b==0)cout<<"0"<<endl;
        else if(b==0) cout<<"1"<<endl;
        else if(a==(0||1||5||6)&&b!=0) cout<<a<<endl;
        else if (b%4==0&&b!=0) cout<<(a*a*a*a)%10<<endl;
        else if(b%4==1)cout<<a%10<<endl;
        else if(b%4==2)cout<<(a*a)%10<<endl;
        else if (b%4==3)cout<<(a*a*a)%10<<endl;
    }
    return 0;
}
