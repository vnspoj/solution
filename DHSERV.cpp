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


const int N = 505;
const ll inf = 1e18;
int n, m, q, c[N][N], dd[N];
ll d[N][N];
vector<int> a[N];

struct data {
	int u;
	ll c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra(int s) {
	priority_queue<data> st;
	st.push({s, d[s][s]});
	while (! st.empty()) {
		int u = st.top().u;
		ll w = st.top().c;
		st.pop();
		if (w > d[s][u]) continue;
		for (auto v : a[u]) {
			if (d[s][v] >= d[s][u] + (ll) c[u][v]) {
				d[s][v] = d[s][u] + (ll) c[u][v];
				if (dd[v]) st.push({v, d[s][v]});
			}
		}
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&q);

	FOR(i,1,m) {
		int u, v, w;
		scanf("%d%d%d", &u,&v,&w);
		a[u].pb(v);
		c[u][v] = w;
	}

	FOR(i,1,n) {
		FOR(j,1,n) d[i][j] = inf;
		d[i][i] = 0ll;
		for (auto j : a[i]) d[i][j] = (ll) c[i][j];
	}

	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int u;
			scanf("%d", &u);
			if (dd[u]) continue;
			dd[u] = 1;
			FOR(i,1,n) dijkstra(i);
		} else {
			int u, v;
			scanf("%d%d", &u,&v);
			printf("%lld\n", d[u][v] == inf ? -1 : d[u][v]);
		}
	}


	return 0;
}
