#include <bits/stdc++.h>
#define ll unsigned long long
#define ull unsigned long long
using namespace std;
#define MOD 3000000021ULL
#define MOD2 2000000012ULL
#define INV 333333336
ll scan_lld()    {int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
ull scan_llu()    {int ip=getchar_unlocked();if(ip==EOF)return-1;ull ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
ll power2[] = {2,4,16,256,65536,1294967275,582344008,2279632291,792845266,418385479,1812734599,2409643894,1246797658,2112754255,774491455,2669157976,2973586840,125655169,2385894028,1998632887,2036221060,164150368,125918023,405241093,306292255,816280417,1513497898,2215687321,1075265158,2915398921,71108578,1829787088,1974674410,213475114,978311635};
inline ll ipoww(ll a,ll b)
{
    ll ans = 1;
    int i = 0;
    while(b)
    {
        if(b&1)ans = ans*power2[i] % MOD;
        b>>=1;
        i++;
    }
    return ans;
}
ll ipow(ll a,ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b&1)
        {
            ret = (ret*a);
            if(ret>=MOD){ret%=MOD;}
        }
        a = (a*a);
        if(a>=MOD)a%=MOD;
        b>>=1;
    }
    return ret;
}
inline unsigned ilog2(ull x) {
	union Data {
		ull u64;
		double d;
	} n;
	n.d = double(x) + 0.5;
	return (n.u64 >> 52) - 1023;
}
int main()
{
    ll k,n,temp;
    //ll curr = 1;
    //for(int i=1;i<=35;i++)power2[i] = (power2[i-1]*power2[i-1]) % MOD;
    //for(int i=0;i<35;i++)cout<<power2[i]<<",";
    while(1)
    {
        n=scan_llu();
        if(n==-1)break;
        temp=1+ !(n&1);
        if(n>=MOD2)n=n%(MOD2);
        n = ipoww(2LL,n)+temp;
        n/=3;
        println_d(n);
    }
}
