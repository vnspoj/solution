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

const int N = 1001, inf = 1e6;
int n, m, s, t, c[N][N], F[N][N];
vector<int> a[N];
int trace[N], dmin[N];

bool FindPath() {
	FOR(i,1,n) trace[i] = 0;
	trace[s] = -1;
	dmin[s] = inf;
	queue<int> st;
	st.push(s);
	while (! st.empty()) {
		int u = st.front();
		st.pop();
		for (auto v : a[u]) {
			if (trace[v] == 0 && c[u][v] > F[u][v]) {
				trace[v]  = u;
				dmin[v] = min(dmin[u], c[u][v] - F[u][v]);
				if (v == t) return true;
				st.push(v);
			}
		}
	}
	return false;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &s, &t);
	FOR(i,1,m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u].pb(v);
		a[v].pb(u);
		c[u][v] = w;
	}

	for (;;) {
		if (! FindPath()) break;
		int del = dmin[t], v = t;
		while (v != s) {
			int u = trace[v];
			F[u][v] += del;
			F[v][u] -= del;
			v = u;
		}
	}

	int ans = 0;
	for (auto v : a[s]) ans += F[s][v];

	printf("%d\n", ans);

	return 0;
}
