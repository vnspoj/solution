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


const int N = 101;
const double inf = double(1e9+9.0);
int n, x[N], y[N], s[N], dd[N];
double d[N];
vector<int> a[N];

struct data {
	int u;
	double c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

double dis(int i, int j) {
	double X = double(x[i]-x[j]);
	double Y = double(y[i]-y[j]);
	return sqrt(X*X + Y*Y);
}

void dijkstra() {
	FOR(i,1,n) d[i] = inf;
	d[1] = 0.00;
	priority_queue<data> st;
	st.push({1, d[1]});
	while (! st.empty()) {
		int u = st.top().u;
		double c = st.top().c;
		st.pop();
		if (c > d[u]) continue;
		int cnt = 0;
		dd[u] = 1;
		for (auto v : a[u]) {
			if (cnt == s[u]) break;
			if (dd[v]) continue;
			cnt++;
			if (d[v] > d[u] + dis(u,v)) {
				d[v] = d[u] + dis(u,v);
				st.push({v, d[v]});
			}
		}
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d", &n);
	FOR(u,1,n) {
		scanf("%d%d%d", &x[u], &y[u], &s[u]);
		FOR(i,1,n-1) {
			int v;
			scanf("%d", &v);
			a[u].pb(v);
		}
	}

	dijkstra();

	FOR(u,1,n) printf("%.6f\n", d[u]);

	return 0;
}
