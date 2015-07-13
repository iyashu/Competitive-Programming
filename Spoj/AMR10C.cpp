#include<iostream>
#include<math.h>
#include<string.h>
//bool prime[1000005];

using namespace std;
/*bool isPrime(long long int n)
{
    if(n==2 || n==3)
	{
		return true;
	}
	if(n%2==0)
	{
		return false;
	}
	long long int sq=(long long int)sqrt(n);
	for(long long int i=3;i<=sq;i+=2)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}*/
long int primeNos[169];
void initializePrimeArray()
{
	primeNos[0]=2;
	primeNos[1]=3;
	primeNos[2]=5;
	primeNos[3]=7;
	primeNos[4]=11;
	primeNos[5]=13;
	primeNos[6]=17;
	primeNos[7]=19;
	primeNos[8]=23;
	primeNos[9]=29;
	primeNos[10]=31;
	primeNos[11]=37;
	primeNos[12]=41;
	primeNos[13]=43;
	primeNos[14]=47;
	primeNos[15]=53;
	primeNos[16]=59;
	primeNos[17]=61;
	primeNos[18]=67;
	primeNos[19]=71;
	primeNos[20]=73;
	primeNos[21]=79;
	primeNos[22]=83;
	primeNos[23]=89;
	primeNos[24]=97;
	primeNos[25]=101;
	primeNos[26]=103;
	primeNos[27]=107;
	primeNos[28]=109;
	primeNos[29]=113;
	primeNos[30]=127;
	primeNos[31]=131;
	primeNos[32]=137;
	primeNos[33]=139;
	primeNos[34]=149;
	primeNos[35]=151;
	primeNos[36]=157;
	primeNos[37]=163;
	primeNos[38]=167;
	primeNos[39]=173;
	primeNos[40]=179;
	primeNos[41]=181;
	primeNos[42]=191;
	primeNos[43]=193;
	primeNos[44]=197;
	primeNos[45]=199;
	primeNos[46]=211;
	primeNos[47]=223;
	primeNos[48]=227;
	primeNos[49]=229;
	primeNos[50]=233;
	primeNos[51]=239;
	primeNos[52]=241;
	primeNos[53]=251;
	primeNos[54]=257;
	primeNos[55]=263;
	primeNos[56]=269;
	primeNos[57]=271;
	primeNos[58]=277;
	primeNos[59]=281;
	primeNos[60]=283;
	primeNos[61]=293;
	primeNos[62]=307;
	primeNos[63]=311;
	primeNos[64]=313;
	primeNos[65]=317;
	primeNos[66]=331;
	primeNos[67]=337;
	primeNos[68]=347;
	primeNos[69]=349;
	primeNos[70]=353;
	primeNos[71]=359;
	primeNos[72]=367;
	primeNos[73]=373;
	primeNos[74]=379;
	primeNos[75]=383;
	primeNos[76]=389;
	primeNos[77]=397;
	primeNos[78]=401;
	primeNos[79]=409;
	primeNos[80]=419;
	primeNos[81]=421;
	primeNos[82]=431;
	primeNos[83]=433;
	primeNos[84]=439;
	primeNos[85]=443;
	primeNos[86]=449;
	primeNos[87]=457;
	primeNos[88]=461;
	primeNos[89]=463;
	primeNos[90]=467;
	primeNos[91]=479;
	primeNos[92]=487;
	primeNos[93]=491;
	primeNos[94]=499;
	primeNos[95]=503;
	primeNos[96]=509;
	primeNos[97]=521;
	primeNos[98]=523;
	primeNos[99]=541;
	primeNos[100]=547;
	primeNos[101]=557;
	primeNos[102]=563;
	primeNos[103]=569;
	primeNos[104]=571;
	primeNos[105]=577;
	primeNos[106]=587;
	primeNos[107]=593;
	primeNos[108]=599;
	primeNos[109]=601;
	primeNos[110]=607;
	primeNos[111]=613;
	primeNos[112]=617;
	primeNos[113]=619;
	primeNos[114]=631;
	primeNos[115]=641;
	primeNos[116]=643;
	primeNos[117]=647;
	primeNos[118]=653;
	primeNos[119]=659;
	primeNos[120]=661;
	primeNos[121]=673;
	primeNos[122]=677;
	primeNos[123]=683;
	primeNos[124]=691;
	primeNos[125]=701;
	primeNos[126]=709;
	primeNos[127]=719;
	primeNos[128]=727;
	primeNos[129]=733;
	primeNos[130]=739;
	primeNos[131]=743;
	primeNos[132]=751;
	primeNos[133]=757;
	primeNos[134]=761;
	primeNos[135]=769;
	primeNos[136]=773;
	primeNos[137]=787;
	primeNos[138]=797;
	primeNos[139]=809;
	primeNos[140]=811;
	primeNos[141]=821;
	primeNos[142]=823;
	primeNos[143]=827;
	primeNos[144]=829;
	primeNos[145]=839;
	primeNos[146]=853;
	primeNos[147]=857;
	primeNos[148]=859;
	primeNos[149]=863;
	primeNos[150]=877;
	primeNos[151]=881;
	primeNos[152]=883;
	primeNos[153]=887;
	primeNos[154]=907;
	primeNos[155]=911;
	primeNos[156]=919;
	primeNos[157]=929;
	primeNos[158]=937;
	primeNos[159]=941;
	primeNos[160]=947;
	primeNos[161]=953;
	primeNos[162]=967;
	primeNos[163]=971;
	primeNos[164]=977;
	primeNos[165]=983;
	primeNos[166]=991;
	primeNos[167]=997;
	primeNos[168]=1009;
	primeNos[169]=1013;
	primeNos[170]=1019;
}

