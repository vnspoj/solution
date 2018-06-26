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

const int   N = 1010;
const ll    oo = 1e13;
int         n, m, k, i1, i2, J1, j2, g, l, r;
ll          f[N][N], x, res;

ll S(int i1, int J1, int i2, int j2) {
	return (f[i2][j2]+f[i1-1][J1-1]-f[i2][J1-1]-f[i1-1][j2]);
}

void solve1() {
	l = J1;
	r = j2-1;
	while (l <= r) {
		int j = (l+r)/2;
		res = min(res, abs(S(i1,J1,i2,j)-S(i1,j+1,i2,j2)));
		if (S(i1,J1,i2,j) <= S(i1,j+1,i2,j2)) l = j+1;
		else r = j-1;
	}
	if (l < j2-1) {
		l++;
		res = min(res, abs(S(i1,J1,i2,l)-S(i1,l+1,i2,j2)));
	}
}

void solve2() {
	l = i1;
	r = i2-1;
	while (l <= r) {
		int i = (l+r)/2;
		res = min(res, abs(S(i1,J1,i,j2)-S(i+1,J1,i2,j2)));
		if (S(i1,J1,i,j2) <= S(i+1,J1,i2,j2)) l = i+1;
		else r = i-1;
	}
	if (l < i2-1) {
		l++;
		res = min(res, abs(S(i1,J1,l,j2)-S(l+1,J1,i2,j2)));
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&k);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			scanf("%d", &g);
			f[i][j] = (ll)g+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		}

	while (k--) {
		scanf("%d%d%d%d", &i1,&J1,&i2,&j2);
		res = oo;
		solve1();
		solve2();
		printf("%lld\n", res);
	}

	return 0;
}
