#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
char str[MAXN];

class Node {
public:
    Node() {
        for(int i = 0; i < 26; i++) next[i] = 0;
        times = sufflink = len = 0;
    }
    int next[26];   //correspond to another Node when sandwiched to current Node
    int len;    // denotes the length of palindrome corresponding to Node
    int sufflink;   // denotes the suffix link of Node
    int times;      // denotes the number of times the palindrome occurs in string
    int start;      // denotes the start position of the first occurence of palindrome
    void clean() {
        for(int i = 0; i < 26; i++) next[i] = 0;
        start = times = sufflink = len = 0;
    }
};
class PalinTree {
public:
    int total, suff;    // suff denotes largest suffix palindrome of the processed prefix string
    vector <Node> tree;
    void construct(int N, char* str) {
        init(N);
        for(int i = 0; i < N; i++) add(i, str);
        propagate();
    }
    void init(int N) {
        tree.resize(N + 5);
        total = 2; suff = 2;
        tree[1].sufflink = tree[2].sufflink = 1;
        tree[1].len = -1; tree[2].len = 0;
    }
    // return true if new node is created, i.e new palindrome occurs;
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

    void propagate() {
        // propagates value of number of occurrence among the up to tree using suffix links;
        for(int i = total; i > 2; i--) {
            tree[tree[i].sufflink].times += tree[i].times;
        }
    }

    void clean() {
        for(int i = 0; i <= total; i++) tree[i].clean();
    }

};

void solve() {
    PalinTree T;
    int N;
    scanf("%d", &N);
    scanf("%s", str);
    N = strlen(str);
    T.construct(N, str);
    /*int maxi = 0;
    for(int i = 3; i <= T.total; i++) {
        maxi = max(maxi, T.tree[i].len);
    }*/
    int cnt = 0;
    for(int i = 3; i <= T.total; i++) {
        cnt += T.tree[i].times;
    }
    printf("%d\n", cnt);
    T.clean();
    //printf("%d\n", maxi);
 }
int main() {
    int t = 1;
    //scanf("%d", &t);
    while(t--) solve();
}
