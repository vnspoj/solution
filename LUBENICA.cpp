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

struct data {
	int root, minc, maxc;
};

const int   N = 150000, oo = 2e6, M = 100;
int         n, u, v, c, q, m, dd[N], Min, Max, times;
vector<ii>  a[N];
ii          t[N];
data        up[N][M];

void build(int p, int u) {
	dd[u] = 1;
	for (int i=0; i<a[u].size(); i++) {
		int v = a[u][i].X;
		if (!dd[v] and v != p) {
			up[v][0].root = u;
			up[v][0].minc = a[u][i].Y;
			up[v][0].maxc = a[u][i].Y;
			build(u,v);
		}
	}
}

void dfs(int u, int v) {
	t[v].X = ++times;

	dd[v] = 1;
	for (int i=1; i<=m; i++) {
		int p = up[v][i-1].root;
		up[v][i].root = up[p][i-1].root;
		up[v][i].maxc = max(up[v][i-1].maxc, up[p][i-1].maxc);
		up[v][i].minc = min(up[v][i-1].minc, up[p][i-1].minc);
	}

	for (int i=0; i<a[v].size(); i++) {
		int k = a[v][i].X;
		if (!dd[k] and k != u) dfs(v,k);
	}

	t[v].Y = ++times;
}

bool upper(int u, int v) {
	return (t[u].X <= t[v].X and t[v].Y <= t[u].Y);
}

int lca(int u, int v) {
	if (upper(u,v)) return u;
	if (upper(v,u)) return v;
	for (int i=m; i>=0; i--)
		if (up[u][i].root > 0 and ! upper(up[u][i].root, v)) u = up[u][i].root;

	return up[u][0].root;
}

void find_min(int u, int p) {
	for (int i=m; i>=0; i--)
		if (up[u][i].root > 0 and upper(p, up[u][i].root)) {
			Min = min(Min, up[u][i].minc);
			u = up[u][i].root;
		}
}

void find_max(int u, int p) {
	for (int i=m; i>=0; i--)
		if (up[u][i].root > 0 and upper(p, up[u][i].root)) {
			Max = max(Max, up[u][i].maxc);
			u = up[u][i].root;
		}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d", &n);
	for (int i=1; i<n; i++) {
		scanf("%d%d%d", &u,&v,&c);
		a[u].pb(mp(v,c));
		a[v].pb(mp(u,c));
	}

	for (int i=n; i/2>0; i/=2) m++;

	build(0,1);
	for (int i=1; i<=n; i++) dd[i] = 0;
	dfs(0,1);

	scanf("%d", &q);
	while (q--) {
		Min = oo;
		Max = 0;
		scanf("%d %d", &u, &v);
		int p = lca(u,v);
		find_min(u,p);
		find_min(v,p);
		find_max(u,p);
		find_max(v,p);
		printf("%d %d\n", Min, Max);
	}

	return 0;
}
