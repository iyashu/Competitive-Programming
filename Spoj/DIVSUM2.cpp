#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
typedef unsigned long long ull;
#define MAXN 100000000LL
int flag[MAXN + 1];
vector<ull> primes;
int total;
void sieve() {
    for(int i = 3; i <= 10000; i++) {
        for(int j = i * i, k = i << 1LL; j <= MAXN; j += k) {
            flag[j] = 1;
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= MAXN; i += 2) if(!flag[i]) primes.push_back(i);
    total = primes.size();


}
ull ipow(ull a, ull b) {
    ull ans = 1ULL;
    while(b) {
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1ULL;
    }
    return ans;
}
void solve() {
    ull N;
    scanf("%llu", &N);
    ull NN = N;
    ull rootn = sqrtl(N);
    ull ans = 1ULL;
    for(int i = 0; ull(primes[i]) * primes[i] <= N && i < total; i++) {
        if(N % primes[i] == 0) {
            int cnt = 0;
            while(N % primes[i] == 0) {
                N /= primes[i];
                cnt++;
            }
            ans = ans * (ipow(primes[i], cnt + 1) - 1ULL);
            ans = ans / (primes[i] - 1);
        }
    }
    if( N > 1) ans = ans * (N + 1);
    ans = ans - NN;
    printf("%llu\n", ans);
}
int main() {
    int t;
    sieve();
    scanf("%d", &t);

    while(t--) solve();
}
