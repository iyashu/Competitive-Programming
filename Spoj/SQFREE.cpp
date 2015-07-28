#include <stdio.h>
#include <math.h>
using namespace std;
#define MAXN 10000000
typedef long long ll;
int miu[MAXN + 1], small[MAXN], primes[MAXN], total;
/*
    As we need to find the count of all the square-free number, we need to substract all the number which are not square-free ..
    Inorder to do the above, we can inclusion-exclusion principle on the square of all the prime numbers less than N
    so, ans = n - (n / 4) - (n / 9) + (n / 36) . . .
    ans = sum of miu[i] * (n / (i * i)) over i = 1 to sqrt(n)
*/
void pre() {
    miu[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        if(!small[i]) {
            // i is prime
            small[i] = i;
            miu[i] = -1;
            primes[total++] = i;
        }
        int upto = MAXN / i;
        for(int j = 0; j < total && primes[j] <= upto; j++) {
            small[i * primes[j]] = primes[j];
            if(small[i] == primes[j]) {
                miu[i * primes[j]] = 0;
                break;
            }
            else miu[i * primes[j]] = -miu[i];
        }
    }
}
void solve() {
    ll N, ans = 0;
    scanf("%lld", &N);
    //for(int i = 1; i < 15; i++) printf("%d ", miu[i]);printf("\n");
    ll upto = sqrtl(N);
    for(int i = 1; i <= upto; i++) {
        ans = ans + (miu[i]) * (N / (ll(i) * i));
    }
    printf("%lld\n", ans);
}
int main() {
    int t;
    total = 0;pre();
    scanf("%d", &t);
    while(t--) solve();
}
