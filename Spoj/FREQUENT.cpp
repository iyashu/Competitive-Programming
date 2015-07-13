#include <bits/stdc++.h>
#define ll long long
#define MAX 100005
using namespace std;
ll ar[MAX];
struct node
{
    ll left,ans,right;
}tree[4*MAX];

void build(ll root,ll tl,ll tr)
{
    if(tl==tr)//leaf node
    {
        tree[root].ans = tree[root].left = tree[root].right = 1;
        return ;
    }
    ll left = root<<1;
    ll right = left+1;
    ll mid = tl+tr;mid>>=1;
    build(left,tl,mid);
    build(right,mid+1,tr);
    if(ar[mid]==ar[mid+1])
    {
        tree[root].left = tree[left].left + tree[right].left*(ar[mid]==ar[tl]);
        tree[root].right = tree[right].right + tree[left].right*(ar[mid]==ar[tr]);
        tree[root].ans = max(max(tree[left].ans,tree[right].ans),tree[left].right+tree[right].left);
    }
    else
    {
        tree[root].left = tree[left].left;
        tree[root].right = tree[right].right;
        tree[root].ans = max(tree[left].ans,tree[right].ans);
    }
}

ll query(ll root,ll tl,ll tr,ll l,ll r)
{
    ll mid = tr+tl;mid>>=1;
    ll left = root<<1;ll right = left+1;
    if(tl==l && tr==r)return tree[root].ans;
    if(r<=mid && l>=tl)return query(left,tl,mid,l,r);
    if(l>=mid+1 && r<=tr)return query(right,mid+1,tr,l,r);
    ll L =  query(left,tl,mid,l,mid);
    ll R = query(right,mid+1,tr,mid+1,r);
    ll M;
    if(ar[mid]==ar[mid+1])
    {
        ll temp = min(tree[left].right,mid-l+1) + min(tree[right].left,r-mid);
        M = max(max(L,R),temp);
    }
    else
    {
        M = max(L,R);
    }
    return M;
}

int main()
{
   int n, q, i, u, v;
	while(scanf("%d", &n)==1 && n)
	{
		scanf("%d", &q);
		for(i = 0; i < n; i++)
			scanf("%d", &ar[i]);
		build(1, 0, n-1);
		for(i = 0; i < q; i++)
		{
			scanf("%d%d", &u, &v);
			if(u==v)
				printf("1\n");
			else
				printf("%d\n", query(1, 0, n-1, --u, --v));
		}
	}
	return 0;
}
