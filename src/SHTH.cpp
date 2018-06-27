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

BigInt bigInt(string s) {
	BigInt a;
	while (s.size() % 9 != 0) s = '0' + s;
	for (int i = s.size() - 1; i > 0; i -= 9) {
		int x = 0;
		FOR(j,i-9+1,i) x = x * 10 + s[j] - '0';
		a.pb(x);
	}
	Set(a);
	return a;
}

BigInt bigInt(int x) {
	BigInt a;
	a.pb(x);
	return a;
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
	if (g) c.pb(g);
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

const int N = 333;
int n, k, a[N];
BigInt C[N][N], x;
string s;

void solve1() {
	int j = 0;
	FOR(i,1,k) {
		++j;
		while (j <= n) {
			if (k-i <= n-j && x >= C[k-i][n-j]) {
				x = x - C[k-i][n-j];
				j++;
			} else break;
		}
		printf("%d%c", j, i == k ? '\n' : ' ');
	}
}

void solve2() {
	x = bigInt(1);
	int j = 0;
	FOR(i,1,k) {
		j++;
		while (j < a[i]) {
			x = x + C[k-i][n-j];
			j++;
		}
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

	C[0][0] = bigInt(1);
	FOR(j,1,n)
	FOR(i,0,j)
	if (i == 0 || i == j) C[i][j] = bigInt(1);
	else C[i][j] = C[i][j-1] + C[i-1][j-1];

	solve1();
	solve2();

	return 0;
}
