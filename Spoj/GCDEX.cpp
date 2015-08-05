    #include <stdio.h>
    #include <assert.h>
    #include <vector>
    using namespace std;
    typedef long long ll;
    #define MAXN 1000000
    ll N;
    ll small[MAXN + 1], primes[MAXN + 1], phi[MAXN + 1], sum[MAXN + 1], C[MAXN + 1], B[MAXN + 1];
    int total;
    void pre() {
        phi[1] = sum[1] = 1;
        for(int i = 2; i <= MAXN; i++) {
            if(!small[i]) {
                small[i] = i;
                primes[total++] = i;
                phi[i] = i - 1;
            }
            int upto = MAXN / i;
            for(int j = 0; j < total && primes[j] <= upto; j++) {
                small[i * primes[j]] = primes[j];
                if(small[i] == primes[j]) {
                    phi[i * primes[j]] = phi[i] * primes[j];
                    break;
                }
                else phi[i * primes[j]] = phi[i] * (primes[j] - 1LL);
            }
        }
        for(int i = 2; i <= MAXN; i++) B[i] = phi[i];
        for(int i = 2; i <= 1000000; i++) {
            for(int j = i + i; j <= MAXN; j+= i) {
                B[j] += ll(i) * phi[j / i];
            }
        }
        for(int i = 1; i <= MAXN; i++) B[i] = B[i - 1] + B[i];
    }
    void solve() {
        ll ans = 0;
        printf("%lld\n", B[N]);/*
        for(int i = 1; i <= N; i++) {
            ll upto = N / i;
            ll nxt = N / upto;
            ans = ans + (sum[nxt] - sum[i - 1]) * C[upto];
            i = nxt;
        }
        printf("%lld\n", ans); */
    }
    int main() {
        total = 0;pre();
        vector<int> v;
        while(scanf("%lld", &N)==1 && N) {
            v.push_back(N);
            //solve();
        }
        for(int i = 0; i < v.size(); i++) N = v[i], solve();
        //assert(0);
    }
