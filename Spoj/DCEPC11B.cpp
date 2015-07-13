// I am back :)

// Macros
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define vld vector<long double>
#define vpii vector< pair<int,int> >
#define vpll vector< pair<long long> >
#define PI pair<int,int>
#define PLL pair<long long,long long>
#define vs vector<string>
#define pb push_back
#define set_count __builtin_popcount
#define gcd __gcd

#if defined(_MSC_VER) || __cplusplus > 199711L // define the version of C++
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#ifdef DEBUGIT
  #define DEBUG(X) cerr << ">>> DEBUG(" << __LINE__ << ") " << #X << " = " << X << endl
#else
  #define DEBUG(X) (void)0
#endif


#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define reu(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define repr(i,n) for(int (i)=n;(i)>=0;i--)
#define repv(i,v) for(int (i)=0;(i)<sz(v);(i)++)


#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ms0(x) memset(x,0,sizeof(x))
#define ms1(x) memset(x,-1,sizeof(x))
#define INF 0x7fffffff
#define INFL 0x7fffffffffffffffLL

#define CASET int ___T,cas=1;scanf("%d",&___T);while(___T--)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define sd(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sld(x) scanf("%lf",&x)
#define sllu(x) scanf("%llu",&x)
#define pd(x) printf("%d",x)
#define pll(x) printf("%lld",x)
#define pld(x) printf("%lf",x)
#define pllu(x) printf("%llu",x)
#define NL printf("\n")
#define MOD 1000000007
using namespace std;
ll ipow(ll a,ll b,ll p)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)ans = ans*a %p;
        a = a*a % p;
        b>>=1;
    }
    return ans;
}
void solve()
{
    ll N,P;
    sll(N);sll(P);
    if(N>=P)
    {
        puts("0");
        return;
    }
    ll ans = P-1;
    ll temp = P-1;
    while(N!=temp)
    {
        ans = ans*(ipow(temp,P-2,P));
        ans = ans%P;
        DEBUG(ans);
        temp--;
    }
    pll(ans);NL;

}
int main()
{
    CASET solve();
}
