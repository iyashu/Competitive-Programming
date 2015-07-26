#include <stdio.h>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAXN 200005
ll A[MAXN];
void solve() {
    ll a, b, c, n;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &n);
    A[1] = 1;ll sum = 1;
    priority_queue<ll, vector<ll>, greater<ll> > R;
    priority_queue<ll> L;
    int cntL = 1, cntR = 0;
    L.push(1);
    for(int i = 2; i <= n; i++) {
        ll mid = L.top();
        A[i] = (a * mid + b * i + c) % MOD;
        if(cntL > cntR) {
            if(mid <= A[i]) R.push(A[i]);
            else {
                L.push(A[i]);
                ll temp = L.top();
                L.pop();
                R.push(temp);
            }
            cntR++;
        }
        else {
            if(mid >= A[i]) L.push(A[i]);
            else {
                R.push(A[i]);
                ll temp = R.top();
                R.pop();
                L.push(temp);
            }
            cntL++;
        }
        sum += A[i];
     }
    printf("%lld\n", sum);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
}
