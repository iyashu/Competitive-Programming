#include <stdio.h>
using namespace std;
typedef long long ll;
void solve() {
    ll N, K, T;
    scanf("%lld %lld", &N, &K);
    ll ans = 0, curr = 0;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &T);
        if(T < curr){curr -= T, curr--;continue; }
        else if(T >= curr) T -= curr, curr = 0;
        ll TT = (T/K); ans = ans + TT;
        TT = T - TT * K;
        if(TT != 0)ans ++, curr = K - TT, curr--;
    }
    printf("%lld\n", ans);
}
int main() {
    int t; scanf("%d", &t);
    while(t--) solve();
}
 
