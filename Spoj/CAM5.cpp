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
struct node
{
    vll adj;
}graf[100005];
int mark[100005];
void DFS(int src)
{
    mark[src] = 1;
    int sz = graf[src].adj.size();
    for(int i=0;i<sz;i++)
    {
        ll temp = graf[src].adj[i];
        if(mark[temp])continue;
        DFS(temp);
    }
}

void solve()
{
    ll n,e,a,b;
    sll(n);sll(e);
    for(int i=0;i<n;i++)mark[i] = 0;
    for(int i=0;i<n;i++)graf[i].adj.clear();
    for(int i=0;i<e;i++)
    {
        sll(a);sll(b);
        graf[a].adj.push_back(b);
        graf[b].adj.push_back(a);
    }
    ll cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(mark[i]==0){DFS(i);cnt++;}
    }
    pll(cnt);NL;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}
