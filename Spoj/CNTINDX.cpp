#include <bits/stdc++.h>
#define pb push_back
#define ll long long
//typedef long long ll
using namespace std;
vector <ll> V[200002];
ll ar[200002];
ll scan_lld()    {int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}

ll cnt(ll x,ll j)
{
    ll sz = V[x].size();
    if(sz==0)return 0;
    ll ans = lower_bound(V[x].begin(),V[x].end(),j)-V[x].begin();
    if(ans<sz && V[x][ans]==j)ans++;
    return ans;
}
int main()
{
    ll Q,flag,x,pre,i,j;
    int idx = 0;
    Q = scan_lld();
    while(Q--)
    {
        flag = scan_lld();
        if(flag==1)
        {
            x = scan_lld();
            idx++;
            ar[idx] = x;
            V[x].pb(idx);
        }
        else if(flag==0)
        {
            if(idx==0)puts("invalid");
            else V[ar[idx]].pop_back(),idx--;
        }
        else
        {
            x = scan_lld();i = scan_lld();j = scan_lld();
            ll ans = cnt(x,j)-cnt(x,i-1);
            println_d(ans);
        }
    }
}
