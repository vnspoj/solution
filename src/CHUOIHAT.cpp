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

const int N = 700;
int n;
BigInt x, F[N][N], s[N];
string S;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	getline(cin, S);
	x = bigInt(S) - bigInt(1);

	FOR(i,1,n-1) F[i][0] = bigInt(0);
	FOR(i,n,2*n) F[i][0] = bigInt(1);
	s[2*n+1] = bigInt(0);
	FOR(j,1,n-1) {
		FOD(i,2*n,1) s[i] = s[i+1] + F[i][j-1];
		FOR(i,n-j,2*(n-j)) F[i][j] = s[i+1];
	}

	int j = 0;
	FOR(i,1,n) {
		j++;
		while (j < 2*n && x >= F[j][n-i]) {
			x = x - F[j][n-i];
			j++;
		}
		printf("%d ", j);
	}

	return 0;
}
