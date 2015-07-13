#include<iostream>
#include<stdio.h>
#include<math.h>


#define LL double
#define PI 3.14159265

#define max(a,b) ((a)>=(b) ? (a):(b))
#define min(a,b) ((a)<=(b) ? (a):(b))

using namespace std;

/*void replace(LL& x,LL& y)
{
	if(x<y)
	{
		LL temp = x;
		x=y;
		y=temp;
	}
}*/
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL  a,b,x,y;
		scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
		if(min(a,b)>min(x,y) && max(a,b)>max(x,y))
			{
				printf("Escape is possible.\n");
				continue;
			}
		
		if((a*b)>(x*y))
		{
			bool temp = false;
			LL theta=0.0;
			for(;theta<PI/4;theta+=0.002)
			{
				if(((((x*cos(theta)+y*sin(theta))<b) && ((y*cos(theta)+x*sin(theta))<a)) || (((x*cos(theta)+y*sin(theta))<a) && ((y*cos(theta)+x*sin(theta))<b))))
				{
					temp = true;
					break;
				}
			}
			if(temp)printf("Escape is possible.\n");
			else printf("Box cannot be dropped.\n"); 

		}
		else printf("Box cannot be dropped.\n");


	}
}



