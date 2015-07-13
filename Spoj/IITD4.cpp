#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
ll scan_lld()    {int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
void println_lld(ll n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
using namespace std;
ll pow_st[100005];
ll sum[100005];
ll num[100005][17];
ll pre;
inline ll ipow(ll a,ll b)
{
    ll ans = 1;
    int i = 0;
    while(b)
    {
        if(b&1)ans = ans*num[a][i] % MOD;
        b>>=1;
        i++;
    }
    return ans;
}
ll cal(ll n)
{
    ll temp,ans = n;
    ll sqrtn = sqrtl(n);
    ll cnt = 1;
    ll curr = n;
    ll i = 2;
    while(cnt<n)
    {
        temp = n/i;
        ans +=(temp*pow_st[i]);
        cnt++;
        if(i<=sqrtn)
        {
            ll cnt1 = (sum[curr]-sum[temp]+MOD);
            ans+=(cnt1*(i-1));
            cnt+=(curr-temp);
        }
        ans%=MOD;
        curr = temp;
        //(sum[curr]-sum[temp])
        i++;
    }
    //cout<<i<<endl;
    return ans;
}
void solve()
{
    ll a,b,k;
    //a = scan_lld();b=scan_lld();k=scan_lld();
    cin>>a>>b>>k;
    if(pre<b)
    {
        for(int i=pre+1;i<=b;i++)
        {
            num[i][0] = i;
            for(ll j=1;j<17;j++)
            {
                num[i][j] = (num[i][j-1]*num[i][j-1]);
                if(num[i][j]>=MOD)num[i][j]%=MOD;
            }
        }
        pre = b;
    }
    for(int i=1;i<=b;i++)
    {
        pow_st[i] = ipow(i,k);
        sum[i] = sum[i-1]+pow_st[i];
        //if(sum[i]>=MOD)sum[i]-=MOD;
    }
    ll ans = 0;
    a--;
    //for(int i=1;i<=a;i++)ans+=(((b/i)-(a/i))*pow_st[i]),ans%=MOD;
    //for(int i=a+1;i<=b;i++)ans+=((b/i)*pow_st[i]),ans%=MOD;
    //println_lld(ans);
    ans = cal(b)-cal(a)+MOD;
    if(ans>=MOD)ans-=MOD;
    cout<<ans<<'\n';
}

int main()
{
    ll t;
    pre = 0;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--) solve();
}
