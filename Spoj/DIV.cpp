#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000
#define pb push_back
using namespace std;
vector<int> primes;
int flag[1000006] = {0};
int small[1000006] = {0};
vector<int> v;
int H[1000006];
void sieve()
{
    primes.pb(2);

    small[2] = 2;flag[0] = flag[1]  = small[1] = 1;
    for(int i=4;i<=MAX;i+=2)small[i] = 2,flag[i] = 1;
    for(int i=3;i<=MAX;i+=2)small[i] = i;
    for(int i=3;i<1000;i+=2)
    {
        if(!flag[i])
        {
            for(int j=i*i,k=i<<1;j<MAX;j+=k)
            {
                if(flag[j])continue;
                flag[j] = 1;
                small[j] = i;
            }
        }
    }
    ll temp ;
    for(int i=6;i<MAX;i++)
    {
        //if(small[i]==0)cout<<i<<endl
        if(!flag[i/small[i]] && i/small[i]!=small[i])H[i] = 1;
    }
    for(int i=6;i<=MAX;i++)
    {
        temp = i;
        ll ans = 1;
        while(small[temp]>1)
        {
            int cnt = 1;
            int first = small[temp];
            while(first==small[temp])temp/=small[temp],cnt++;
            ans*=cnt;
        }
        if(H[ans])v.pb(i);
    }
    int  sz = v.size();
    for(int i=8;i<sz;i+=9)printf("%d\n",v[i]);
}
int main()
{
    sieve();
}
