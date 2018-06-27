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

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt &a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}

void Print(BigInt a) {
	printf("%d", a.back());
	FOD(i,a.size()-2,0) printf("%09d", a[i]);
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
	ll v = 0;
	FOR(i,0,a.size()-1) {
		v += a[i] * (ll) b;
		c.pb(v%base);
		v/=base;
	}
	if (v) c.pb(v);
	return c;
}

BigInt operator * (BigInt a, BigInt b) {
	BigInt c(a.size() + b.size(), 0);
	FOR(i,0,a.size()-1) {
		ll v = 0;
		FOR(j,0,b.size()-1) {
			v += (ll) c[i+j] + (ll) a[i] * b[j];
			c[i+j] = v % base;
			v /= base;
		}
		if (v) c[i+b.size()] = v;
	}
	Set(c);
	return c;
}

//**************//
const int N = 2500;
BigInt F = bigint(1), S = bigint(0);
BigInt n = bigint(1), p4[N];
char c[N];
int f[N];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%s\n", &c);

	FOD(i, strlen(c)-1, 0) f[i] = f[i+1] + (c[i] == '*');
	p4[0] = bigint(1);
	FOR(i,1,f[0]) p4[i] = p4[i-1] * 4;

	FOR(i, 0, strlen(c)-1) {
		if (c[i] == '*') {
			BigInt t = (F * 9) + (n * 3);
			S = S + (t * p4[f[i]-1]);
			F = F + t;
			n = n * 4;
		} else {
			if (c[i] == 'L') F = F * 3;
			else if (c[i] == 'C') F = (F * 3) + n;
			else if (c[i] == 'R') F = (F * 3) + (n * 2);
			if (c[i] != 'S') S = S + (F * p4[f[i]]);
		}
	}
	Print(S + n);

	return 0;
}
