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
int n, m, k = 4, u, v, w, f[10], imp[N];
int c[N][N], d[N][N], trace[N][N], ans = inf;
vector<int> a[N];

struct data {
	int u, c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra(int s) {
	FOR(i,1,n) d[s][i] = inf;
	d[s][s] = 0;
	priority_queue<data> st;
	st.push({s, d[s][s]});
	while (! st.empty()) {
		int u = st.top().u, w = st.top().c;
		st.pop();
		if (w > d[s][u]) continue;
		for (auto v : a[u]) {
			if (d[s][v] > d[s][u] + c[u][v]) {
				d[s][v] = d[s][u] + c[u][v];
				trace[s][v] = u;
				st.push({v, d[s][v]});
			}
		}
	}
}

void Try(int s, int t) {
	vector<int> path;
	int sum = 0, v = t, cnt = 0, inPath[N];
	FOR(i,1,n) inPath[i] = 0;
	while (v != 0) {
		path.pb(v);
		inPath[v] = 1;
		cnt += imp[v];
		int u = trace[s][v];
		sum += c[u][v];
		v = u;
	}
	while (cnt < k) {
		int u = 0, v = 0, Min = inf;
		FOR(i,1,k) {
			int V = f[i];
			if (inPath[V]) continue;
			for (auto U : path)
				if (d[U][V] < Min)
					u = U, v = V, Min = d[U][V];
		}
		while (v != u) {
			path.pb(v);
			inPath[v] = 1;
			cnt += imp[v];
			int last = trace[u][v];
			sum += c[last][v];
			v = last;
		}
	}
	ans = min(ans, sum);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,k) scanf("%d", &f[i]), imp[f[i]] = 1;
	while (scanf("%d%d%d", &u,&v,&w) != EOF) {
		if (c[u][v] == 0) {
			a[u].pb(v);
			a[v].pb(u);
			c[u][v] = c[v][u] = w;
		} else
			c[u][v] = c[v][u] = min(c[u][v], w);
	}

	FOR(i,1,n) dijkstra(i);

	FOR(i,1,k) FOR(j,i+1,k) Try(f[i], f[j]);

	printf("%d\n", ans);

	return 0;
}
