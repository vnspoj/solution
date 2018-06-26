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

const int N = 10005;
int n, ans[N], F[N][4];
vector<int> a[N];

void dfs(int p, int u) {
	FOR(i,1,3) F[u][i] = i;
	for (auto v : a[u]) {
		if (v == p) continue;
		dfs(u, v);
		F[u][1] += min(F[v][2], F[v][3]);
		F[u][2] += min(F[v][1], F[v][3]);
		F[u][3] += min(F[v][1], F[v][2]);
	}
}

void find(int p, int u) {
	for (auto v : a[u]) {
		if (v == p) continue;
		for (ans[v] = 1; ans[v] <= 3; ans[v]++)
			if (ans[v] != ans[u]) break;
		FOR(i,1,3)
		if (i != ans[u] && F[v][i] < F[v][ans[v]]) ans[v] = i;
		find(u, v);
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n-1) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].ep(v);
		a[v].ep(u);
	}
	dfs(0,1);
	ans[1] = 1;
	FOR(i,2,3) if (F[1][i] < F[1][ans[1]]) ans[1] = i;
	find(0,1);
	printf("%d\n", F[1][ans[1]]);
	FOR(i,1,n) printf("%d\n", ans[i]);

	return 0;
}
