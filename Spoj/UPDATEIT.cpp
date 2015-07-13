#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define ll long long
#define ull unsigned long long 
#define ld long

#define MAXN 10005
using namespace std;


int scan_d()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ll scan_lld()    {int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ull scan_llu()    {int ip=getchar_unlocked();ull ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
 
//end of fast input
 
//fast output
 
//no line break
void print_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_lld(ll n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(ull n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
 
//new line
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void println_lld(ll n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void println_llu(ull n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

ll tree[MAXN],A[MAXN],B[MAXN];

ll read(ll idx)
{
    ll sum = 0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & (-idx));
    }
    return sum;
}
void update(ll idx,ll num)
{
    if(idx ==0)return;
    while(idx<MAXN)
    {
        tree[idx]+=num;
        idx+=(idx & (-idx));
    }
}
void solve()
{
    ll n,u,l,r,val;
    memset(tree,0,sizeof(tree));
    n = scan_lld();
    u = scan_lld();
    for(int i=0;i<u;i++)
    {
        l = scan_lld();
        r = scan_lld();
        val = scan_lld();
        l++;r++;
        update(l,val);
        update(r+1,-val);
    }
    ll q = scan_lld();
    while(q--)
    {
        l = scan_lld();
        l = read(++l);
        println_lld(l);
    }
}
int main()
{
    int t;
    t = scan_d();
    while(t--)
    {
        solve();
    }
}
