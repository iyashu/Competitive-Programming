#include<stdio.h>
#include<vector>
#define MOD 5000011
using namespace std;
vector<int>ans;
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++)
    {
        ans.push_back(0);
    }
    ans[0]=1;
    for(int i=1;i<=k;i++)
    {
        ans[i]=i+1;
    }
    for(int i=k+1;i<=n;i++)
    {
        ans[i]=(ans[i-1]+ans[i-(k+1)])%MOD;
    }
    printf("%d\n",ans[n]);
    ans.clear();

}
}
