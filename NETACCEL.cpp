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

const int N = 1001, K = 11;
const double inf = double(1e9+9.0);
int n, m, k;
double d[N][K];
vector<ii> a[N];

struct data {
	int u, j;
	double c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void dijkstra() {
	FOR(i,1,n) FOR(j,0,k) d[i][j] = inf;
	d[1][0] = double(0.0);
	priority_queue<data> st;
	st.push({1, 0, d[1][0]});
	while (! st.empty()) {
		data t = st.top();
		st.pop();
		int u = t.u, j = t.j;
		double c = t.c;
		if (c > d[u][j]) continue;
		for (auto e : a[u]) {
			int v = e.X;
			double w = (double) e.Y;
			FOR(i,j,k) {
				if (d[v][i] > d[u][j] + w) {
					d[v][i] = d[u][j] + w;
					st.push({v, i, d[v][i]});
				}
				w /= 2.0;
			}
		}
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&k);
	while (m--) {
		int u, v, c;
		scanf("%d%d%d", &u,&v,&c);
		a[u].pb({v,c});
		a[v].pb({u,c});
	}

	dijkstra();

	printf("%.2f\n", d[n][k]);

	return 0;
}
