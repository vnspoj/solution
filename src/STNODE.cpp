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

const int N = 10005;
int n, m, s, t, trace[N];
int num[N], F[N], dd[N], inPath[N];
vector<int> a[N], path;

void dfs(int u) {
	if (u == t) return ;
	for (auto v : a[u])
		if (! trace[v]) trace[v] = u, dfs(v);
}

void findPath(int u, int v) {
	path.push_back(v);
	while (v != u)
		v = trace[v], path.push_back(v);
	reverse(path.begin(), path.end());
	for (auto u : path)
		F[u] = num[u] = ++num[0], inPath[u] = 1;
}

void dfs2(int u) {
	dd[u] = 1;
	for (auto v : a[u]) {
		if (inPath[v])
			F[u] = max(F[u], num[v]);
		else {
			if (! dd[v]) dfs2(v);
			F[u] = max(F[u], F[v]);
		}
	}
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d%d", &n,&m,&s,&t);
	FOR(i,1,m) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].pb(v);
	}

	dfs(s);
	findPath(s,t);
	for (auto u : path) dfs2(u);

	int ans = 0, Max = 0;
	for (auto u : path) {
		if (u != s && u != t && Max <= num[u]) ans++;
		Max = max(Max, F[u]);
	}

	printf("%d\n", ans);

	return 0;
}
