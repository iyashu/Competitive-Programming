#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 131072
#define MOD 1000000007
typedef long long ll;
ll norm(ll &num) {
    while(num >= MOD) num -= MOD;
    return num;
}
ll N, h;
ll tree[2 * MAXN], A[MAXN], M[MAXN], U[MAXN];
void calAdd(int p, ll k) {
    if(U[p] >= 0) {
        tree[p] = (U[p] * k) % MOD;
        return;
    }
    tree[p] = (tree[p << 1LL] + tree[((p << 1)|1)]);norm(tree[p]);
    tree[p] = ((tree[p] * M[p])) + ((A[p] * k));
    tree[p] %= MOD;
}
void apply(int p, ll valueAdd, ll valueMul, ll valueUpdate,ll k) {
 
    if(valueUpdate >=0 ) {
            tree[p] = (valueUpdate * k) % MOD;
            if(p < N) U[p] = valueUpdate;
            return;
    }
    tree[p] = ((tree[p] * valueMul)) + ((valueAdd * k) );tree[p] %= MOD;
    if(p < N) {
        M[p] = M[p] * valueMul;M[p] %= MOD;
        A[p] = (A[p] * valueMul) + valueAdd;A[p] %= MOD;
        if(U[p] >= 0) U[p] = (U[p] * valueMul + valueAdd) % MOD;
     }
}
void build(int p) {
    ll k = 1LL;
    while(p > 1) p >>= 1LL, k <<= 1LL, calAdd(p, k);
}
void push(int p) {
    ll k = (1LL << (h-1));
    for(int hh = h; hh > 0; --hh, k >>= 1LL) {
        int node = p >> hh;
        if((A[node] != 0) || (M[node] != 1) || (U[node] >= 0)) {
            apply(node << 1LL, A[node], M[node], U[node], k);
            apply(((node << 1LL)|1LL), A[node], M[node], U[node], k);
            A[node] = 0; M[node] = 1LL;U[node] = -1;
        }
    }
}
ll AA, MM, UU;
void update(int l, int r, ll value) {
    l += N; r += N;
    int sl = l, rl = r;
    push(l); push(r - 1);
    ll k = 1LL;
    for(; l < r; l >>= 1LL, r >>= 1LL, k <<= 1LL) {
        if(l & 1) apply(l++, AA, MM, UU, k);
        if(r & 1) apply(--r, AA, MM, UU, k);
    }
    build(sl);build(rl-1);
}
ll query(int l, int r) {
    l += N; r += N;
    push(l); push(r - 1);
    ll res = 0LL;
    for(; l < r; l >>= 1LL, r >>= 1LL) {
        if(l & 1) res += tree[l++];
        if(r & 1) res += tree[--r];
    }
    res = res % MOD;
    return res;
}
int main() {
    //freopen ("test.txt","r",stdin);
    //freopen ("out2.txt","w",stdout);
    ll Q, l, r, v, type;
    scanf("%lld %lld", &N, &Q);
    h = sizeof(int) * 8 - __builtin_clz(N);
    for(int i = 0; i < N; i++) A[i] = 0, M[i] = 1LL, U[i] = -1;
    for(int i = 0; i < N; i++) scanf("%lld", &tree[N + i]);
    for(int i = N - 1; i > 0; i--) tree[i] = tree[i << 1LL] + tree[((i << 1)|1)],norm(tree[i]);
    for(int i = 0; i < Q; i++) {
        scanf("%lld %lld %lld", &type, &l, &r);
        AA = 0; MM = 1LL; UU = -1;
        if(type == 1) {
            scanf("%lld", &v);
            // do add
            AA = v;
            update(--l, r, v);
        }
        else if(type == 2) {
            scanf("%lld", &v);
            // do mul
            MM = v;
            update(--l, r, v);
        }
        else if(type == 3) {
            scanf("%lld", &v);
            // do the assignment operation
            UU = v;
            update(--l, r, v);
        }
        else {
            // output the query
            printf("%lld\n", query(--l, r));
 
        }
    }
}
 
