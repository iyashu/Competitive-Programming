#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAXN 3003
int N;
char str[MAXN];
struct node {
    int next[26];
    int len, sufflink, times, start;
    // times denotes the number of times the given palindrome occurs
    // On Adding new letter we lazily propagate times via suffix links
}tree[MAXN];
int total, suff;
void init() {
    total = 2; suff = 2;
    tree[1].len = -1; tree[2].len = 0;
    tree[1].sufflink = tree[2].sufflink = 1;
}
bool add(int pos, char* str) {
        int curr = suff;
        int letter = str[pos] - 'a';
        while(1) {
            int curlen = tree[curr].len;
            if((pos - curlen - 1) >= 0 && (str[pos] == str[pos - curlen - 1])) break;
            curr = tree[curr].sufflink;
        }
        // curr is the largest suffix palindrome on which on sandwiching id str[pos] results in next suff

        // if it already exits
        if(tree[curr].next[letter]) {
            suff = tree[curr].next[letter];
            tree[suff].times ++;
            // if u wanna to store all the occurrence of this palindrome
            // then create a vector corresponding to this palindrome and push all its pos
            return false;
        }
        suff = ++total;
        tree[total].len = tree[curr].len + 2;
        tree[total].times = 1;
        tree[curr].next[letter] = total;

        if(tree[total].len == 1) {
            tree[total].sufflink = 2;
            tree[total].start = pos;
            return true;
        }
        tree[total].start = tree[curr].start - 1;
        while(1) {
            curr = tree[curr].sufflink;
            int curlen = tree[curr].len;
            if((pos - curlen - 1) >= 0 && str[pos] == str[pos - curlen - 1]) break;
        }
        tree[total].sufflink = tree[curr].next[letter];
    }

void clean() {
    memset(tree, 0, total * sizeof(tree[0]));
    total = suff = 0;
}
void propagate() {
    // propagates value of number of occurrence among the up to tree using suffix links;
    for(int i = total; i > 2; i--) {
        tree[tree[i].sufflink].times += tree[i].times;
    }
}
void construct(int N, char* str) {
        init();
        for(int i = 0; i < N; i++) add(i, str);
        propagate();
    }
void solve() {
    int N;
    scanf("%s", str);
    N = strlen(str);
    construct(N, str);
    // do some fun

    //printf("%d\n", total);
    int maxi = 0;
    for(int i = 3; i <= total; i++) {
        maxi = max(maxi, tree[i].len);
    }
    int cnt = 0;
    for(int i = 3; i <= total; i++) {
        if(tree[i].len == maxi) cnt += tree[i].times;
    }
    printf("%d %d\n", maxi, cnt);
    clean();
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
}
