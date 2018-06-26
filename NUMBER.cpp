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

const int N = 1e4+5;
int n, m, t, low[N], num[N];
int in[N], degOut[N], T;
vector<int> a[N];
stack<int> st;
bool dd[N][N];

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
	if (low[u] < num[u]) return ;
	++m;
	for (;;) {
		int v = st.top();
		st.pop();
		in[v] = m;
		if (v == t) T = m;
		if (v == u) break;
	}
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&t);
	while (m--) {
		int i, j;
		scanf("%d%d", &i,&j);
		a[i].pb(j);
	}
	m = 0;
	FOR(i,1,n) if (!in[i]) dfs(i);

	FOR(i,1,n) {
		for (auto j : a[i]) {
			int u = in[i], v = in[j];
			if (u == v || dd[u][v]) continue;
			dd[u][v] = 1;
			degOut[u]++;
		}
	}

	int ans = 0;
	FOR(i,1,m) ans += degOut[i] == 0 && i != T;

	printf("%d\n", ans);

	return 0;
}
