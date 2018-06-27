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

const int N = 10005, inf = N;
int n, m, dd[N], num[N], low[N], ans;
vector<int> a[N];
stack<int> st;


void dfs(int u) {
	num[u] = ++num[0];
	low[u] = inf;
	st.push(u);
	for (auto v : a[u]) if (!dd[v]) {
			if (num[v]) low[u] = min(low[u], num[v]);
			else {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
		}
	if (low[u] < num[u]) return;
	ans++;
	for (;;) {
		int k = st.top();
		st.pop();
		dd[k] = 1;
		if (k == u) return ;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n, &m);
	FOR(i,1,m) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].ep(v);
	}
	FOR(u,1,n) if (!dd[u]) dfs(u);
	printf("%d\n", ans);

	return 0;
}
