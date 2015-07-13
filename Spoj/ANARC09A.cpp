#include <bits/stdc++.h>
#define ll long long
using namespace std;
string st;
int main()
{
    int t = 0;
    while(++t && cin>>st)
    {
        if(st[0]=='-')break;
        int len = st.length();
        stack<char> s;
        int x = 0;
        for(int i=0;i<len;i++)
        {
            int temp = s.size();
            if(temp==0 && st[i]=='}')x++;
            if(temp==0)s.push(st[i]);
            else
            {
                if(st[i]=='}')s.pop();
                else s.push(st[i]);
            }
        }
        ll ans = s.size()>>1;
        printf("%d. %lld\n",t,ans+x);

    }
}
