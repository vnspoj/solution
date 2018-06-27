#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int base = 1e8;
typedef vector<int> BigInt;

void Print(BigInt a) {
	printf("%d", a.back());
	FOD(i,a.size()-2,0) printf("%08d", a[i]);
	EL;
}

BigInt bigint(int x) {
	BigInt a;
	a.pb(x);
	return a;
}

BigInt operator + (BigInt a, BigInt b) {
	BigInt c;
	int v = 0;
	FOR(i,0, max(a.size(), b.size()) - 1) {
		if (i < a.size()) v += a[i];
		if (i < b.size()) v += b[i];
		c.pb(v%base);
		v/=base;
	}
	if (v) c.pb(v);
	return c;
}

BigInt operator * (BigInt a, int b) {
	BigInt c;
	int v = 0;
	FOR(i,0,a.size()-1) {
		v += a[i] * b;
		c.pb(v%base);
		v/=base;
	}
	if (v) c.pb(v);
	return c;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	char c[20000];
	scanf("%s\n", &c);
	BigInt F = bigint(1), cnt = bigint(1);
	FOR(i,0,strlen(c)-1) {
		if (c[i] == 'L') F = F * 2;
		else if (c[i] == 'R') F = F * 2 + cnt;
		else if (c[i] == '*')
			F = F * 5 + cnt, cnt = cnt * 3;
	}
	Print(F);

	return 0;
}
