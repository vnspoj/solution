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

const int N = 10001, inf = 1e9;
int T, n, m, k, s, t, d[N][2];
vector<ii> a[N], b[N];

struct data {
	int u, f, c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra() {
	FOR(i,1,n) d[i][0] = d[i][1] = inf;
	d[s][0] = 0;
	priority_queue<data> st;
	st.push({s, 0, d[s][0]});
	while (! st.empty()) {
		data t = st.top();
		st.pop();
		int u = t.u, f = t.f, c = t.c;
		if (c > d[u][f]) continue;
		for (auto k : a[u]) {
			int v = k.X, w = k.Y;
			if (d[v][f] > d[u][f] + w) {
				d[v][f] = d[u][f] + w;
				st.push({v, f, d[v][f]});
			}
		}
		if (f == 1) continue;
		for (auto k : b[u]) {
			int v = k.X, w = k.Y;
			if (d[v][1] > d[u][0] + w) {
				d[v][1] = d[u][0] + w;
				st.push({v, 1, d[v][1]});
			}
		}
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d", &n,&m,&k,&s,&t);
		FOR(i,1,n) a[i].clear(), b[i].clear();

		int u, v, c;
		while (m--) {
			scanf("%d%d%d", &u,&v,&c);
			a[u].pb({v,c});
		}
		while (k--) {
			scanf("%d%d%d", &u,&v,&c);
			b[u].pb({v,c});
			b[v].pb({u,c});
		}

		dijkstra();

		if (d[t][0] == inf && d[t][1] == inf) puts("-1");
		else
			printf("%d\n", min(d[t][0], d[t][1]));
	}

	return 0;
}
