#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ar[10],len;
char st[60000];
ll H[] = {1,3,2,-1,-3,-2};
bool divisibleBy1()
{
    return true;
}
bool divisibleBy2()
{
    ll temp = st[len-1]-48;
    if(temp&1)return false;
    return true;
}
bool divisibleBy3()
{
    ll sum = 0;
    for(ll i=0;i<len;i++)sum+=(st[i]-48);
    if(sum%3)return false;
    return true;
}
bool divisibleBy4()
{
    if(len==1)
    {
        ll temp = st[0]-48;
        if(temp%4)return false;
        return true;
    }
    ll temp = st[len-2]-48;
    temp*=10;temp+=(st[len-1]-48);
    if(temp%4)return false;
    return true;
}
bool divisibleBy5()
{
    ll temp = st[len-1]-48;
    if(temp==0 || temp==5)return true;
    return false;
}
bool divisibleBy6()
{
    ll temp = st[len-1]-48;
    if(divisibleBy2() && divisibleBy3())return true;
    return false;
}
bool divisibleBy7()
{
    ll j = 0;
    ll temp = 0;
    for(ll i=len-1;i>=0;i--)
    {
        temp+=(H[j%6]*(st[i]-48));
        j++;
    }
    if(temp%7 !=0)return false;
    return true;
}
bool divisibleBy8()
{
    if(len<3)
    {
        ll temp=0;
        for(ll i=0;i<len;i++)temp = temp*10 + st[i]-48;
        if(temp&7)return false;
        return true;
    }
    ll temp=0;
    for(ll i=len-3;i<len;i++)temp = temp*10 + st[i]-48;
    if(temp&7)return false;
    return true;
}

bool divisibleBy9()
{
    ll sum = 0;
    for(ll i=0;i<len;i++)sum+=(st[i]-48);
    if(sum%9)return false;
    return true;
}
bool divisibleBy25()
{
    if(len==1) return false;
    ll temp = st[len-2]-48;
    temp*=10;temp+=(st[len-1]-48);
    if(temp%25)return false;
    return true;
}
bool divisibleBy(ll n)
{
    if(n==1)return divisibleBy1();
    if(n==2)return divisibleBy2();
    if(n==3)return divisibleBy3();
    if(n==4)return divisibleBy4();
    if(n==5)return divisibleBy5();
    if(n==6)return divisibleBy6();
    if(n==7)return divisibleBy7();
    if(n==8)return divisibleBy8();
    if(n==9)return divisibleBy9();
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",st);
        len = strlen(st);
        /*
        if(divisibleBy25())printf("Yes\n");
        else puts("No");
        */
        if(divisibleBy4() && divisibleBy7() && divisibleBy9())printf("Yes ");
        else printf("No ");
        if(divisibleBy25() && divisibleBy7() && divisibleBy3())printf("Yes\n");
        else printf("No\n");

    }
}
