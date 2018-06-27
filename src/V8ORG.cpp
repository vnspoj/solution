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
int n, k, F[N];
vector<int> a[N];

void dfs(int p, int u) {
	F[u] = 1;
	for (auto v : a[u]) {
		if (v == p) continue;
		dfs(u, v);
		F[u] += F[v];
	}
	if (F[u] >= k) {
		F[u] = 0;
		F[0]++;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &k,&n);
	FOR(i,2,n) {
		int j;
		scanf("%d", &j);
		a[i].pb(j);
		a[j].pb(i);
	}

	dfs(0,1);

	printf("%d\n", F[0]);

	return 0;
}
