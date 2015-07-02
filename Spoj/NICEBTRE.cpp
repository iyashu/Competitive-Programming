#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string st;
int len,i;
int T()
{
    if(i>=len)return 0;
    i++;
    if(st[i]=='l') {return 0;}
    if(st[i]=='n')
    {
        int temp = T()+1;
        int temp2 = T()+1;
        temp = max(temp,temp2);
        return temp;
    }
}

void solve()
{
    cin>>st;
    i =-1;
    len = st.length();
    printf("%d\n",T());
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}
