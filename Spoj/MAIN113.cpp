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
using namespace std;
ll dp[33][3];
ll sum[33];
//827421
void solve()
{
    ll n;
    sll(n);
    //ll temp = powl(3,n);
    ll temp=sum[n];
    pll(temp);NL;
}
int main()
{
    sum[0] = 0;sum[1] = 3;sum[2] = 9;
    for(int i=3;i<33;i++)
    {
        sum[i] = sum[i-1]+sum[i-1]+sum[i-2];
    }
    //for(int i=3;i<33;i++)sum[i] = dp[i][0]+dp[i][1]+dp[i][2];
    CASET solve();

}