#if 0
void generatePrime(long long int n)
{
	memset(prime,true,sizeof(prime));
	//prime[2]=true;
	//prime[3]=true;
	long long int j=2;
	for(;j<n;j++)
	{
		if(prime[j] && isPrime(j))
		{
			for(long long int k=j+j;k<n;k+=j)
			{
				prime[k]=false;
			}
		}
	}
	/*int c=0;
	for(long long int i=2;i<n;i++)
	{
		if(prime[i])
		{
			cout<<"primeNos["<<c<<"]="<<i<<endl;
			c++;
		}
	}
	cout<<c;*/
}
#endif

long int countFactors(long int n)
{
	//long int counterArray[170];
	//memset(counterArray,0,sizeof(counterArray));
	int max=0;
	long int ed=(long int)sqrt(n);
/*	while(n!=1)
	{
		int i=0;
		do
		{
			if(n%primeNos[i]==0)
			{
				counterArray[primeNos[i]]++;
				if(counterArray[primeNos[i]] > max)
				{
					max=counterArray[primeNos[i]];
				}
				n=n/primeNos[i];
				//i=167;
				goto out;
			}
			i++;
		}while(i<168);
out:;
	}*/
	for(long int i=0;primeNos[i]<=ed;i++)
	{
		int cnt=0;
		while(n%primeNos[i]==0)
		{
			n=n/primeNos[i];
			cnt++;
		}
		if(cnt>max)
		{
			max=cnt;
		}
		ed=(long int)sqrt(n);
	}

	if(max==0)
		max=1;

/*	for(int i=0;i<168;i++)
	{
		//cout<<"counterArray["<<i<<"]="<<counterArray[i]<<endl;
		if(counterArray[i] > max)
		{
			max=counterArray[i];
		}
	}*/
	return max;
}
int main()
{
	int t;
	scanf("%d",&t);
	initializePrimeArray();
	while(t--)
	{
		long int n;
		scanf("%ld",&n);
		printf("%ld\n",countFactors(n));
	}
	return 0;
}
