#include <iostream>
#include <stdio.h>
#include <string>
#include <assert.h>
using namespace std;
int check(string in) {
    if(in == "blue") return 0;
    if(in == "black") return 1;
    if(in == "red") return 2;
    if(in == "yellow") return 3;
    if(in == "orange") return 4;
    if(in == "green") return 5;
    assert(0);
    return -1;
}
bool Y(int a, int b, int c) {
    if(a == b && a == c) return true;
    return false;
}
void solve() {
    string in;
    int  front, back, left, right, top ,bottom;
    cin >> in;front = check(in);
    cin >> in;back = check(in);
    cin >> in;left = check(in);
    cin >> in;right = check(in);
    cin >> in;top = check(in);
    cin >> in;bottom = check(in);
    if(Y(front, top, left) || Y(front, top, right) || Y(front, bottom, left) || Y(front, bottom, right) || Y(back, top, left) || Y(back, top, right) || Y(back, bottom, left) || Y(back, bottom, right)) puts("YES");
    else puts("NO");
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
}
