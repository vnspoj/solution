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


const int N = 2001;
int n, m, deg[N], low[N], num[N];
int in[N], Arg[N], dd[N][N];
vector<int> a[N], b[N];
stack<int> st;

void dfs(int u) {
	num[u] = ++num[0];
	low[u] = n+1;
	st.push(u);
	for (auto v : a[u]) {
		if (in[v]) continue;
		if (num[v])
			low[u] = min(low[u], num[v]);
		else {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if (low[u] >= num[u]) {
		Arg[++m] = u;
		for (;;) {
			int v = st.top();
			st.pop();
			in[v] = m;
			if (v == u) break;
		}
	}
}

void End(int start, int u) {
	num[u] = 1;
	for (auto v : b[u])
		if (num[v] == 0) End(start, v);
	puts("YES");
	printf("%d %d\n", Arg[u], Arg[start]);
	exit(0);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,m) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].pb(v);
	}
	m = 0;
	FOR(i,1,n) if (!in[i]) dfs(i);

	FOR(i,1,n) {
		for (auto j : a[i]) {
			int u = in[i], v = in[j];
			if (u == v || dd[u][v]) continue;
			b[u].pb(v);
			dd[u][v] = 1;
			deg[v]++;
		}
	}

	FOR(i,1,m) num[i] = 0;
	FOR(i,1,m) if (deg[i] == 0) End(i,i);

	return 0;
}
