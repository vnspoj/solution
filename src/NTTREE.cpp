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
int n, u, v, c, sz[N];
ll F[N], ans;
vector<ii> a[N];

void dfs(int p, int u) {
	sz[u] = 1;
	for (auto v : a[u]) {
		if (v.X == p) continue;
		dfs(u, v.X);
		sz[u] += sz[v.X];
	}
	for (auto v : a[u]) {
		if (v.X == p) continue;
		F[u] += F[v.X] + (ll) v.Y * sz[v.X];
		ans += F[v.X] * (ll)(sz[u] - sz[v.X]);
		ans += (ll) v.Y * sz[v.X] * (sz[u] - sz[v.X]);
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n-1) {
		scanf("%d%d%d", &u,&v,&c);
		++u;
		++v;
		a[u].ep(v,c);
		a[v].ep(u,c);
	}
	dfs(0,1);
	printf("%lld\n", ans);

	return 0;
}
