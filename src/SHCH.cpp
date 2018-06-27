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

void Print(BigInt a) {
	printf("%d", a.back());
	FOD(i,a.size()-2,0) printf("%09d", a[i]);
	EL;
}

BigInt bigInt(string s) {
	BigInt a;
	while (s.size() % 9 != 0) s = '0' + s;
	for (int i = s.size() - 1; i > 0; i -= 9) {
		int x = 0;
		FOR(j,i-9+1,i) x = x * 10 + s[j] - '0';
		a.pb(x);
	}
	return a;
}

BigInt bigInt(int x) {
	BigInt a;
	a.pb(x);
	return a;
}

void Set(BigInt &a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt operator * (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt c (a.size() + b.size() + 1, 0);
	FOR(i,0,a.size()-1) {
		ll g = 0ll;
		FOR(j,0,b.size()-1) {
			g += c[i+j] + (ll) a[i] * b[j];
			c[i+j] = g % base;
			g /= base;
		}
		if (g > 0) c[i+b.size()] += g;
	}
	Set(c);
	return c;
}

bool operator >= (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	if (a.size() != b.size())
		return (a.size() > b.size());
	FOD(i,a.size()-1,0)
	if (a[i] != b[i]) return a[i] > b[i];
	return true;
}

BigInt operator + (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt c;
	int g = 0;
	FOR(i, 0, max(a.size(), b.size()) - 1) {
		if (i < a.size()) g += a[i];
		if (i < b.size()) g += b[i];
		c.pb(g%base);
		g /= base;
	}
	if (g > 0) c.pb(g);
	Set(c);
	return c;
}

BigInt operator - (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt c;
	int g = 0;
	FOR(i,0, a.size()-1) {
		g += a[i];
		if (i < b.size()) g -= b[i];
		if (g >= 0) c.pb(g), g = 0;
		else c.pb(g+base), g = -1;
	}
	Set(c);
	return c;
}

//******************//
const int N = 111;
int n, k, a[N], dd[N];
BigInt F[N], x;
string s;

void solve1() {
	FOR(i,1,k) {
		int ord = 0;
		while (x >= F[k-i]) {
			x = x - F[k-i];
			ord++;
		}
		int cnt = 0;
		FOR(j,1,n) {
			if (cnt == ord && !dd[j]) {
				printf("%d%c", j, i == k ? '\n' : ' ');
				dd[j] = 1;
				break;
			}
			cnt += dd[j] == 0;
		}
	}
}

void solve2() {
	FOR(i,1,n) dd[i] = 0;
	x = bigInt(1);
	FOR(i,1,k) {
		int cnt = 0;
		FOR(j,1,a[i]-1) cnt += dd[j] == 0;
		x = x + F[k-i] * bigInt(cnt);
		dd[a[i]] = 1;
	}
	Print(x);
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&k);
	getline(cin, s);
	x = bigInt(s) - bigInt(1);
	FOR(i,1,k) scanf("%d", &a[i]);

	F[0] = bigInt(1);
	FOR(i,1,n) F[i] = F[i-1] * bigInt(n-k+i);

	solve1();
	solve2();

	return 0;
}
