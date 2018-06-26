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

void Set(BigInt &a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
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
	FOR(i, 0, max(a.size(), b.size())-1) {
		if (i < a.size()) v += a[i];
		if (i < b.size()) v += b[i];
		c.pb(v%base);
		v /= base;
	}
	if (v) c.pb(v);
	Set(c);
	return c;
}

BigInt operator - (BigInt a, BigInt b) {
	Set(a);
	Set(b);
	BigInt c;
	int v = 0;
	FOR(i, 0, a.size()-1) {
		v += a[i] - (i < b.size() ? b[i] : 0);
		if (v < 0) c.pb(v+base), v = -1;
		else c.pb(v), v = 0;
	}
	Set(c);
	return c;
}


const int N = 10005;
int n, k;
BigInt F[N][2], S, P2[N];


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&k);

	FOR(i,0,k-1) F[i][0] = F[i][1] = bigint(0);
	F[k][0] = bigint(1);
	F[k][1] = bigint(0);

	P2[0] = bigint(1);
	FOR(i,1,n-k) P2[i] = P2[i-1] + P2[i-1];

	S = bigint(0);
	FOR(i,k+1,n) {
		S = S + F[i-1][1] - F[i-k][1];
		F[i][1] = F[i-1][0] + F[i-1][1];
		F[i][0] = S + P2[i-k];
	}
	Print(F[n][0]+F[n][1]);

	return 0;
}
