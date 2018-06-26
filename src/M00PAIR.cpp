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
	Set(a);
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
	Set(a);
	Set(b);
	BigInt c;
	int v = 0;
	FOR(i,0, max(a.size(), b.size()) - 1) {
		if (i < a.size()) v += a[i];
		if (i < b.size()) v += b[i];
		c.pb(v%base);
		v /= base;
	}
	if (v > 0) c.pb(v);
	Set(c);
	return c;
}

BigInt operator - (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt c;
	int v = 0;
	FOR(i,0,a.size()-1) {
		v += a[i] - (i < b.size() ? b[i] : 0);
		if (v < 0) c.pb(v+base), v = -1;
		else c.pb(v), v = 0;
	}
	Set(c);
	return c;
}

const int N = 1001;
BigInt F[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	F[1] = bigint(0);
	F[2] = bigint(1);
	FOR(i,3,1000) {
		F[i] = F[i-1] + F[i-1];
		if (i%2) F[i] = F[i] - bigint(1);
		else F[i] = F[i] + bigint(1);
	}

	int n;
	while (scanf("%d", &n) == 1) Print(F[n]);

	return 0;
}
