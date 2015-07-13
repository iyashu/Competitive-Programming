#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX 1000001
inline ll ipow(ll a,ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)ans = ans*a;
        a = a*a;
        b>>=1;
    }
    return ans;
}
ll small[MAX];
ll W[MAX];
int main()
{
    for(int i=0;i<MAX;i+=2)small[i]=2;
    for(int i=1;i<MAX;i+=2)small[i] = i;
    for(int i=3;i<1000;i+=2)
    {

        for(int j=i*i,k=i<<1;j<MAX;j+=k)
        {
            if(small[j]==j)small[j] = i;
        }
    }
    W[1] = 1;
    ll temp,next,ans ;
    ll cnt ;
    for(int i=2;i<MAX;i++)
    {
        temp = small[i];
        int j = i/temp;
        cnt = 1;
        while(temp == small[j])
        {
            cnt++;
            j/=temp;
        }
        next = ipow(temp,cnt);
        cnt = next*next*temp + 1LL;
        //if(i==1321)cout<<cnt<<endl;
        cnt/=(temp+1);
        W[i] = W[i/next]*cnt;
    }
    int t;
    scanf("%d",&t);
    //freopen ("LCMSUM.txt","w",stdout);
    for(ll i=1;i<=t;i++)
    {
        ll n ;
        scanf("%lld",&n);
        //cout<<W[n]<<endl;
        ans = W[n]-1;
        if(ans&1) ans*=(n>>1);
		else ans>>=1,ans*=n;
		ans+=n;
        printf("%lld\n",ans);

    }
    //fclose (stdout);
}
