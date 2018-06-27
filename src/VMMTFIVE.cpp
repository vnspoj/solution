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

int d[6], c[6], a[6][6];

void output() {
	FOR(i,1,5) {
		FOR(j,1,5) printf("%d ", a[i][j]);
		EL;
	}
	exit(0);
}

void dq(int i, int j) {
	if (i == 6) {
		if (c[5] == 0) output();
		return ;
	}
	int l = max(1, max(d[i]-25*(5-j), c[j]-25*(5-i)));
	int r = min(25, min(d[i]-5+j, c[j]-5+i));
	if (l > 25 || r < 1 || l > r) return ;
	if (j == 5) l = r = d[i];
	FOR(x,l,r) {
		a[i][j] = x;
		d[i] -= x;
		c[j] -= x;
		if (j < 5) dq(i, j+1);
		else dq(i+1, 1);
		d[i] += x;
		c[j] += x;
		a[i][j] = 0;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	FOR(i,1,5) scanf("%d", &d[i]);
	FOR(i,1,5) scanf("%d", &c[i]);
	dq(1,1);

	return 0;
}
