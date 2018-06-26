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

int n, m, a[9][9];
ii b[65], c[65];
ll ans, sum;
bool hau[65][65], xe[65][65], tuong[65][65], ma[65][65];


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		a[x][y] = c;
		b[i] = {x,y};
		sum += (ll) c;
	}

	FOR(i,1,8)
	FOR(j,1,8)
	if (a[i][j] == 0) c[++m] = {i,j};

	FOR(i,1,n)
	FOR(j,1,m) {
		int u = b[i].X, v = b[i].Y, x = c[j].X, y = c[j].Y;
		xe[i][j] = u == x || v == y;
		tuong[i][j] = u-v == x-y || u+v == x+y;
		hau[i][j] = xe[i][j] || tuong[i][j];
		ma[i][j] = (abs(x-u)==1&&abs(y-v)==2)||(abs(x-u)==2&&abs(y-v)==1);
	}

	FOR(i,1,m) FOR(j,1,m) FOR(k,1,m) FOR(t,1,m) {
		if (i == j || i == k || i == t || j == k || j == t || k == t) continue;
		ll s = 0ll;
		FOR(q,1,n) {
			int x = b[q].X, y = b[q].Y;
			if (hau[q][i] || xe[q][j] || tuong[q][k] || ma[q][t])
				s += a[x][y];
		}
		ans = max(ans, s);
		if (ans == sum) {
			printf("%lld\n", ans);
			return 0;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
