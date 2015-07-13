#include <bits/stdc++.h>
typedef int ll;
using namespace std;
int scan_d()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
#define MAXN (1<<15)
using namespace std;
struct node
{
    ll sum;
    node *l,*r;
} buff[MAXN*50]; // pointer to node !!
typedef node* pNode;
ll A[MAXN];
ll B[MAXN];
pNode root[MAXN];
pNode allocate(ll num)
{
    static pNode start = buff;
    pNode result = start;
    start+=num;
    return result;
}
pNode update(pNode pre,ll left,ll right,ll val)
{
    // from [left,right)
    if(left==val && right==(val+1))
    {
        pNode temp = allocate(1);
        *temp = *pre;
        ++(temp->sum);
        //cout<<"Yash"<<endl;
        return temp;
    }
    pNode temp = allocate(1);
    //cout<<left<<" "<<right<<" "<<val<<endl;
    *temp = *pre;
    int mid = (left+right)>>1;
    if(val<mid)temp->l= update(temp->l,left,mid,val);
    else temp->r = update(temp->r,mid,right,val);
    ++(temp->sum);
    return temp;
}
pair<ll,bool> query(pNode u,pNode v,ll left,ll right,ll val) // we need to find the valth smallest element
{
    ll sum = v->sum - u->sum;
    if(left == (right-1))
    {
        // if its a leaf node
        if(val==sum) return make_pair(left,false);
    }
    if(sum<val)
    {
        // true indicates that we need to go towards right in thr range
        return make_pair(right,true);
    }
    if(left == (right-1))return make_pair(left,false);
    ll mid = (left+right)>>1;
    pair<ll,bool> temp = query(u->l,v->l,left,mid,val);
    if(!temp.second)return temp;
    return query(u->r,v->r,mid,right,val - v->l->sum +u->l->sum);
}
ll query2(pNode u,pNode v,ll left,ll right,ll val)
{

    if(val<left)return (v->sum-u->sum);
    if(val>=right)return 0;
    if(right-left==1)return 0;
    ll mid = (left+right)>>1;
    return (query2(u->l,v->l,left,mid,val) + query2(u->r,v->r,mid,right,val));
}
int main()
{
    ll n,idx,m,l,r,k;
    n = scan_d();
    //scanf("%lld",&m);
    for(int i=0;i<n;i++)
    {
        A[i] = scan_d();
        B[i] = A[i];
    }
    sort(A,A+n);
    for(int i=0;i<n;i++) B[i] = lower_bound(A,A+n,B[i])-A;
    // making the segment tree for zero node !! ;)
    allocate((MAXN<<1)-1);
    for(int i=MAXN-2;i>=0;i--)
    {
        buff[i].l = &buff[(i<<1)+1];
        buff[i].r = &buff[(i<<1)+2];
        buff[i].sum = 0;
    }
    root[0] = buff;
    for(int i=1;i<=n;i++)
        root[i] = update(root[i-1],0,MAXN,B[i-1]);
    m = scan_d();
    while(m--)
    {
        l = scan_d();r = scan_d();k = scan_d();
        idx = lower_bound(A,A+n,k)-A;
        if(A[idx]!=k)idx--;
        println_d(query2(root[l-1],root[r],0,MAXN,idx));
    }
}
