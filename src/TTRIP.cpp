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


const int N = 101, inf = 1e9;
int n, d[N][N], dd[N];
vector<ii> a[N];

struct data {
	int u, c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra(int s) {
	priority_queue<data> st;
	FOR(i,1,n) d[s][i] = inf;
	d[s][s] = 0;
	st.push((data) {
		s, d[s][s]
	});
	while (! st.empty()) {
		int u = st.top().u, c = st.top().c;
		st.pop();
		if (c > d[s][u]) continue;
		for (int i = 0; i < a[u].size(); i++) {
			int v = a[u][i].X, w = a[u][i].Y;
			if (d[s][v] > d[s][u] + w) {
				d[s][v] = d[s][u] + w;
				st.push((data) {
					v, d[s][v]
				});
			}
		}
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(u,1,n) {
		FOR(v,1,n) {
			int c;
			scanf("%d", &c);
			if (u == v || c == 0) continue;
			a[u].pb({v,c});
		}
	}

	FOR(s,1,n) dijkstra(s);

	ll ans = 0ll;
	int s = 1, t = 0;
	FOR(i,1,n-2) {
		dd[s] = 1;
		int Min = inf;
		FOR(u,1,n-1)
		if (! dd[u] && Min > d[s][u])
			Min = d[s][u], t = u;
		ans += (ll) Min;
		s = t;
	}
	ans += d[t][n];

	printf("%lld\n", ans);


	return 0;
}
