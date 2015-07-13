#include<cstdio>
#include<iostream>
using namespace std;
long long fact(int n)
{
long long k;
if(n==0)
return(1);
else
{
k=n*fact(n-1);
}
return(k);
}

int main()
{

    int n,i,k;
    unsigned int a[13];
    long long x;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        i=0;
        x=fact(n);
        while(i<k)
        {
            cin>>a[i];
            x=x/fact(a[i]);
            i++;

        }
    cout<<x<<endl;
    }

}
