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

const int N = 100005;
const ll mod = 1000000007;
int n, u, v, c;
ll F[N], ans = 0ll;
vector<ii> a[N];

void dfs(int p, int u) {
	F[u] = 1ll;
	for (auto v : a[u]) {
		if (v.X == p) continue;
		dfs(u, v.X);
		F[u] = (F[u] + F[v.X] * v.Y % mod) % mod;
	}
	for (auto v : a[u]) {
		if (v.X == p) continue;
		ll T = F[v.X] * v.Y % mod;
		T = T * (F[u] - F[v.X] * (ll) v.Y % mod + 1 + mod) % mod;
		ans = (ans + T) % mod;
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n-1) {
		scanf("%d%d%d", &u,&v,&c);
		a[u].ep(v,c);
		a[v].ep(u,c);
	}
	dfs(0,1);
	if (ans%2) ans += mod;
	printf("%lld\n", ans/2);

	return 0;
}
