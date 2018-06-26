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

void Print(BigInt a) {
	printf("%d", a.back());
	FOD(i,a.size()-2,0) printf("%09d", a[i]);
	EL;
}

BigInt bigint(int x) {
	BigInt a;
	a.ep(x);
	return a;
}

BigInt operator + (BigInt a, BigInt b) {
	BigInt c;
	int v = 0;
	FOR(i,0,max(a.size(), b.size())-1) {
		if (i < a.size()) v += a[i];
		if (i < b.size()) v += b[i];
		c.ep(v%base);
		v /= base;
	}
	if (v) c.ep(v);
	return c;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	int T, n;
	BigInt F[150];

	F[1] = bigint(1);
	F[2] = bigint(2);
	FOR(i,3,100) F[i] = F[i-1] + F[i-2];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		Print(F[n]);
	}

	return 0;
}
