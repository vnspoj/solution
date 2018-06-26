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
	bool operator < (const edge &o) const {
		return c < o.c;
	}
};

const int N = 1e5+5;
int n, m, c[N], pa[N], sz[N];
edge e[N];
ll ans = 1001ll;

int FindSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = FindSet(pa[u]);
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,n) scanf("%d", &c[i]);
	FOR(i,1,m) {
		int u, v, w;
		scanf("%d%d%d", &u,&v,&w);
		e[i] = {u, v, w * 2 + c[u] + c[v]};
	}
	sort(e+1, e+m+1);

	FOR(i,1,n) pa[i] = i, sz[i] = 1, ans = min(ans, (ll) c[i]);
	FOR(i,1,m) {
		int u = FindSet(e[i].u), v = FindSet(e[i].v);
		if (u == v) continue;
		pa[v] = u;
		sz[u] += sz[v];
		ans += (ll) e[i].c;
	}

	printf("%lld\n", ans);

	return 0;
}
