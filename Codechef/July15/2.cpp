#include <stdio.h>
using namespace std;
typedef long long ll;
ll cnt(ll num) {
    ll temp = num;
    ll cntt = 0, cnttt = 0;
    while(temp % 5 == 0) temp /= 5, cntt++;
    temp = num ;while(temp % 2 == 0)temp >>= 1LL, cnttt ++;
    return cntt - cnttt;
}
int main() {
    ll N,num;
    scanf("%lld", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &num);
        ll cntt = cnt(num) ;
        while(cntt > 0) num <<= 2LL, cntt -= 2;
        printf("%lld\n",num);
    }
}
