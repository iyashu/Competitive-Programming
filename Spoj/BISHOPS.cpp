#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string st;
    while(cin>>st)
    {
        //n-1*2
        ll len = st.length();
        if(len==1&&st=="1")
        {
            cout<<"1"<<endl;
            continue;
        }
        else if(len==1&&st=="0")
        {
            cout<<"0"<<endl;
            continue;
        }
        for(int i=len-1;i>=0;i--)
        {
            if(st[i]=='0') st[i] = '9';
            else
            {
                st[i] = st[i]-1;break;
            }
        }
        if(st[0]=='0')st = st.substr(1);
        len = st.length();
        ll num = 0;
        for(int i=len-1;i>=0;i--)
        {
            num = (st[i]-48)*2 + num;
            st[i] = char(num%10 + 48);
            num/=10;
        }
        if(num>0)cout<<num;
        cout<<st<<endl;
    }
}
