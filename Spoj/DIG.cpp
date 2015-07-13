#include <stdio.h>
int main() {
    int t;
    scanf("%d",&t);

    long long n;
    long long answer;
    int i;
    for(i = 0; i < t; i++) {
        scanf("%lld",&n);
        long long x = ((n*(n-1)) % (24000000168));
        long long y = (x*(n-2)) % (24000000168);
        long long z = (y*(n-3)) % (24000000168);
        answer = z / 24;
        printf("%lld\n",answer);
    }

    return 0;
}
