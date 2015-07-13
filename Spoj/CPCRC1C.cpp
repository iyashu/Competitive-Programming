#include<iostream>
#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
int power[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int sum[]={0,1,3,6,10,15,21,28,36,45};
LL ans(LL p)
{
    LL n=p;
    LL cal =0 ;
    int digit[15];  
     int maxpow = 0;
    if(n/10==0)return sum[n];
    while(n/10>0)
    {
        digit[maxpow]=n%10;
        maxpow++;
        n/=10;
        
    }
   /* int sum_digit[15]={0};
    
    sum_digit[maxpow-1]=digit[maxpow-1];
    
    for(int i=maxpow-2;i>=0;i--)
    {
        sum_digit[i]=digit[i]+sum_digit[i+1];
    }
    
    for(int i=0;i<maxpow;i++)cout<<digit[i]<<" ";
    cout<<endl;
    for(int i=0;i<maxpow;i++)cout<<sum_digit[i]<<" ";
    cout<<endl;
    
    for(int i=0;i<maxpow;i++)
    {
        cal=cal + (sum_digit[i+1]*(digit[i]+1)*power[i])+(sum[digit[i]-1]*power[i])+(digit[i]*);
        
    }
    */
    cal = n*((p%power[maxpow])+1) + power[maxpow]*(sum[n-1])+((45*n*power[maxpow]*maxpow)/10) + ans(p%power[maxpow]);
    return cal;
    
}
int main()
{
    LL a,b;
    while(1)
    {
    scanf("%lld%lld",&a,&b);
    if(a!=-1 && b!=-1)
    printf("%lld\n",ans(b)-ans(a-1));
    else break;
}    
   return 0;
}
