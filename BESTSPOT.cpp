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

const int N = 505, inf = 1e9;
int n, k, m, d[N][N], f[N];
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
	st.push({s, d[s][s]});
	while (! st.empty()) {
		int u = st.top().u, c = st.top().c;
		st.pop();
		if (c > d[s][u]) continue;
		for (auto k : a[u]) {
			int v = k.X, w = k.Y;
			if (d[s][v] > d[s][u] + w) {
				d[s][v] = d[s][u] + w;
				st.push({v, d[s][v]});
			}
		}
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&k,&m);
	FOR(i,1,k) scanf("%d", &f[i]);
	FOR(i,1,m) {
		int u, v, c;
		scanf("%d%d%d", &u,&v,&c);
		a[u].pb({v,c});
		a[v].pb({u,c});
	}

	FOR(s,1,n) dijkstra(s);

	int s = 0, ans = inf;
	FOR(u,1,n) {
		int sum = 0ll, cnt = 0;
		FOR(i,1,k) {
			int v = f[i];
			if (d[u][v] == inf) {
				sum = -1;
				break;
			}
			sum += d[u][v];
		}
		if (sum == -1) continue;
		if (ans > sum)
			ans = sum, s = u;
	}

	printf("%d\n", s);

	return 0;
}
