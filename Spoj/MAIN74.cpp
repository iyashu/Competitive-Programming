#include<stdio.h>
#include<string.h>
        typedef unsigned long long ll;
        ll  MOD= 1000000007;
        ll Fibo(ll n)
            {
                int i,j,k;
                ll  fib[2][2]={{1,1},{1,0}},ret[2][2]={{1,0},{0,1}},tmp[2][2]={{0,0},{0,0}};
                while(n)
                {
                    if(n&1)
                    {
                 memset(tmp,0,sizeof tmp);
                        for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++)
                                tmp[i][j]=(tmp[i][j]+ret[i][k]*fib[k][j])%MOD;
                        for(i=0;i<2;i++) for(j=0;j<2;j++) ret[i][j]=tmp[i][j];
                    }
                    memset(tmp,0,sizeof tmp);               
                    for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++)
                                           tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j])%MOD;
                                for(i=0;i<2;i++) for(j=0;j<2;j++) fib[i][j]=tmp[i][j];
                    n/=2;
         
                }
                return (ret[0][1])%MOD;
            }
         
            int main()
            {
                ll t,m,n,k;
                for(scanf("%lld",&t);t>0;t--)
                {
                    scanf("%lld",&n);
                    if(n==0)k=0;
                    else if(n==1)k=2;
                    else k = (Fibo(n+3))%MOD;
                    printf("%lld\n",k);
                }
return 0;
            }
