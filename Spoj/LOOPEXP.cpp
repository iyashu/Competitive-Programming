#include<iostream>
#include<cstdio>
using namespace std;
double ar[1000000];
void fac()
{
    ar[0]=1;
    for(int i=1;i<1000000;i++)
    {
        ar[i]=ar[i-1]+(1.0/(i+1));
    }
}
int main()
{
    fac();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        printf("%0.14f\n",ar[n-1]);;
    }
}
