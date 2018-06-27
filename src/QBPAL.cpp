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

BigInt bigint(int x) {
	BigInt a;
	a.ep(x);
	return a;
}


BigInt operator + (BigInt a, BigInt b) {
	BigInt c;
	int v = 0;
	FOR(i, 0, max(a.size(), b.size()) - 1) {
		if (i < a.size()) v += a[i];
		if (i < b.size()) v += b[i];
		c.ep(v%base);
		v /= base;
	}
	if (v) c.ep(v);
	return c;
}

BigInt operator - (BigInt a, BigInt b) {
	BigInt c;
	int v = 0;
	FOR(i,0,a.size()-1) {
		v += a[i] - (i < b.size() ? b[i] : 0);
		if (v < 0) c.ep(v+base), v = -1;
		else c.ep(v), v = 0;
	}
	return c;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	char s[200];
	int n;
	BigInt F[200][200];
	scanf("%s\n", s);
	n = strlen(s)-1;

	FOD(i,n,0)
	FOR(j,i,n) {
		if (i == j) F[i][j] = bigint(1);
		else {
			if (i == j-1) {
				if (s[i] == s[j]) F[i][j] = bigint(3);
				else
					F[i][j] = bigint(2);
			} else {
				F[i][j] = F[i+1][j] + F[i][j-1] - F[i+1][j-1];
				if (s[i] == s[j])
					F[i][j] = F[i][j] + F[i+1][j-1] + bigint(1);
			}
		}
	}

	Print(F[0][n]);

	return 0;
}
