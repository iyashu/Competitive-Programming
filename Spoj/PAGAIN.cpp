#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld; // 80 bits used for getting more precision
typedef unsigned long long ull;
typedef unsigned uint;
static const ll MOD_MAX = 1ULL << 62;
using namespace std;
inline ull mul_mod(ull a,ull b,ull mod, ld i)
{
    ull y = ull(ld(a) * ld(b) * i + ld(1) / 2);
    ull r = a * b - y * mod;
    if(ll(r)<0)r+=mod;
    return r;
}
inline uint mul_mod(uint a, uint b, uint mod, ld)
{
	return (ull(a) * b) % mod;
}
template <typename T>
T pow_mod(uint base, T exp, T mod, ld modi)
{
	T ret = 1;
	T q = base;
	while(exp)
	{
		if(exp & 1)
		{
			ret = mul_mod(ret, q, mod, modi);
		}
		exp >>= 1;
		q = mul_mod(q, q, mod, modi);
	}
	return ret;
}
template <typename T>
bool miller_rabin_pass(uint base, uint m, T exp, T mod, ld modi)
{
	T n = pow_mod(base, exp, mod, modi);
	if(n == 1) return true;
	for(uint i = 0; i < m; ++i)
	{
		if(n == mod - 1) return true;
		n = mul_mod(n, n, mod, modi);
	}
	return n == mod - 1;
}
inline uint ilog2(ull x) // Awesome Function return the log2(n)
{
	union Data
	{
		ull u64;
		double d;
	} n;
	n.d = double(x) + 0.5;
	return (n.u64 >> 52) - 1023;
}
bool miller_rabin(ull n)
{
    // using bases to make it deterministic
	static const uint BASES1[] = {2, 3};
	static const uint BASES2[] = {2, 299417};
	static const uint BASES3[] = {2, 7, 61};
	static const uint BASES4[] = {15, 176006322, 4221622697u};
	static const uint BASES5[] = {2, 2570940, 211991001, 3749873356u};
	static const uint BASES6[] = {2, 2570940, 880937, 610386380, 4130785767u};
	static const uint BASES7[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

	//if(n <= 1) return false;
	//if(n <= 3) return true;
	ull d = n - 1;
	uint s = ilog2(d & -d);
	d >>= s;
	uint bases_size;
	const uint* bases;
	if(n < 1373653)
	{
		bases_size = 2;
		bases = BASES1;
	}
	else if(n < 19471033)
	{
		bases_size = 2;
		bases = BASES2;
	}
	else if(n < 4759123141ull)
	{
		bases_size = 3;
		bases = BASES3;
	}
	else if(n < 154639673381ull)
	{
		bases_size = 3;
		bases = BASES4;
	}
	else if(n < 47636622961201ull)
	{
		bases_size = 4;
		bases = BASES5;
	}
    else if(n < 3770579582154547ull)
    {
		bases_size = 5;
		bases = BASES6;
	}
	else
	{
		bases_size = 7;
		bases = BASES7;
	}
	if(n < 0x100000000ULL)
	{
		for(uint rep = 0; rep < bases_size; ++rep)
		{
			if(!miller_rabin_pass<uint>(bases[rep], s, d, n, 0))
				return false;
		}
	}
	else
	{
		ld modi = ld(1) / n;
		for(uint rep = 0; rep < bases_size; ++rep)
		{
			if(!miller_rabin_pass<ull>(bases[rep], s, d, n, modi))
				return false;
		}
	}
	return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ull n;
        scanf("%llu",&n);
        if(n>7)
        {
            ull temp = (n-1)/6;
            ull x = temp*6;
            if(x+6 == n && miller_rabin(x+5))
            {
                printf("%llu\n",x+5);
                continue;
            }
            if(x+1==n)
            {
                if(miller_rabin(x-1))
                {
                    printf("%lld\n",x-1);
                    continue;
                }
                else x-=6;
            }
            ull ans ;
            while(1)
            {
                if(miller_rabin(x+1))
                {
                    x++;break;
                }
                if(miller_rabin(x-1))
                {
                    x--;break;
                }
                x-=6;
            }
            printf("%llu\n",x);
        }
        else if(n==3)puts("2");
        else if (n<=5)puts("3");
        else puts("5");
    }
}
