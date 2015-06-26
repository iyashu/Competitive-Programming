#include <stdio.h>
#include <iostream>
#define MAXN 20005
typedef long long ll;
using namespace std;
ll tree[MAXN << 1LL];

void build(int N) {
    for(int i = N - 1; i > 0; i--) tree[i] = tree[(i << 1LL)] & tree[((i << 1LL)|1)];
}
int query(int l, int r, int N) {
    int ans = -1;
    for(l += N, r += N; l < r; l >>= 1LL, r >>= 1LL) {
        if(l & 1) { if(ans < 0) ans = tree[l++]; else ans = ans & tree[l++]; }
        if(r & 1) { if(ans < 0) ans = tree[--r]; else ans = ans & tree[--r]; }
    }
    return ans;
}
void solve() {
    ll N, K;
    scanf("%lld %lld", &N, &K);
    ll M = N >> 1LL;
    for(int i = 0; i < N; i++) scanf("%lld", &tree[i+ N]);
    build(N);
    if(K >= M) {
        int ans = query(0, N, N);
        for(int i = 0; i < N; i++) printf("%d ",ans);printf("\n");
    }
    else {
        for(int i = 0; i < N; i++) {
            int R = (i + K);if(R >= N) R -= N;
            int L = i - K;if(L < 0) L += N;
            int ansR, ansL;
            if(R < i) ansR = query(0, R + 1, N) & query(i, N, N);
            else ansR = query(i, R + 1, N);
            if(L > i) ansL = query(L, N, N) & query(0, i + 1, N);
            else ansL = query(L, i + 1, N);
            printf("%d ", ansL & ansR);
        }
        printf("\n");
    }
}
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
}
