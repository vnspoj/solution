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

struct edge {
	int u, v, c;
	bool f;
};
bool cmp(edge u, edge v) {
	return (u.c > v.c);
}

// info //

const int   N = 1e5+5, oo = 1e6+9;
int         n, m, pa[N], Rank[N];
edge        e[N];
int         root, lg, times, dd[N];
ii          t[N], up[N][50];
ll          res;
vector<ii>  a[N];

int FindSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = FindSet(pa[u]);
}

void check(edge &e) {
	int u = FindSet(e.u);
	int v = FindSet(e.v);
	if (u == v) return;
	pa[v] = u;
	if (Rank[v] > Rank[u]) swap(Rank[u], Rank[v]);
	if (Rank[u] == Rank[v]) Rank[u]++;
	e.f = true;
}

void dfs(int pa, int u, int c) {
	t[u].X = ++times;
	dd[u] = 1;
	up[u][0] = mp(pa,c);
	FOR(i,1,lg) {
		int p = up[u][i-1].X;
		up[u][i].X = up[p][i-1].X;
		up[u][i].Y = min(up[u][i-1].Y, up[p][i-1].Y);
	}
	for (int i=0; i<a[u].size(); i++) {
		ii f = a[u][i];
		if (f.X != pa && !dd[f.X]) dfs(u,f.X,f.Y);
	}
	t[u].Y = ++times;
}

bool upper(int u, int v) {
	return (t[u].X <= t[v].X and t[v].Y <= t[u].Y);
}

int lca(int u, int v) {
	if (upper(u,v)) return u;
	if (upper(v,u)) return v;
	FOD(i,lg,0)
	if (up[u][i].X > 0 and !upper(up[u][i].X,v)) u = up[u][i].X;
	return up[u][0].X;
}

int get(int pa, int u) {
	if (pa == u) return oo;
	int ans = oo;
	FOD(i,lg,0)
	if (up[u][i].X > 0 and !upper(up[u][i].X, pa)) {
		ans = min(ans, up[u][i].Y);
		u = up[u][i].X;
	}
	ans = min(ans, up[u][0].Y);
	return ans;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&m);
	FOR(i,1,m) scanf("%d%d%d\n", &e[i].u, &e[i].v, &e[i].c);
	sort(e+1,e+m+1,cmp);
	FOR(i,1,n) pa[i] = i;
	FOR(i,1,m) check(e[i]);
	FOR(i,1,m) if (e[i].f) {
		int u = e[i].u, v = e[i].v, c = e[i].c;
		a[u].pb(mp(v,c));
		a[v].pb(mp(u,c));
		root = u;
	}
	for (int i=n; i>1; i/=2) lg++;
	FOR(i,0,lg) up[0][i].Y = oo;
	dfs(0,root,oo);
	FOR(i,1,m) if (!e[i].f) {
		int u = e[i].u, v = e[i].v;
		int k = lca(u,v);
		res += (ll) ( min(get(k,u),get(k,v)) - e[i].c );
	}
	printf("%lld\n", res);

	return 0;
}
