#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 2001;
int n, m, cnt, dd[N];
vector<int> a[N];

void dfs(int u) {
	dd[u] = 1;
	for (auto v : a[u])
		if (!dd[v]) dfs(v);
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m;
	FOR(i,1,m) {
		int u, v;
		scanf("%d%d", &u, &v);
		a[u].pb(v);
		a[v].pb(u);
	}

	FOR(u,1,n)
	if (!dd[u]) cnt++, dfs(u);

	cout << cnt+m-n << endl;

	return 0;
}
