#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXN 1005
#define LMAXN 10
int parent[MAXN], level[MAXN], E[MAXN << 1LL ], L[MAXN << 1LL], H[MAXN], T[2*MAXN];
int M[LMAXN + 1][MAXN << 1LL];
vector<int> tree[MAXN];
int N;
int upto ;
void dfs(int start, int depth) {
    if(level[start] >= 0) return;
    E[upto] = start;
    L[upto] = depth;
    if(H[start] < 0) H[start] = upto;
    upto++;
    level[start] = depth;
    int cnt = tree[start].size();
    for(int i = 0; i < cnt; i++) {
        dfs(tree[start][i], depth + 1LL);
        E[upto] = start;
        L[upto] = depth;
        upto++;
    }
}
void solve() {
    upto = 0;

    int num;
    scanf("%d", &N);
    for(int i = 0; i <= N; i++) parent[i] = -1;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &num);
        tree[i].clear();
        for(int j = 0; j < num; j++) {
            int child; scanf("%d", &child);
            parent[child] = i;
            tree[i].push_back(child);
        }
    }
    for(num = 1; num <= N; num++) if(parent[num] <= 0) break;
    level[num] = 0;
    for(int i = 0; i <= N; i++) level[i] = -1, H[i] = -1;
    dfs(1, 0);
    int NN = upto;
    T[0] = 0; T[1] = 0; for(int i = 2; i <= 2*N; i++) T[i] = 1 + T[i >> 1LL];
    int LN = 0;
    while((1LL << LN) <= NN) LN++;
    for(int i = 0; i < NN; i++) M[0][i] = i;
    for(int i = 1; i < LN; i++) {
        ll rng = 1LL << i; --rng;
        for(int j = 0; j + rng < NN; j++) {
            if(L[M[i - 1][j]] <= L[M[i - 1][j + (rng >> 1LL) + 1]]) M[i][j] = M[i - 1][j];
            else M[i][j] = M[i - 1][j + (rng >> 1LL) + 1];
        }
    }


    //for(int i = 0; i < upto; i++) cout << E[i] << " ";cout << endl;
    //for(int i = 0; i < upto; i++) cout << L[i] << " ";cout << endl;
    //for(int i = 1; i <= N; i++) cout << H[i] << " ";cout << endl;

    int Q; scanf("%d", &Q);
    while(Q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u = H[u], v = H[v];
        if(u > v) swap(u, v);
        int idx = 0;
        int diff = v - u + 1LL;
        int minIdxLf = M[T[diff]][u];
        int minIdxRt = M[T[diff]][v - (1LL << T[diff]) + 1];
        if(L[minIdxLf] <= L[minIdxRt]) idx = minIdxLf;
        else idx = minIdxRt;
        printf("%d\n", E[idx]);
    }
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) { printf("Case %d:\n", i + 1); solve(); }
}
