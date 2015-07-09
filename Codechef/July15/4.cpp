#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
#define MAXN 100002
#define MAXK 501
ll dp[MAXN][MAXK],A[MAXN], S[MAXN], tree[2 * MAXN], X[MAXN];
struct node {
    ll L, R, C;
};
node J[MAXN];
bool compare(node a, node b) {
    return a.C > b.C;
}
void pre(int N) {
    for(int i = 0; i < (2*N); i++) tree[i] = 1000LL;
}
void update(int l, int r, ll value, int N) {
    for(l += N, r += N; l < r; l >>= 1LL, r >>= 1LL) {
        if(l & 1LL) tree[l] = min(tree[l], value), ++l;
        if(r & 1LL) --r, tree[r] = min(tree[r], value);
    }
}
void pushall(int N) {
    for(int i = 1; i < N; i++) {
        tree[i << 1LL] = min(tree[i << 1LL] , tree[i]);
        tree[(i << 1LL)|1LL] = min(tree[(i << 1LL)|1LL], tree[i]);
        tree[i] = 1000LL;
    }
}
vector<ll> V;
void solve() {
    ll N, K, M, LL, RR, CC;
    scanf("%lld %lld %lld", &N, &K, &M);
    for(int i = 0; i < N; i++) scanf("%lld", &A[i]);
    for(int i = 0; i < M; i++) {
        scanf("%lld %lld %lld", &LL, &RR, &CC);
        --LL;
        J[i].L = LL, J[i].R = RR, J[i].C = CC;
    }
    sort(J, J + M, compare);pre(N);
    for(int i = 0;i < M; i++) update(J[i].L, J[i].R, J[i].C, N);
    pushall(N);
    for(int i = 0;i < N; i++) S[i] = tree[N + i];
    ll ans = 0LL;
    int cnt = 0;
    vector<ll> v;
    for(int i = 0; i < N; i++)  {
        if((S[i] > 200) || (S[i] > K))X[cnt++] = i;
        else if(A[i] >= 0) X[cnt++] = i;
        else v.push_back(i);
    }
    for(int i = 0; i < cnt; i++) ans += A[X[i]];
    for(int i = 0; i < v.size(); i++)A[i] = -A[v[i]], S[i] = S[v[i]];
    ll sum = 0;
    for(int i = 0; i < v.size(); i++) sum += A[i];
    N = v.size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j++) {
            dp[i][j] = 0LL;
            if(i == 0) {
                if(j - S[i] >= 0)  dp[i][j] = A[i];
                continue;
            }
            if(j - S[i] < 0) dp[i][j] = dp[i -1][j];
            else dp[i][j] = max(dp[i - 1][j - S[i]] + A[i], dp[i -1][j]);
        }
    }
    ll temp = 0;
    if(N > 0) temp = dp[N - 1][K];
    sum -= temp;
    if(sum > 0) ans -= sum;
    V.push_back(ans);
}
int main() {
    int t; scanf("%d", &t);
    while(t--) solve();
    for(int i = 0; i < V.size();i++) printf("%lld\n",V[i]);
}
 
