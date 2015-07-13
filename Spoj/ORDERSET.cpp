#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

inline int ilog2(ll x)
{
	union Data {
		ll u64;
		double d;
	} n;
	n.d = double(x) + 0.5;
	return (n.u64 >> 52) - 1023;
}
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
    int findG(int bitMask,T upto)
    {
        int sz = v.size();
        int idx = 0;
        int ans = sz+1;
        while ((bitMask != 0) && (idx < sz)){
            int tIdx = idx + bitMask;
            if(tIdx >= sz){}
            else if(upto==v[tIdx]) ans = tIdx;
            else if (upto>v[tIdx])
            {
                idx = tIdx;
                upto -= v[tIdx];
            }
            bitMask >>= 1;
        }
        if (ans==(sz+1)) return -1;
        else return (ans-1LL);
    }
};

int H[30];
struct query
{
    ll q;
    ll x;
}A[200005];
vector<ll> V;
unordered_map<int,int> mp;
int main()
{
    ll Q,type,num;
    read(Q);
    for(int i=0;i<Q;i++)
    {
        read(A[i].q,A[i].x);
        if(A[i].q!=27)V.push_back(A[i].x);
    }
    sort(V.begin(),V.end());
    int sz = V.size();
    //for(int i=0;i<sz;i++)cout<<V[i]<<" ";cout<<endl;
    FenwickTree T;
    T.init(sz);
    int bitmask = 1LL<<(ilog2(sz));
    int idx;
    for(int i=0;i<Q;i++)
    {
        type = A[i].q;
        if(type==25)
        {
            if(mp[A[i].x])continue;
            mp[A[i].x]=1;
            idx = lower_bound(V.begin(),V.end(),A[i].x)-V.begin();
            T.add(idx,1);
        }
        else if(type==20)
        {
            if(!mp[A[i].x])continue;
            mp[A[i].x]=0;
            idx = lower_bound(V.begin(),V.end(),A[i].x)-V.begin();
            T.add(idx,-1);
        }
        else if(type==19)
        {
            idx = lower_bound(V.begin(),V.end(),A[i].x)-V.begin();
            writeln(T.sum(idx));
        }
        else
        {
            int ans = T.findG(bitmask,A[i].x);
            if(ans<0)puts("invalid");
            else writeln(V[ans]);
        }
    }
}
