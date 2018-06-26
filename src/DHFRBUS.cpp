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

const int N = 1e5+5;
const ll inf = 1e18;
int n, m, k, s, t;
ll d[N][10];
vector<ii> a[N];

struct data {
	int u, i;
	ll c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra() {
	FOR(i,1,n) FOR(j,0,k) d[i][j] = inf;
	d[s][0] = 0ll;
	priority_queue<data> st;
	st.push({s, 0, d[s][0]});
	while (! st.empty()) {
		data t = st.top();
		st.pop();
		int u = t.u, i = t.i, c = t.c;
		if (c > d[u][i]) continue;
		for (auto e : a[u]) {
			int v = e.X, w = e.Y;
			if (d[v][i] > d[u][i] + w) {
				d[v][i] = d[u][i] + w;
				st.push({v, i, d[v][i]});
			}
			if (i < k && d[v][i+1] > d[u][i]) {
				d[v][i+1] = d[u][i];
				st.push({v, i+1, d[v][i+1]});
			}
		}
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d%d%d", &n,&m,&k,&s,&t);
	while (m--) {
		int u, v, c;
		scanf("%d%d%d", &u,&v,&c);
		a[u].pb({v,c});
		a[v].pb({u,c});
	}

	dijkstra();

	ll ans = inf;
	FOR(i,0,k) ans = min(ans, d[t][i]);

	printf("%lld\n", ans);

	return 0;
}
