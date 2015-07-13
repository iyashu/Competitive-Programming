#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int swap(int& m,int& n)
{
    int temp = m;
    m=n;n=temp;
}
int upperbound(int *a, int st, int en, int val) {
    int idx, cnt, stp;
    cnt = en - st;
    while(cnt > 0) {
        stp = cnt >> 1; idx = st + stp;
        if(a[idx] > val) st = ++idx, cnt -= stp+1;
        else cnt = stp;
    }
    return st;
}

int main()
{
    int t,k,p;
    scanf("%d",&t);
    while(t--)
    {
        int n,j=0;
        scanf("%d",&n);
        int* ar=new int[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            
            if(ar[i]<ar[i+1]){p=i;k=upperbound(ar,i+1,n,ar[i]);swap(ar[i],ar[k-1]);break;}j++;
        }if(j==(n-1))printf("-1\n");else{
        for(int i=0;i<=p;i++)printf("%d",ar[i]);for(int i=n-1;i>p;i--)printf("%d",ar[i]);
        printf("\n");}
    }
}

