#include<iostream>
#include<algorithm>
#include<math.h>
typedef long long LL;
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int main()
{
    LL test;
    float a[3];
    LL i;
    scanf("%lld", &test);
    for (i = 0; i < test; i++) {
 
        LL N, M, K;
        LL count = 0;
        float max;
        scanf("%lld %lld %lld", &N, &M, &K);
        printf("Case #%lld: ", i + 1);
        LL ans = N * K * M - 1;
        printf("%lld ", ans);
 
        while (N != 1 || K != 1 || M != 1) {
            count++;
 
            a[0] = N;
            a[1] = M;
            a[2] = K;
            sort(a, a + 3);
            max = a[2];
 
         
            if (((LL) max) == N) {
                N = (LL) ceil(max / 2);
                continue;
            } else if ((LL) max == M) {
                M = (long) ceil(max / 2);
                continue;
            } else if ((LL) max == K)
                K = (LL) ceil(max / 2);
        }
        printf("%lld\n", count);
    }
}
