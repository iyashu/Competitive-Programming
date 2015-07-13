#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ar[10000007];

int main()
{
    int t;
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    string st;
    while(t--)
    {
        ll n,temp;
        cin>>n;
        for(int i=0;i<n;i++)cin>>st>>ar[i];
        sort(ar,ar+n);
        ll ans = 0;
        for(int i=0;i<n;i++)ans+=abs(ar[i]-i-1);
        cout<<ans<<'\n';
    }
}
