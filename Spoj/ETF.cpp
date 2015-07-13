#include<iostream>
using namespace std;
int phi(int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n=phi(n);
        cout<<n<<endl;
    }
}
int phi(int n)
{
     int result = n;
     int i;
       for(i=2;i*i <= n;i++) 
       { 
         if (n % i == 0) 
         result -= result / i; 
         while (n % i == 0) 
         n /= i; 
       } 
       if (n > 1)
       result -= result / n; 
       return result; 
}
