#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 10004
#define MAXK 51
#define MOD 5000000
class FenwickTree
{
    public:
    typedef long long T;
    vector<T> v;
    void init(int n){ v.assign(n+1,0); }
    void add(int i,T x) {
        int sz = v.size();
        for(++i;i<sz;i+=(i & (-i)))v[i]+=x;
    }
    T sum(int i) const {	//[0, i)
		T r = 0;
		for(;i > 0; i-= (i & (-i))) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) - sum(left);
	}
    int findG(int bitMask,T upto)
    {
        // return smallest index i such that sum ([0,i]) = upto
        // bitMask is the largest power of 2 less than sz
        int sz = v.size();
        T store = upto;
        int idx = 0;
        int ans = sz;
        int flag = 0;
        while ((bitMask != 0) && (idx < sz)) {
            int tIdx = idx + bitMask;
            //if(tIdx >= sz){bitMask>>=1;continue;}
        if(upto==v[tIdx]) ans = min(ans,tIdx);
		if (tIdx < sz && upto>v[tIdx]) {
			idx = tIdx;
			upto -= v[tIdx];
		}
		bitMask >>= 1;
	}
	if (sum(ans)!=store) return -1;
	else return (ans-1LL);
    }
    void output()
    {
        int sz = v.size();
        for(int i=0;i<sz;i++)printf("%lld ", v[i]);printf("\n");
    }
};
int A[MAXN], B[MAXN];
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        B[i] = A[i];
    }
    sort(B, B + N);
    for(int i = 0; i < N; i++) {
        A[i] = lower_bound(B, B + N, A[i]) - B;
    }/*
    for(int i = 0; i < N; i++) B[i] = 0;
    int cnt = 0;
    for(int i = 0; i < N;i++) {
        if(B[A[i]]) continue;
        A[cnt++] = A[i];
        B[A[i]]++;
    }
    N = cnt;*/
    FenwickTree T[51];
    for(int i = 1; i <= K; i++) T[i].init(N + 1);
    for(int i = 0; i < N; i++) {
        //dp[i][1] = 1;
        long long temp = T[1].sum(A[i], A[i] + 1);
        T[1].add(A[i], 1 - temp);
        for(int j = 2; j <= K; j++) {
            long long sum = T[j - 1].sum(0, A[i]);
            //dp[i][j] = sum;
            temp = T[j].sum(A[i], A[i] + 1);
            sum = sum - temp;
            sum %= MOD;
            sum += MOD;
            if(sum >= MOD) sum -= MOD;
            T[j].add(A[i], sum);
        }
    }
    long long ans = T[K].sum(0, N + 1);
    ans = ans % MOD;
    printf("%lld\n", ans);
}
