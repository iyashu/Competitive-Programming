#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ar[100005];
struct node
{
    ll ans,val;
    void merge(node& a,node& b)
    {
        val = max(a.val,b.val);
        ans = max(max(a.ans,b.ans),a.val+b.val);
    }
}tree[400005];
void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
        tree[v].val = tree[v].ans = ar[tl];
        return;
    }
    ll mid = tr+tl;mid>>=1;
    ll left = v<<1;ll right = left+1;
    build(left,tl,mid);
    build(right,mid+1,tr);
    tree[v].merge(tree[left],tree[right]);
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
        tree[root].val = tree[root].ans = val;
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
    ll n,q,x,y;
    string st;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)scanf("%lld",&ar[i]);
    build(1,0,n-1);
    scanf("%lld",&q);
    while(q--)
    {
        cin>>st;
        if(st=="Q")
        {
            scanf("%lld%lld",&x,&y);
            x--,y--;
            node temp = query(1,0,n-1,x,y);
            printf("%lld\n",temp.ans);
        }
        else
        {
            scanf("%lld%lld",&x,&y);
            x--;
            update(1,0,n-1,x,y);
        }
    }
}
