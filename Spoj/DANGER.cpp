#include<iostream>
#include<math.h>
using namespace std;
int solve(int n)
{
   int x,y,z=0;
   x=int(pow(2.0,z*1.0));
   while(x<=n)
   {
      z=z+1;
      x=int(pow(2.0,z*1.0));
   } 
   z=z-1;
   return int(pow(2.0,z*1.0));
}
int main()
{
    while(1)
    {
    char str[6];
    cin>>str;
    int n;
    int x,y,z;
    x=str[0]-'0';
    y=str[1]-'0';
    z=str[3]-'0';
    if(x==0&&y==0&&z==0)break;
    z=int(pow(10.0,z*1.0));
    x=10*x;
    n=(x+y)*z;
    n=n-solve(n);
    n=2*n+1;
    cout<<n<<endl;
    }    
}
