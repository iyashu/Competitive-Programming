#include <bits/stdc++.h>
#define ll long long
using namespace std;
string st;
ll C(string temp)
{
    ll len = st.length();
    ll cnt = 0;
    for(int i=0;i<len-2;i++)
    {
        //cout<<st.substr(i,3)<<" ";
        if(st.substr(i,3)==temp)cnt++;
    }
    return cnt;
}

int main()
{
    int t,f;
    scanf("%d",&t);
    while(t--)
    {
        cin>>f;
        cin>>st;
        cout<<f;
        for(int i=0;i<8;i++)
        {
            string temp = "";
            if((i>>2)&1)temp +="H";
            else temp+="T";
            if((i>>1)&1)temp+="H";
            else temp+="T";
            if(i&1)temp+="H";
            else temp+="T";
            cout<<" "<<C(temp);
        }
        cout<<endl;
    }
}
