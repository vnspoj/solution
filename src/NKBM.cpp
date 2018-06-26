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
int n, m, e, u, v, matchX[N], matchY[N], trace[N];
vector<int> a[N], b[N];
int ans;

int findPath() {
	queue<int> st;
	FOR(i,1,m) trace[i] = 0;
	FOR(i,1,n)
	if (matchX[i] == 0) st.push(i);
	while (! st.empty()) {
		int u = st.front();
		st.pop();
		for (auto v : a[u]) {
			if (trace[v]) continue;
			trace[v] = u;
			if (matchY[v] == 0) return v;
			st.push(matchY[v]);
		}
	}
	return -1;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&e);
	while (e--) {
		scanf("%d%d", &u,&v);
		a[u].pb(v);
		b[v].pb(u);
	}

	for(;;) {
		v = findPath();
		if (v == -1) break;
		while (v != 0) {
			u = trace[v];
			int k = matchX[u];
			matchX[u] = v;
			matchY[v] = u;
			v = k;
		}
	}

	FOR(i,1,n) if (matchX[i]) ans++;

	printf("%d\n", ans);

	return 0;
}
