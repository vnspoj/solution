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

const int N = 10001, K = 21;
const ll inf = 1e18;
int n, m, k;
ll d[N][K];
vector<ii> a[N];

struct data {
	int u, j;
	ll c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra() {
	FOR(i,1,n) FOR(j,0,k) d[i][j] = inf;
	d[1][0] = 0ll;
	priority_queue<data> st;
	st.push({1, 0, d[1][0]});
	while (! st.empty()) {
		data t = st.top();
		st.pop();
		int u = t.u, j = t.j;
		ll c = t.c;
		if (c > d[u][j]) continue;
		for (auto e : a[u]) {
			int v = e.X, w = e.Y;
			if (d[v][j] > d[u][j] + w) {
				d[v][j] = d[u][j] + w;
				st.push({v, j, d[v][j]});
			}
			if (j < k && d[v][j+1] > d[u][j]) {
				d[v][j+1] = d[u][j];
				st.push({v, j+1, d[v][j+1]});
			}
		}
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&k);
	while (m--) {
		int u, v, c;
		scanf("%d%d%d", &u,&v,&c);
		a[u].pb({v,c});
		a[v].pb({u,c});
	}

	dijkstra();

	ll ans = inf;
	FOR(i,0,k) ans = min(ans, d[n][i]);

	printf("%lld\n", ans);

	return 0;
}
