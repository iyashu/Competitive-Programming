#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int n,a[200],carry,y;
        cin>>n;
        a[0]=1;
        for(int j=1;j<200;j++)a[j]=0;
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<200;i++)
            {
                a[i]=a[i]*j;
                for(;a[i]>=10;i++)
                {
                    a[i+1]=(a[i]/10)+(a[i+1]*j);
                    a[i]=a[i]%10;
                    if(a[i+1]<10)
                    {
                        i=i+1;
                        break;
                    }    
                }
            }
        }
        
        int count=0;
        for(int i=199;i>=0;i--)
        {
            if(a[i]%10==0) count++;
            else break;
        }
        for(int i=(199-count);i>=0;i--)
        cout<<a[i];
        cout<<endl;
    }
  
    return 0;
}
