#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;
#define MOD 1000000007
typedef long long ll;
ll dp[100][10];
ll N, K;
void brute() {
    for(int i = 0; i < 10; i++) dp[1][i] = 1;dp[1][0] = 0;
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 10; j++) {
            dp[i][j] = 0;
            for(int k = j + K; k < 10; k++) dp[i][j] += dp[i - 1][k];
            int diff = j - K;
            if(K == 0) diff--;
            for(int k = diff; k >= 0; k--) dp[i][j] += dp[i - 1][k];
            dp[i][j] %= MOD;
            //printf("%d ", dp[i][j]);
        }
        //printf("\n");
    }
    ll ans = 0;
    for(int i = 0 ; i < 10; i++) ans += dp[N][i];
    printf("%lld\n", ans % MOD);
}
ll T[10][10];
ll ans[10][10];
ll temp[10][10];
ll A[10][10];
void norm(int& num) {
    if(num >= MOD) num -= MOD;
}
void getTemp(ll (*T)[10]) {
    for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) A[i][j] = temp[i][j] = 0;
    for(int i = 0; i < 10; i++) {
        int upper = i + K;
        int lower = i - K;
        if(upper == lower)lower--;
        for(int j = 0; j < 10; j++) {
            if(j < upper && j > lower) continue;
            for(int k = 0; k < 10; k++) {
                temp[i][k] += T[j][k];
                if(temp[i][k] >= MOD) temp[i][k] -= MOD;
            }
        }
    }
}

void solve() {
    scanf("%lld %lld", &N, &K);
    //brute();
    for(int i = 0 ; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(i == j) T[i][j] = 1;
            else T[i][j] = 0;
        }
    }
    for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) ans[i][j] = 0;
    int logn = 0;
    int flag = 1;
    while((1LL << logn) <= N) logn++;logn--;

    for(int i = 1; i <= logn; i++) {
        getTemp(T);
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 10; l++) {
                    A[j][l] += T[j][k] * temp[k][l];
                    if(A[j][l] >= MOD) A[j][l] %= MOD;
                }
            }
        }
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                T[j][k] = A[j][k];
            }
        }
        if(N & (1LL << i)) {
            getTemp(T);
            if(flag) {
                if(N & 1) {
                    for(int j = 0; j < 10; j++) {
                        ans[j][j] = 1;
                    }
                } else {
                    for(int j = 0; j < 10; j++) {
                        for(int k = 0; k < 10; k++) {
                            ans[j][k] = T[j][k];
                        }
                    }
                    flag = 0;
                    continue;
                }
                flag = 0;
            }
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 10; k++) {
                    for(int l = 0; l < 10; l++) {
                        A[j][l] += ans[j][k] * temp[k][l];
                        if(A[j][l] >= MOD) A[j][l] %= MOD;
                    }
                }
            }
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 10; k++) {
                    ans[j][k] = A[j][k];
                }
            }
        }
    }
    ll sum = 0;
    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++)
            sum = sum + ans[i][j];
            if(sum >= MOD) sum = sum % MOD;
    }
    printf("%lld\n", sum);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
}
