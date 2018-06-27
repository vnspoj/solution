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

const int N = 111;
int n, m, pa[N], low[N], num[N], f[N], ans;
vector<int> a[N];

void dfs(int u) {
	num[u] = ++num[0];
	low[u] = n+1;
	f[u] = 1;
	for (auto v : a[u]) {
		if (pa[u] == v) continue;
		if (num[v])
			low[u] = min(low[u], num[v]);
		else {
			pa[v] = u;
			dfs(v);
			f[u] += f[v];
			low[u] = min(low[u], low[v]);
		}
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].ep(v);
		a[v].ep(u);
	}
	FOR(u,1,n) if (pa[u] == 0) dfs(u);
	FOR(v,1,n) {
		int u = pa[v];
		if (u == 0 || low[v] < num[v]) continue;
		ans += f[v] * (n - f[v]);
	}
	printf("%d\n", ans);

	return 0;
}
