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

const int N = 1500;
int n, u, v, F[N][3];
vector<int> a[N];

void dfs(int p, int u) {
	F[u][1] = 1;
	int have_leaf = 0;
	for (auto v : a[u]) {
		if (v == p) continue;
		if (a[v].size() == 1) {
			F[u][0]++;
			F[u][2] = n+1;
			have_leaf = 1;
		} else {
			dfs(u,v);
			F[u][1] += min(F[v][0], min(F[v][1], F[v][2]));
			F[u][2] += min(F[v][0], F[v][1]);
		}
	}
	if (have_leaf) {
		for (auto v : a[u]) {
			if (v == p || a[v].size() == 1) continue;
			F[u][0] += min(F[v][0], F[v][1]);
		}
	} else {
		int Min = n+1;
		for (auto v : a[u]) {
			if (v == p) continue;
			F[u][0] += F[v][0];
			int t = F[v][1] - F[v][0];
			Min = min(Min, t);
			if (t < 0) F[u][0] += t;
		}
		if (Min > 0) F[u][0] += Min;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		FOR(i,1,n) {
			a[i].clear();
			F[i][0] = F[i][1] = F[i][2] = 0;
		}
		FOR(i,1,n-1) {
			scanf("%d%d", &u,&v);
			a[u].ep(v);
			a[v].ep(u);
		}
		if (n <= 2) puts("1");
		else {
			dfs(0,1);
			printf("%d\n", min(F[1][0], F[1][1]));
		}
	}
	
	return 0;
}
