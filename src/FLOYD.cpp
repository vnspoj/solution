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


struct data {
	int u, c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

const int N = 101, inf = 1e9;
int n, m, k, u, v, c, d[N][N], trace[N][N];
vector<ii> a[N];

void dijkstra(int s) {
	priority_queue<data> st;
	FOR(u,1,n) d[s][u] = inf;
	d[s][s] = 0;
	st.push({s, d[s][s]});
	while (! st.empty()) {
		int u = st.top().u, c = st.top().c;
		st.pop();
		if (c > d[s][u]) continue;
		for (auto k : a[u]) {
			int v = k.X, w = k.Y;
			if (d[s][v] > d[s][u] + w) {
				d[s][v] = d[s][u] + w;
				trace[s][v] = u;
				st.push({v, d[s][v]});
			}
		}
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&k);
	FOR(i,1,m) {
		scanf("%d%d%d", &u,&v,&c);
		a[u].pb({v,c});
		a[v].pb({u,c});
	}

	FOR(s,1,n) dijkstra(s);

	while (k--) {
		scanf("%d%d%d", &c,&u,&v);
		if (c == 0) printf("%d\n", d[u][v]);
		else {
			stack<int> st;
			while (v != 0) {
				st.push(v);
				v = trace[u][v];
			}
			printf("%d ", st.size());
			while (! st.empty())
				printf("%d ", st.top()), st.pop();
		}
	}

	return 0;
}
