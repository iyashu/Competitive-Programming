#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ll ar[101];
struct node
{
    ll val;
    ll B,C,D;
};
vector<ll> v;

vector<node> vv;
bool compare(node a,node b)
{
    if(a.val!=b.val)return a.val<b.val;
    return a.B<b.B;
}
int main()
{
    for(int i=1;i<101;i++)ar[i] = i*i*i;
    ll temp;
    node tt;
    for(int i=2;i<101;i++)for(int j=i;j<101;j++)for(int k=j;k<101;k++)temp = i*i*i + k*k*k+j*j*j,v.pb(temp),tt.val=temp,tt.B=i,tt.C=j,tt.D=k,vv.pb(tt);
    sort(v.begin(),v.end());
    sort(vv.begin(),vv.end(),compare);
    for(int i=2;i<101;i++)
    {
        temp = i*i*i;
        int idx = lower_bound(v.begin(),v.end(),temp)-v.begin();
        if(v[idx]==temp)
        {
            temp = upper_bound(v.begin(),v.end(),temp)-v.begin();
            for(int j=idx;j<temp;j++)
            {
                printf("Cube = %d, Triple = (%lld,%lld,%lld)\n",i,vv[j].B,vv[j].C,vv[j].D);
            }
        }
    }
}
