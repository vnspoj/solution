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

const int   N = 5000000;
int         n, m, s, k, a[N], dd[N], deg[N], res[N], cnt;
vector<int> ke[N], kt[N];
stack <int> st;

void dfs(int u) {
	dd[u] = 1;
	for (int i=0; i<deg[u]; i++) {
		int v = ke[u][i];
		if (! dd[v]) dfs(v);
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d%d", &n,&m,&s,&k);
	while (m--) {
		int u, v;
		scanf("%d%d", &u,&v);
		ke[u].push_back(v);
		ke[v].push_back(u);
		kt[u].push_back(1);
		kt[v].push_back(1);
		deg[u]++;
		deg[v]++;
	}
	for (int i=1; i<=k; i++) scanf("%d", &a[i]);
	dfs(s);
	for (int i=1; i<=k; i++)
		if (dd[a[i]] == 0) {
			printf("NIE");
			return 0;
		}
	printf("TAK\n");
	st.push(s);
	while (!st.empty()) {
		int u = st.top();
		bool flag = true;
		for (int i=0; i<deg[u]; i++) {
			int v = ke[u][i];
			if (kt[u][i] == 1) {
				kt[u][i] = 0;
				st.push(v);
				flag = false;
				break;
			}
		}
		if (flag) {
			res[++cnt] = u;
			st.pop();
		}
	}
	printf("%d ", cnt);
	for (int i=1; i<=cnt; i++) printf("%d ", res[i]);


	return 0;
}
