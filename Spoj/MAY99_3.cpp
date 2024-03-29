#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}
int main() {
	int a, b, c, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &a, &b, &c);
		if(c > a && c > b) printf("NO\n");
		else if(!c) printf("YES\n");
		else if(c == a || c == b) printf("YES\n");
		else if(c % gcd(a, b)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
