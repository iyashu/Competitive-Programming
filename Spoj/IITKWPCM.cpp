#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uint64;
typedef long double float80;
typedef long long ll;
typedef long long int64;
typedef unsigned uint;
typedef unsigned char uint8;

static const uint64 PRIME_MAX = 1024;
static const uint64 THRESHOLD = PRIME_MAX * PRIME_MAX;
static const uint64 POLLARD_RHO_M = 250;

static const uint64 MOD = 1000000000000000000ull;
static const float80 MOD_INV = float80(1) / MOD;
ll scan_lld()    {int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
void println_lld(ll n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

static const int primes[] = {
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031
};

inline uint xrand(void) {
	static uint x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	uint t = x ^ (x << 11); x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

inline uint randrange(uint n) {
	return (uint64(xrand()) * n) >> 32;
}

inline uint randrange(uint64) {
	return (uint64(xrand()) * 0xFFFFFFFF) >> 32;
}

template <typename T>
T gcd(T a, T b) {
	if(b > a) {
		T tmp = a;
		a = b;
		b = tmp;
	}
	while(1) {
		if(!b) return a;
		a-=b;if(a>=b){a-=b;if(a>=b){a-=b;if(a>=b){a-=b;if(a>=b){a%=b;}}}}
		if(!a) return b;
		b-=a;if(b>=a){b-=a;if(b>=a){b-=a;if(b>=a){b-=a;if(b>=a){b%=a;}}}}
	}
}

inline uint64 mul_mod(uint64 a, uint64 b, uint64 mod, float80 i) {
	uint64 y = uint64(float80(a) * float80(b) * i + float80(1) / 2);
	uint64 r = a * b - y * mod;
	if(int64(r) < 0)
		r += mod;
	return r;
}

static const uint64 MOD_MAX = 1ull << 62;

inline void mul_add_div_mod(uint64 a, uint64 c, uint64 mod, float80 modi, uint64& q, uint64& r) {
	q = uint64(float80(a) * modi + float80(1) / 2);
	r = a * MOD - q * mod + c;
	if(int64(r) < 0) {
		r += mod;
		--q;
	} else if(r >= mod) {
		q += r / mod;
		r %= mod;
	}
}

// 2^61 <= mod < 2^62
inline uint64 mul_add_mod(uint64 a, uint64 c, uint64 mod, float80 modi) {
	uint64 q = uint64(float80(a) * modi + float80(1) / 2);
	uint64 r = a * MOD - q * mod + c;
	if(int64(r) < 0) {
		return r + mod;
	} else if (r >= mod) {
		return r - mod;
	} else {
		return r;
	}
}

inline uint mul_mod(uint a, uint b, uint mod, float80) {
	return uint64(a) * b % mod;
}

inline uint64 square_add_mod(uint64 a, uint c, uint64 mod, float80 modi) {
	uint64 ret = mul_mod(a, a, mod, modi) + c;
	if(ret >= mod)
		ret -= mod;
	return ret;
}

inline uint square_add_mod(uint a, uint c, uint mod, float80) {
	return (uint64(a) * a + c) % mod;
}

template <typename T>
T pow_mod(uint base, T exp, T mod, float80 modi) {
	T ret = 1;
	T q = base;
	while(exp) {
		if(exp & 1) {
			ret = mul_mod(ret, q, mod, modi);
		}
		exp >>= 1;
		q = mul_mod(q, q, mod, modi);
	}
	return ret;
}

template <typename T>
bool miller_rabin_pass(uint base, uint m, T exp, T mod, float80 modi) {
	T n = pow_mod(base, exp, mod, modi);
	if(n == 1)
		return true;
	for(uint i = 0; i < m; ++i) {
		if(n == mod - 1)
			return true;
		n = mul_mod(n, n, mod, modi);
	}
	return n == mod - 1;
}

inline uint ilog2(uint64 x) {
	union Data {
		uint64 u64;
		double d;
	} n;
	n.d = double(x) + 0.5;
	return (n.u64 >> 52) - 1023;
}

bool miller_rabin(uint64 n) {
	static const uint BASES1[] = {2, 3};
	static const uint BASES2[] = {2, 299417};
	static const uint BASES3[] = {2, 7, 61};
	static const uint BASES4[] = {15, 176006322, 4221622697u};
	static const uint BASES5[] = {2, 2570940, 211991001, 3749873356u};
	static const uint BASES6[] = {2, 2570940, 880937, 610386380, 4130785767u};
	static const uint BASES7[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

	if(n <= 1) {
		return false;
	}
	if(n <= 3) {
		return true;
	}
	uint64 d = n - 1;
	uint s = ilog2(d & -d);
	d >>= s;

	uint bases_size;
	const uint* bases;
	if(n < 1373653) {
		bases_size = 2;
		bases = BASES1;
	} else if(n < 19471033) {
		bases_size = 2;
		bases = BASES2;
	} else if(n < 4759123141ull) {
		bases_size = 3;
		bases = BASES3;
	} else if(n < 154639673381ull) {
		bases_size = 3;
		bases = BASES4;
	} else if(n < 47636622961201ull) {
		bases_size = 4;
		bases = BASES5;
	} else if(n < 3770579582154547ull) {
		bases_size = 5;
		bases = BASES6;
	} else {
		bases_size = 7;
		bases = BASES7;
	}
	if(n < 0x100000000ull) {
		for(uint rep = 0; rep < bases_size; ++rep) {
			if(!miller_rabin_pass<uint>(bases[rep], s, d, n, 0))
				return false;
		}
	} else {
		float80 modi = float80(1) / n;
		for(uint rep = 0; rep < bases_size; ++rep) {
			if(!miller_rabin_pass<uint64>(bases[rep], s, d, n, modi))
				return false;
		}
	}
	return true;
}
int flag[1000001];
uint64 PN[1000000];
vector<uint64> vv;
#define MAXN 1000000000000000000ULL
void sieve()
{
    flag[0] = flag[1] = 1;
    PN[0] = 2;
    for(int i=3;i<1000;i+=2)if(flag[i]==0)for(int j=i*i,k=i<<1;j<1000001;j+=k)flag[j] =1;
    int j =1;
    for(int i=3;i<1000001;i+=2)if(flag[i]==0)PN[j++] = i;
    uint64 temp,curr;
    for(int i=1;i<j;i++)
    {
        temp = MAXN/PN[i];
        curr = PN[i];
        while(curr<=temp)
        {
            vv.push_back(curr);
            curr = curr*PN[i];
        }
        vv.push_back(curr);
    }
    sort(vv.begin(),vv.end());
}
typedef unsigned long long ull;
void print_llu(ull n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
ull scan_llu()    {int ip=getchar_unlocked();ull ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
void solve()
{
    uint64 m,n,temp;
    n = scan_llu();
    m = n-1;
    int ar[9];
    ar[0] = ar[1] = 0;
    ar[2] = 1;
    ar[3] = 2;ar[4] = 3;ar[5] = 4;ar[6] = 5;ar[7] = 6;ar[8] = 1;
    if(n<9){printf("%d\n",ar[n]);return;}
    if(!(n&1))n>>=1;
    temp = sqrtl(n);
    bool ff = temp*temp==n?1:0;
    bool f = miller_rabin(n) || (ff&&miller_rabin(temp)) || binary_search(vv.begin(),vv.end(),n);
    if(f)print_llu(m);
    else putchar_unlocked('1');
    putchar_unlocked('\n');
}
int main()
{
    int t;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}
