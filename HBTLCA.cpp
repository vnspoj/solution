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


const int   N = 2e5;
int         n, m, r, u, v, k, q, up[N][100], times;
ii          t[N];
vector<int> a[N];
char        ch;

void reset() {
	m = 0;
	for (int i=n; i/2>0; i/=2) m++;
	for (int i=1; i<=n; i++) {
		a[i].clear();
		t[i].X = t[i].Y = 0;
		for (int j=0; j<=m; j++) up[i][j] = 0;
	}
	r = 1;
	times = 0;
}

void dfs(int u, int v) {
	t[v].X = ++times;
	up[v][0] = u;
	for (int j=1; j<=m; j++) up[v][j] = up[up[v][j-1]][j-1];
	for (int i=0; i<a[v].size(); i++) {
		int k = a[v][i];
		if (k == u) continue;
		dfs(v,k);
	}
	t[v].Y = ++times;
}

bool upper(int u, int v) {
	return (t[u].X <= t[v].X and t[v].Y <= t[u].Y);
}

int lca(int u, int v) {
	if (upper(u,v)) return u;
	if (upper(v,u)) return v;
	for (int j=m; j>=0; j--)
		if (up[u][j] > 0 and !upper(up[u][j],v)) u = up[u][j];
	return up[u][0];
}

int get(int r, int u, int v) {
	if (upper(r,u) or upper(r,v)) return r;
	for (int j=m; j>=0; j--)
		if (up[r][j] > 0 and !upper(up[r][j],u) and !upper(up[r][j],v)) r = up[r][j];
	return up[r][0];
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	for (;;) {
		scanf("%d", &n);
		if (n == 0) break;
		reset();
		for (int i=1; i<n; i++) {
			scanf("%d%d", &u,&v);
			a[u].pb(v);
			a[v].pb(u);
		}
		dfs(0,1);
		scanf("%d\n", &q);
		while (q--) {
			scanf("%c ", &ch);
			if (ch == '!') {
				scanf("%d\n", &r);
				continue;
			}
			scanf("%d%d\n", &u,&v);
			k = lca(u,v);
			if (k == r or !upper(k,r)) {
				printf("%d\n", k);
				continue;
			}
			printf("%d\n", get(r,u,v));
		}
	}

	return 0;
}
