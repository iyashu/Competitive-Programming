#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int b;
		scanf("%d",&b);
		if(b%3==2)
		{

			int x = (b-2)/3;
			printf("%d ",(b-2)/3);
			printf("%d\n",b-1-x);
			continue;
		}
		int  original[1000];
		original[0] = 1;
		int len_ori = 1;
		int bas = 1,carri = 0;
		while(1)
		{
			bas = (bas*2) + carri;
			carri = 0;
			if(bas>=b)
			{
				bas = bas-b;
				carri = 1;
			}
			if((bas==1)&&(carri==0))break;
			original[len_ori] = bas;
			len_ori++;
		}
		/*for(int i=len_ori-1;i>=0;i--)
		{
			cout<<original[i]<<" ";
		}
		cout<<endl;*/
		for(int i=2;i<b;i++)
		{
			int temp [1000];
			temp[0] = i;
			int len_temp = 1;
			int base = i;
			int carry = 0;
			while(1)
			{
				if(len_temp > len_ori)break;
				base = (base*2)+carry;
				carry = 0;
				if(base>=b)
				{
					base = base - b;
					carry = 1;
				}
				if ((base == i) && (carry ==0))break;
				temp[len_temp] = base;
				len_temp++;

			}
			if(len_temp<len_ori)
			{
				copy(temp,temp+len_temp,original);
				len_ori  = len_temp;
			}
		}
		for(int i=len_ori-1;i>=0;i--)
		{
			printf("%d ",original[i]);
		}
		printf("\n");
	}
}
