#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long N, K, count = 0, i;
    scanf("%lld", &N);
    scanf("%lld", &K);
    long long input[N];
    for (i = 0; i < N; i++)
        scanf("%lld", &input[i]);
    sort(input, input + N);
    for (i = 0; i < N; i++)
        if (binary_search(input, input + N, input[i] + K))
            count++;
    printf("%lld", count);
}
