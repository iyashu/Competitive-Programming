#include <bits/stdc++.h>
#define MAX 1000000
#define pb push_back
using namespace std;
vector<int> primes;
int flag[1000006] = {0};
vector<int> v;
void sieve()
{
    primes.pb(2);
    for(int i=4;i<=MAX;i+=2)flag[i] = 1;
    for(int i=3;i<1000;i+=2)
    {
        if(!flag[i])
        {
            for(int j=i*i,k=i<<1;j<MAX;j+=k)
            {
                flag[j] = 1;
            }
        }
    }

    for(int i=3;i<1000;i+=2)if(!flag[i])primes.pb(i);
    int  sz = primes.size();
    for(int i=0;i<sz;i++)
    {
        for(int kk=primes[i]*primes[i],k =kk;k<MAX;k+=kk)
                flag[k] = 0;
    }
    for(int i=0;i<MAX;i++)if(flag[i])v.pb(i);
    sz = v.size();
    for(int i=107;i<sz;i+=108)printf("%d\n",v[i]);
}
void solve()
{
    sieve();
}


int main()
{
    solve();
}

