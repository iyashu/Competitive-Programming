#include <stdio.h>
#include <math.h>
#include <vector>
#include <assert.h>
#include <iostream>
using namespace std;
typedef long long ll;
long double R1, R2;
long double C1, C2;
bool equals(long double a, long double b) {
    if(fabs(a - b) <= (1e-3) ) return true;
    return false;
}
vector<long double> v;
int main() {
    ll T;
    scanf("%lld",&T);
    ll N0, P, M, B;
    scanf("%lld %lld %lld %lld", &N0, &P, &M, &B);
    long double r1, r2, r3, r4;
    scanf("%Lf %Lf %Lf %Lf", &r1, &r2, &r3, &r4);
    C1 = r1 * r2; C2 = r1 - r2;
    long double num = r3;
    long double a = (C2 * r3) / C1;
    long double c = 1l;
    long double b = (r3 * (C2 - r3)) / C1;
    b = sqrtl(b);
 
    v.push_back(r1);v.push_back(r2);v.push_back(r3);v.push_back(r4);
    long double den1 = a + c;
    long double den2 = 2l * b;
    R1 = num/(den1 - den2);
    R2 = num/(den1 + den2);
    if(equals(R1, r4)) den2 = -den2;
    long double ans = 0l;
    for(int i = 0; i < T; i++) {
        N0 = ((P * N0) % M) + B;
        long double temp = ((N0 - 3) * (N0 - 3));
        if(N0 <= 4) {ans = ans + v[N0 - 1];continue;}
        long double den1 = a * (temp) + c;
        long double K = den2 *  (N0 - 3);
        //double den1 = (N0 - 3l) * (a * (N0 - 3l) + den2) + c;
        ans = ans + ( num /(den1 + K));
    }
    printf("%0.6Lf\n",ans);
}
