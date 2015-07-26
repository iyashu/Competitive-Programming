#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
char op[10];
void solve() {
    map<int, int> mp;
    int N, num;
    scanf("%d", &N);
    int total = 0;
    for(int i = 0; i < N; i++) {
        scanf("%s %d", op, &num);
        if(op[0] == 'i') {
            int cnt = mp[num]++;
            if(cnt == 1) total++;
        }
        else {
            int cnt = mp.count(num);
            if(cnt != 0) {
                cnt = mp[num]--;//cout << cnt << " ";
                if(cnt == 2) total--;
                if(cnt == 1) mp.erase(num);
            }
        }
        int sz = mp.size();
        //map<int, int> ::iterator it = mp.begin();
        //for(; it != mp.end(); it++) cout << (it->first) << " " << (it -> second) << endl;
        //cout << sz << endl;
        if(total > 0 && sz > 1) puts("both");
        else if(total > 0) puts("homo");
        else if(sz > 1) puts("hetero");
        else puts("neither");
    }
}
int main() {
    int t = 1;
    while(t--) solve();
}
