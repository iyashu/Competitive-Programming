#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstdlib>
#include<string>

using namespace std;

int main()
{
    
    string a,b;
    while(cin>>a>>b)
    {
        string ans="";
        int ar[30]={0};
        int br[30]={0};
        int temp;
        for(int i=0;i<a.length();i++)
        {
            temp  = int(a[i])-97;
            ar[temp]++;
        }
        for(int i=0;i<b.length();i++)
        {
            temp =int(b[i])-97;
            br[temp]++;
        }
        for(int i=0;i<30;i++)
        {
            temp=min(ar[i],br[i]);
            ar[i]=temp;
            if(ar[i])
            {
                for(int j=0;j<ar[i];j++)
                {
                    ans+=(char(i+97));
                }
            }
        }
        printf("%s\n",ans.c_str());
    }
}
