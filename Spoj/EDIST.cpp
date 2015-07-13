#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[2001][2001];
char* a = new char[2002];
char* b = new char[2002];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",a,b);
        ll A = strlen(a);
        ll B = strlen(b);
        for(int i=0;i<=A;i++)
            dp[0][i] = i;
        for(int i=0;i<=B;i++)
            dp[i][0] = i;
        for(int i=1;i<=B;i++)
        {
            for(int j=1;j<=A;j++)
            {
                if(a[j-1]==b[i-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        printf("%lld\n",dp[B][A]);
    }
}
