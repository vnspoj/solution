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


const int N = 30001, inf = 1e9+9;
int n, m, d[2][N];
ll  F[2][N];
vector<ii> a[N];
vector<int> ans;

struct data {
	int u, c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra(int id, int s) {
	FOR(i,1,n) d[id][i] = inf;
	d[id][s] = 0;
	F[id][s] = 1ll;
	priority_queue<data> st;
	st.push({s, d[id][s]});
	while (! st.empty()) {
		int u = st.top().u, c = st.top().c;
		st.pop();
		if (c > d[id][u]) continue;
		for (auto k : a[u]) {
			int v = k.X, w = k.Y;
			if (d[id][v] > d[id][u] + w) {
				d[id][v] = d[id][u] + w;
				F[id][v] = (ll) F[id][u];
				st.push({v, d[id][v]});
			} else {
				if (d[id][v] == d[id][u] + w)
					F[id][v] += (ll) F[id][u];
			}
		}
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,m) {
		int u, v, c;
		scanf("%d%d%d", &u,&v,&c);
		a[u].pb({v,c});
		a[v].pb({u,c});
	}

	dijkstra(0,1);
	dijkstra(1,n);

	FOR(i,2,n-1)
	if (d[0][i] + d[1][i] > d[0][n]) ans.pb(i);
	else {
		if (F[0][i] * F[1][i] < F[0][n]) ans.pb(i);
	}

	printf("%d\n", ans.size());
	for (auto u : ans) printf("%d\n", u);

	return 0;
}
