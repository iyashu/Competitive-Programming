#include <stdio.h>
#include <vector>
#include <complex>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
#define MAXN 100001
typedef long long ll;
typedef complex<double> base;
void FFT (vector<base> &a, bool invert) {   //  invert = 1 if we need to find the inverse FFT
    int n = a.size();
    if(n == 1) return;
    vector<base> x(n/2), y(n/2);
    for(int i = 0; i < (n/2); i++) x[i] = a[i<<1], y[i] = a[(i << 1LL) + 1];
    FFT(x, invert); FFT(y, invert);
    base w(1);double angle = ( (2*M_PI)/double(n) ) * (invert ? -1 : 1);
    base wn(cos(angle), sin(angle));
    for(int i = 0; i < (n/2); i++) {
        a[i] = x[i] + w * y[i];
        a[i + (n/2)] = x[i] - w * y[i];
        w = w * wn;
    }
    if(invert) for(int i = 0;i < n; i++)a[i] /= 2;
}
void mul(vector<int> &a, vector<int> &b, vector<int> &res) {
    vector<base> f1(a.begin(), a.end()); vector<base> f2(b.begin(), b.end());
    int n = 1;
    int sz1 = a.size(), sz2 = b.size();
    while(n < max(sz1,sz2)) n <<= 1LL;
    n <<= 1LL;
    f1.resize(n);f2.resize(n);
    FFT(f1, 0); FFT(f2, 0);
    for(int i = 0; i < n; i++) f1[i] = f1[i] * f2[i];
    FFT(f1, 1);
    res.resize(n);
    for(int i = 0; i < n; i++) res[i] = int(f1[i].real() + 0.5);
}
char A[MAXN], B[MAXN], ANS[MAXN];
void solve() {
    scanf("%s", A);int l1 = strlen(A);
    scanf("%s", B);int l2 = strlen(B);
    vector<int> a,b;
    for(int i = l1 - 1; i >= 0; i--)a.push_back(A[i] - 48);
    for(int i = l2 - 1; i >= 0; i--)b.push_back(B[i] - 48);
    vector<int> res;
    mul(a,b,res);
    int sz = res.size();
    for(int i = 1; i < sz; i++) res[i] = res[i] + (res[i-1]/10);
    int temp = res[sz-1];
    for(int i = 0; i < sz; i++) res[i] = res[i] % 10;
    if(!temp) {
        sz--;
        while(sz && res[sz] == 0) sz--;
        sz++;
    }
    int cnt = 0;
    while(temp) {
        ANS[MAXN - 1 - cnt] = temp % 10;
        temp /= 10;
        cnt++;
    }
    for(int i = 0; i < cnt; i++) ANS[i] = ANS[MAXN - 1 - i];
    for(int i = cnt; i < (cnt + sz); i++) ANS[i] = res[sz - 1 + cnt - i];
    cnt += sz;
    for(int i = 0; i < cnt; i++) printf("%d",ANS[i]);printf("\n");
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) solve();
}
