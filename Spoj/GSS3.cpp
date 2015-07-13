#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long
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

ll ar[50005];
struct node
{
    ll prefix,suffix,sum,ans;
    void merge(node& a,node& b)
    {
        sum = a.sum+b.sum;
        prefix = max(a.prefix,a.sum+b.prefix);
        suffix = max(b.suffix,b.sum+a.suffix);
        ans = max(max(a.ans,b.ans),a.suffix+b.prefix);
    }
}tree[200005];

void build(ll root,ll tl,ll tr)
{
    if(tl==tr)
    {
        tree[root].prefix = tree[root].suffix=tree[root].ans = tree[root].sum = ar[tr];
        return;
    }
    ll mid = tl+tr;mid>>=1;
    ll left = root<<1;
    ll right = left+1;
    build(left,tl,mid);
    build(right,mid+1,tr);
    tree[root].merge(tree[left],tree[right]);
}
node query(ll root,ll tl,ll tr,ll l ,ll r)
{
    if(tl==l && tr==r)return tree[root];
    ll mid = tl+tr;mid>>=1;
    ll left = root<<1;
    ll right = left+1;
    if(r<=mid)return query(left,tl,mid,l,r);
    if(l>mid)return query(right,mid+1,tr,l,r);
    node NL = query(left,tl,mid,l,mid);
    node NR = query(right,mid+1,tr,mid+1,r);
    node temp;
    temp.merge(NL,NR);
    return temp;
}
void update(ll root,ll tl,ll tr,ll x,ll val)
{
    if(tr==tl)
    {
        tree[root].prefix = tree[root].suffix=tree[root].ans = tree[root].sum = val;
        return;
    }
    ll mid = tl+tr;mid>>=1;
    ll left = root<<1;
    ll right = left+1;
    if(x<=mid)update(left,tl,mid,x,val);
    else update(right,mid+1,tr,x,val);
    tree[root].merge(tree[left],tree[right]);
}
int main()
{
    ll n;
    n = scan_lld();
    for(int i=0;i<n;i++)ar[i] = scan_lld();
    ll m;
    ll x,y;
    build(1,0,n-1);
    m = scan_lld();
    while(m--)
    {
        ll f;
        f = scan_lld();;
        x = scan_lld();y = scan_lld();
        if(f)
        {
            x--,y--;
        node temp = query(1,0,n-1,x,y);
        println_lld(temp.ans);
        }
        else update(1,0,n-1,x-1,y);
    }
}

