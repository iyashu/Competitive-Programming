#include <stdio.h>
#include <algorithm>
using namespace  std;
#define MAXN 100005
char str[MAXN];
struct node {
    int next[26];
    int len;
    int sufflink;
    int times;
    int start;
}tree[MAXN];
int total;    // denotes the total number of nodes in palindromic tree, i.e total number of distinct palindrome
int suff;   // denotes the node corresponding to suffix-palindrome of current processed prefix string

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


void init() {
    total = 2;suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
}
void construct(int N, char* str) {
        //int N = strlen(str);
        init();
        for(int i = 0; i < N; i++) add(i, str);
        //propagate();
    }
void solve() {
    int N;
    scanf("%d", &N);
    scanf("%s", str);
    construct(N, str);
    int maxi = 0;
    //printf("%d\n", num);
    for(int i = 1; i <= total; i++) maxi = max(maxi, tree[i].len);
    printf("%d\n", maxi);
}
int main() {
    int t = 1;
    //scanf("%d", &t);
    while(t--) solve();
}
