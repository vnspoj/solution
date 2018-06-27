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

const int N = 501, inf = 5e6+5;
int n, m, g[N], d[N], Time[N][N], cost[N][N];
vector<int> a[N];

struct data {
	int u, t, w;
	bool operator < (const data &o) const {
		return t > o.t;
	}
};

void dijkstra() {
	d[n] = 0;
	FOR(i,1,n-1) d[i] = inf;
	priority_queue<data> st;
	st.push({n, d[n]});
	while (! st.empty()) {
		int u = st.top().u, t = st.top().t;
		st.pop();
		if (t > d[u]) continue;
		for (auto v : a[u]) {
			if (d[v] > d[u] + Time[u][v]) {
				d[v] = d[u] + Time[u][v];
				st.push({v, d[v]});
			}
		}
	}
}

bool check(int pow) {
	queue<data> st;
	st.push({1, 0, pow});
	while (! st.empty()) {
		data f = st.front();
		st.pop();
		int u = f.u, w = f.w, t = f.t;
		for (auto v : a[u]) {
			if (w < cost[u][v] || t + Time[u][v] + d[v] > d[1]) continue;
			int wv = g[v] ? pow : w - cost[u][v];
			int tv = t + Time[u][v];
			if (v == n && tv == d[1]) return true;
			st.push({v, tv, wv});
		}
	}
	return false;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &g[i]);
	scanf("%d", &m);
	FOR(i,1,m) {
		int u, v, t, c;
		scanf("%d%d%d%d", &u,&v,&t,&c);
		a[u].pb(v);
		a[v].pb(u);
		cost[u][v] = cost[v][u] = c;
		Time[u][v] = Time[v][u] = t;
	}

	dijkstra();

	int L = 1, R = inf, ans = 0;
	while (L <= R) {
		int mid = (L+R)/2;
		if (check(mid))
			ans = mid, R = mid-1;
		else
			L = mid+1;
	}

	printf("%d\n", ans);

	return 0;
}
