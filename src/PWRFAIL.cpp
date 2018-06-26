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

const int N = 1001;
const double inf = double(1e15+5.0);
int n, e, x[N], y[N];
double m, c[N][N], d[N];
vector<int> a[N];

double dis(int i, int j) {
	double X = double(x[i] - x[j]);
	double Y = double(y[i] - y[j]);
	return sqrt(X*X + Y*Y);
}

struct data {
	int u;
	double c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra() {
	d[1] = 0.0;
	FOR(i,2,n) d[i] = inf;
	priority_queue<data> st;
	st.push({1, d[1]});
	while (! st.empty()) {
		int u = st.top().u;
		double w = st.top().c;
		st.pop();
		if (w > d[u]) continue;
		for (auto v : a[u]) {
			if (d[v] > d[u] + c[u][v]) {
				d[v] = d[u] + c[u][v];
				st.push({v, d[v]});
			}
		}
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d%d%lf", &n,&e,&m);
	FOR(i,1,n) scanf("%d%d", &x[i], &y[i]);
	FOR(u,1,n) FOR(v,1,n) c[u][v] = inf;
	while (e--) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].pb(v);
		a[v].pb(u);
		c[u][v] = c[v][u] = 0.0;
	}
	FOR(u,1,n)
	FOR(v,1,n)
	if (u != v && c[u][v] == inf && dis(u,v) <= m) {
		a[u].pb(v);
		a[v].pb(u);
		c[u][v] = c[v][u] = dis(u,v);
	}

	dijkstra();

	if (d[n] == inf) puts("-1");
	else printf("%lld\n", ll(d[n] * 1000ll));


	return 0;
}
