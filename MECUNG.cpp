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

const int N = 1e5+5, inf = 1e9+9, sz = 1e6;
int n, m, d[2][N], st[sz], L, R, dd[N];
vector<ii> a[N];
vector<int> ans;

void bfs(int id, int s) {
	FOR(i,1,n) d[id][i] = inf;
	queue<int> st;
	st.push(s);
	d[id][s] = 0;
	while (! st.empty()) {
		int u = st.front();
		st.pop();
		for (auto v : a[u]) {
			if (d[id][v.X] > d[id][u] + 1) {
				d[id][v.X] = d[id][u] + 1;
				st.push(v.X);
			}
		}
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m;
	FOR(i,1,m) {
		int u, v, c;
		scanf("%d%d%d", &u,&v,&c);
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}

	bfs(0,1);
	bfs(1,n);

	L = R = 1;
	st[1] = 1;
	dd[1] = 1;
	while (L <= R && ans.size() < d[0][n]) {
		int r = R, color = inf;
		FOR(i,L,r) {
			int u = st[i];
			for (auto v : a[u])
				if (! dd[v.X] && d[0][u] + 1 + d[1][v.X] == d[0][n])
					color = min(color, v.Y);
		}
		FOR(i,L,r) {
			int u = st[i];
			for (auto v : a[u])
				if (! dd[v.X] && d[0][u] + 1 + d[1][v.X] == d[0][n] && v.Y == color)
					st[++R] = v.X, dd[v.X] = 1;
		}
		L = r + 1;
		ans.push_back(color);
	}

	printf("%d\n", ans.size());
	for (auto color : ans) printf("%d ", color);


	return 0;
}
