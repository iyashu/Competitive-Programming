#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    long long q=1;
    while(1)
    {
    char a[10000];
    int k;char p='1';
   gets(a);
   if(a[0]=='-')break;
    k=strlen(a);
    int r=0;
    for(int i=0;i<k;i++)
   if(a[i]==p){r=r+1;if(p=='1')p='0';else p='1';}
   cout<<"Game #"<<q<<": "<<r<<endl;
   q++;
    }
    return 0;
}
