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

int n, m, k, a[505];
ll  f[505][505], g[505][505];

void solve(int x, int k, ll &ans) {
	if (k == 1) return ;
	ans += (ll)(x/k)*(x-x/k);
	solve(x-x/k, k-1, ans);
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&k);
	for (int i=1; i<=n; i++) {
		int t;
		scanf("%d", &t);
		a[t]++;
	}

	for (int i=1; i<=m; i++) {
		f[i][0] = (ll)a[i]*(ll)(a[i]+1)/2;
		for (int j=1; j<=min(k, a[i]-1); j++) {
			ll ans = 0;
			solve(a[i], j+1, ans);
			f[i][j] = f[i][0] - ans;
		}
		for (int j=a[i]; j<=k; j++) f[i][j] = f[i][a[i]-1];
	}

	for (int i=0; i<=k; i++) g[1][i] = f[1][i];

	for (int i=2; i<=m; i++)
		for (int j=0; j<=k; j++) {
			g[i][j] = g[i-1][j]+f[i][0];
			for (int c=1; c<=j; c++)
				g[i][j] = min(g[i][j], g[i-1][j-c]+f[i][c]);
		}

	printf("%lld", g[m][k]);

	return 0;
}
