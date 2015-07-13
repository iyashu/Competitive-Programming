#include <bits/stdc++.h>
#define ll long long
#define MAX 50001
#define INF 0x6fffffffffffffffLL
using namespace std;
struct node
{
    ll prefix,suffix,sum,ans;
}tree[4*MAX];
ll ar[MAX];
void combine(node& root,node a,node b)
{
    root.sum = a.sum+b.sum;
    root.prefix = max(a.prefix,a.sum+b.prefix);
    root.suffix = max(b.suffix,b.sum+a.suffix);
    root.ans = max(max(a.ans,b.ans),a.suffix+b.prefix);
}
node zero;
void build(ll root,ll tl,ll tr)
{
    if(tr==tl)
    {
        tree[root].prefix = tree[root].suffix=tree[root].sum = tree[root].ans = ar[tr];
        return;
    }
    ll mid = tr+tl;
    mid>>=1;
    ll left = root<<1;
    ll right = left+1;
    build(left,tl,mid);
    build(right,mid+1,tr);
    combine(tree[root],tree[left],tree[right]);
}
node query(ll root,ll tl,ll tr,ll l,ll r)
{
    if(l>r)return zero;
    if(tl==l && tr==r) return tree[root];
    ll mid = tr+tl;
    mid>>=1;
    ll left = root<<1;
    ll right = left+1;
    node temp;
    combine(temp,query(left,tl,mid,l,min(mid,r)),query(right,mid+1,tr,max(l,mid+1),r));
    return temp;
}
void update(ll root,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
        tree[root].prefix = tree[root].suffix=tree[root].sum = tree[root].ans = val;
    else
    {
        ll mid = tl+tr;mid>>=1;
        if(pos<=mid)update(root*2,tl,mid,pos,val);
        else update(root*2+1,mid+1,tr,pos,val);
        combine(tree[root],tree[root*2],tree[root*2+1]);
    }
}
int main()
{
    zero.ans = -INF;
    zero.sum = 0;
    zero.prefix = -INF;
    zero.suffix = -INF;
    ll n;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&ar[i]);
    }
    build(1,0,n-1);
    ll m;
    ll x,y,temp =1;
    scanf("%lld",&m);
    while(m--)
    {

        //scanf("%lld",&temp);
        scanf("%lld%lld",&x,&y);
        if(temp){ node res = query(1,0,n-1,x-1,y-1);printf("%lld\n",res.ans);}
        //else update(1,0,n-1,x-1,y);
    }
}
