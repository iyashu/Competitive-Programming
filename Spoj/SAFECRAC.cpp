#include <stdio.h>
using namespace std;
#define MAXN 100005
typedef long long ll;
ll dp[MAXN][10];
#define MOD 1000000007
void pre() {
    for(int i = 0; i < 10; i++) dp[0][i] = 1;
    for(int i = 1; i < MAXN; i++) {
        dp[i][0] = dp[i - 1][7];
        dp[i][1] = dp[i - 1][2] + dp[i - 1][4];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5];
        dp[i][3] = dp[i - 1][2] + dp[i - 1][6];
        dp[i][4] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7];
        dp[i][5] = dp[i - 1][2] + dp[i - 1][6] + dp[i -1][4] + dp[i - 1][8];
        dp[i][6] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9];
        dp[i][7] = dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8];
        dp[i][8] = dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9];
        dp[i][9] = dp[i - 1][6] + dp[i - 1][8];
        for(int j = 0; j < 10; j++) while(dp[i][j] >= MOD) dp[i][j] -= MOD;
    }
}
void solve() {
    int N;
    scanf("%d", &N);
    ll ans = 0;
    for(int i = 0 ; i < 10; i++) ans = ans + dp[N - 1][i];
    printf("%lld\n", ans % MOD);
}
int main() {
    int t;
    pre();
    scanf("%d", &t);
    while(t--) solve();
}
