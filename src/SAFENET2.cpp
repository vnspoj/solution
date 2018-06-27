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

const int N = 30005;
int n, m, ans, low[N], num[N];
vector<int> a[N];
stack<ii> st;

void dfs(int p, int u) {
	num[u] = ++num[0];
	low[u] = n+1;
	for (auto v : a[u]) {
		if (v == p) continue;
		if (num[v])
			low[u] = min(low[u], num[v]);
		else {
			st.push({u,v});
			dfs(u,v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= num[u]) {
				int cnt = 1;
				for (;;) {
					ii k = st.top();
					st.pop();
					cnt++;
					if (k == ii(u,v)) break;
				}
				ans = max(ans, cnt);
			}
		}
	}
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,m) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].pb(v);
		a[v].pb(u);
	}

	FOR(i,1,n) if (!num[i]) dfs(0,i);

	printf("%d\n", max(ans, 1));

	return 0;
}
