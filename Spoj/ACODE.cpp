#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll unsigned long long
using namespace std;
char S[5002];
ll ans[5002];
int main()
{
    ll temp;
    while(1)
    {
        scanf("%s",S);
        int len = strlen(S);
        if(S[0]=='0' && len ==1)break;
        memset(ans,0,sizeof(ans));
        ans[0] = 1ULL;
        
        for(int i=1;i<len;i++)
        {   
            temp = 0;
            if(S[i]=='0')
            {
                if(S[i-1]>'2')
                {
                    ans[len-1] = 0;
                    break;
                } 
                if(i>=2) ans[i] = ans[i-2];
                else ans[i]= 1ULL;
                continue;
            }
            else if((S[i-1]==int('1')) || ((S[i-1]=='2')&&(S[i]<='6')))
            {
                if(i>=2) temp = ans[i-2];
                else temp = 1ULL;
            }
            ans[i] = ans[i-1]+temp;
        }
        if(S[0]=='0')ans[len-1]=0;
        printf("%llu\n",ans[len-1]);
    }
}
