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
int n, q, u, v, c;
vector<ii> a[N];

void dfs(int p, int u, int t, int val) {
	if (u == t) {
		c = val;
		return ;
	}
	for (auto k : a[u]) {
		int v = k.X, c = k.Y;
		if (v == p) continue;
		dfs(u, v, t, val + c);
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&q);
	FOR(i,1,n-1) {
		scanf("%d%d%d", &u,&v,&c);
		a[u].pb({v,c});
		a[v].pb({u,c});
	}

	while (q--) {
		scanf("%d%d", &u,&v);
		dfs(0, u, v, 0);
		printf("%d\n", c);
	}

	return 0;
}
