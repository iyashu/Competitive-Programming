#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string st;
        cin>>st;
        ll len = st.length();
        int i=0;int j = len-1;
        int flag = 1;
        while(i<j)
        {
            if(st[i]!=st[j])
            {
                flag = 0;
                break;
            }
            i++;j--;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
