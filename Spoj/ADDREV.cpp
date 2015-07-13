#include<iostream>
#include<cmath>
using namespace std;
int rev(int n);
int main()
{
    int z;
    cin>>z;
    while(z--)
    {
    int x,y;
    cin>>x>>y;
    x=rev(x);y=rev(y);
    x=x+y;
    cout<<rev(x)<<endl;
    }    
 
    return 0;
}
int rev(int n)
{
    int r=1;int h=n;
    for(int i=0;;i++)
    {  
    if(h/10==0)break;
    else {r+=1;
    h=h/10;}
    }
    int a[r];
    for(int i=0;i<r;i++)
    {
    a[i]=n%10;n=n/10;
    }
    int p=r;long double k=0;
    for(int i=0;i<p;i++)
    {
    k=k+(a[i]*pow(10.0,r-1));r=r-1;
}    return k;
}
