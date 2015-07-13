#include <bits/stdc++.h>
using namespace std;
#define getchar getchar_unlocked
inline char getc(){char c;for(c=getchar();c<=32;c=getchar());return c;}
template<class T> inline void read(T&x){bool f=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')f=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(f)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
template<class T> inline void write(T x){if(x<0) putchar('-'),x=-x;if(x<10) putchar(x+'0');else{write(x/10);putchar(x%10+'0');}}
template<class T> inline void write_(T x){write(x);putchar(' ');}
template<class T> inline void writeln(T x){write(x);putchar('\n');}
template<class T> inline void writeln(T x,T y){write(x);putchar(' ');write(y);putchar('\n');}
template<class T> inline void writeln(T x,T y,T z){write(x);putchar(' ');write(y);putchar(' ');write(z);putchar('\n');}
template<class T> inline void writeln(T x,T y,T z,T q){write(x);putchar(' ');write(y);putchar(' ');write(z);putchar(' ');write(q);putchar('\n');}
class FenwickTree
{
    public:
    typedef long long T;
    vector<T> v;
    void init(int n){ v.assign(n+1,0); }
    void add(int i,T x){
        int sz = v.size();
        for(++i;i<sz;i+=(i & (-i)))v[i]+=x;
    }
    T sum(int i) const {	//[0, i)
		T r = 0;
		for(;i > 0; i-= (i & (-i))) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) - sum(left);
	}
};
typedef long long ll;
int t;
struct Road { int u, v; };
//vector< pair<ll,ll> > V;
Road V[1000005];
bool comp(const Road a, const Road b) {
	return ((a.u==b.u)? (a.v < b.v) : (a.u < b.u));
}

void solve()
{
    ll N,M,K,X,Y;
    read(N,M,K);
    for(int i=0;i<K;i++)
    {
        read(V[i].u,V[i].v);
    }
    ll ans = 0;
    sort(V,V+K,comp);
    int i = K-1;
    FenwickTree T;
    T.init(M+2);
    //memset(T,0,sizeof(T));
    for(;i>=0;i--)
    {
        int j;
        for(j=i;j>=0 && V[j].u==V[i].u;j--)ans+=(T.sum(V[j].v));
        for(j=i;j>=0 && V[j].u==V[i].u;j--)T.add(V[j].v,1);
        i = j+1;
    }
    printf("Test case %d: %lld\n",t,ans);
}
int main()
{
    int tt;
    read(tt);
    for(t = 1;t<=tt;t++)
    {
        solve();
    }
}
