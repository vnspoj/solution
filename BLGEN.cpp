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

const int N = 1001;
int n, m, F[N][N];
llu a[N], b[N];

llu sqrt3(llu x) {
	llu l = 1, r = 2154434, a;
	while (l <= r) {
		llu m = (l+r)/2;
		if (m*m*m <= x) {
			a = m;
			l = m+1;
		} else r = m-1;
	}
	return a;
}

bool prime(llu x) {
	if (x == 1) return false;
	if (x == 2) return true;
	llu t = sqrt(x);
	for (int i = 2; i < 6 && i*i <= x; i++)
		if (x%i == 0) return false;
	for (llu k = 1; 6*k+1 <= t; k++)
		if (x%(6*k+1) == 0 || x%(6*k+5) == 0) return false;
	return true;
}

bool check(llu x) {
	if (x == 0) return false;
	llu t = sqrt(x);
	if (t*t == x) return true;
	t = sqrt3(x);
	return (t*t*t == x && prime(t));
}

void read(llu *a, int &n) {
	string s;
	getline(cin, s);
	s = s + ' ';
	llu x = 0;
	FOR(i,0,s.size()-1) {
		if (s[i] == ' ') {
			if (check(x)) a[++n] = x;
			x = 0;
		} else x = x*10 + (s[i]-'0');
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	read(a,n);
	read(b,m);
	FOR(i,1,n)
	FOR(j,1,m) {
		F[i][j] = max(F[i-1][j], F[i][j-1]);
		if (a[i] == b[j])
			F[i][j] = max(F[i][j], F[i-1][j-1] + 1);
	}
	printf("%d\n", F[n][m]);

	return 0;
}
