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

const int N = 500;
int n, u, m, v, F[N], b[N];
vector<int> a[N];

void dfs(int u) {
	if (a[u].size() == 0) {
		F[u] = 1;
		return ;
	}
	FOR(i, 0, a[u].size()-1) dfs(a[u][i]);
	FOR(i, 0, a[u].size()-1) b[i] = F[a[u][i]];
	sort(b, b + a[u].size());
	int du = 0;
	FOD(i, a[u].size()-1, 0) {
		if (b[i] <= du) du -= b[i];
		else {
			F[u] += b[i] - du;
			du = 0;
		}
		du += b[i] - 1;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d", &n);
	while (scanf("%d", &u) != EOF) {
		scanf("%d", &m);
		FOR(i,1,m)
		scanf("%d", &v), a[u].pb(v);
	}
	dfs(1);
	printf("%d", F[1]);

	return 0;
}
