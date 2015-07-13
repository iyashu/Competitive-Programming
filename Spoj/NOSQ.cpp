#include <bits/stdc++.h>
#define MAX 316
#define pb push_back
using namespace std;
vector<int> primes;
int flag[MAX] = {0};
int H[100001] = {0};
int ar[100001][10];
vector<int> v;
void mark(int val)
{
    int temp,i = val;
    int hh[10];
    for(int i=0;i<10;i++)hh[i] = 1;
    while(val>0)
    {
        temp = val%10;
        if(hh[temp])hh[temp]--,ar[i][temp]++;
        val/=10;
    }
}
void sieve()
{
    primes.pb(2);
    for(int i=4;i<=MAX;i+=2)flag[i] = 1;
    for(int i=3;i<18;i+=2)
    {
        if(!flag[i])
        {
            for(int j=i*i,k=i<<1;j<MAX;j+=k)
            {
                flag[j] = 1;
            }
        }
    }

    for(int i=3;i<MAX;i+=2)if(!flag[i])primes.pb(i);
    int  sz = primes.size();
    for(int i=0;i<sz;i++)
    {
        int j=primes[i]*primes[i];
        for(int k=j;j<100000;j+=k)H[j] = 1;
    }
    for(int i=1;i<100000;i++)if(H[i]==0)mark(i);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<=100000;j++)ar[j][i]+=ar[j-1][i];
    }
}
int main()
{
    sieve();
    int t,a,b,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&d);
        printf("%d\n",ar[b][d]-ar[a-1][d]);
    }
}
