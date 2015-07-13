#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{
    int test, N, M, ans, i;
    int men[1001], women[1001];
 
    scanf("%d", &test);
    while (test--) {
 ans = 0;
 scanf("%d", &N);
 for (i = 0; i < N; i++)
     scanf("%d", &men[i]);
 for (i = 0; i < N; i++)
     scanf("%d", &women[i]);
 sort(men, men + N);
 sort(women, women + N);
 for (i = 0; i < N; i++)
     ans += men[i] * women[i];
 printf("%d\n", ans);
    }
    return 0;
}
