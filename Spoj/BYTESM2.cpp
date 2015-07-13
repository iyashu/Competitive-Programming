#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
ll dp[101][101];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll h,w,temp;
        scanf("%lld%lld",&h,&w);
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                scanf("%lld",&temp);
                dp[i][j] = i-1>=0?max(dp[i-1][j],max(j+1<w?dp[i-1][j+1]:0,j-1>=0?dp[i-1][j-1]:0))+temp:temp;
            }
        }
        ll maxi = -1;
        for(int i=0;i<w;i++)
        {
            if(maxi<dp[h-1][i])maxi=dp[h-1][i];
        }
        printf("%lld\n",maxi);
    }
}
