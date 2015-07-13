#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
string st;
int len;
ll power10[15];
ll convert(string num)
{
    ll ans = 0;
    int l = num.length();
    for(int i=0;i<l;i++)
    {
        ans = ans*10 + num[i]-48;
    }
    return ans;
}
ll mul(ll a,ll b,ll mod)
{
    ll ans = 0;
    a = a%mod;
    b = b%mod;
    while(b)
    {
        if(b&1)ans = (ans+a)%mod;
        a<<=1LL;
        a%=mod;
        b>>=1;
    }
    return ans;
}
ll cube(ll a,ll mod)
{
    ll temp = mul(a,a,mod);
    temp = mul(a,temp,mod);
    return temp;
}

void solve()
{
    cin>>st;
    len = st.length();
    ll temp,mod,num,i =1;
    ll curr = 0;
    ll ans = 0;
    while(i<=len)
    {
        num = st[len-i]-48;
        num = num*power10[i-1];
        curr+=num;
        mod = power10[i];
        int j =0;
        temp = ans;
        while(j<10)
        {
            temp = (power10[i-1]*j+ans);
            if(cube(temp,mod)==curr)break;
            j++;
        }
        ans = temp;
        i++;
    }
    printf("%lld\n",ans);

}
int main()
{
    int t;
    scanf("%d",&t);
    power10[0] = 1;
    for(int i=1;i<15;i++)power10[i] = power10[i-1]*10LL;
    while(t--)
    {
        solve();
    }
}
