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
	int u, v, k;
};

const int N = 255, inf = 1e9;
int n, m, s, t, F[N][N][3];
vector<int> a[N];
queue<data> st;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m >> s >> t;
	while (m--) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].pb(v);
	}

	FOR(i,1,n) FOR(j,1,n) FOR(k,1,2) F[i][j][k] = inf;
	F[s][t][1] = 0;
	st.push({s,t,1});
	while (! st.empty()) {
		data f = st.front();
		st.pop();
		if (f.k == 1) {
			for (auto u : a[f.u]) {
				if (F[u][f.v][3-f.k] > F[f.u][f.v][f.k] + 1) {
					F[u][f.v][3-f.k] = F[f.u][f.v][f.k] + 1;
					st.push({u, f.v, 3-f.k});
				}
			}
		} else {
			for (auto v : a[f.v]) {
				if (F[f.u][v][3-f.k] > F[f.u][f.v][f.k] + 1) {
					F[f.u][v][3-f.k] = F[f.u][f.v][f.k] + 1;
					st.push({f.u, v, 3-f.k});
				}
			}
		}
	}

	int ans = inf;
	FOR(i,1,n) ans = min(ans, F[i][i][1]);

	printf("%d\n", ans == inf ? -1 : ans / 2);

	return 0;
}
