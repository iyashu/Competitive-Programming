#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
char a[1002]; 
while(scanf("%s",a)!=EOF)
{
      int l=strlen(a);
      int k[l];
      for(int i=0;i<l;i++)
      {
              if(int(a[i])<97) k[i]=1;
              else k[i]=0;
      }
      int cnt1=0,cnt2=0;
      for(int j=0,i=0;i<l;i++)
      {
              if(k[i]!=j) {cnt1++;j++;if(j==2)j=0;}
              else {j++;if(j==2)j=0;}
      }
      for(int j=1,i=0;i<l;i++)
      {
              if(k[i]!=j) {cnt2++;j++;if(j==2)j=0;}
              else {j++;if(j==2)j=0;}
      }
      cout<<min(cnt1,cnt2)<<endl;
}    
}
