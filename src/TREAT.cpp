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

const int N = 1e5+5;
int n, m, nxt[N], num[N], low[N];
int in[N], f[N], degOut[N];
vector<int> a[N];
stack<int> st;
map<int,int> dd[N];

void dfs(int u) {
	num[u] = ++num[0];
	low[u] = n+1;
	st.push(u);
	int v = nxt[u];
	if (v != u && in[v] == 0) {
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
		f[m]++;
		in[v] = m;
		if (v == u) break;
	}
}

void dfs2(int p, int u) {
	f[u] += f[p];
	for (auto v : a[u]) dfs2(u,v);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) {
		int j;
		scanf("%d", &j);
		nxt[i] = j;
	}

	FOR(i,1,n) if (in[i] == 0) dfs(i);

	FOR(i,1,n) {
		int u = in[i], v = in[nxt[i]];
		if (u == v || dd[u][v]) continue;
		dd[u][v] = 1;
		a[v].pb(u);
		degOut[u]++;
	}

	FOR(i,1,m) if (degOut[i] == 0) dfs2(0,i);

	FOR(i,1,n) printf("%d\n", f[in[i]]);

	return 0;
}
