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


struct mat {
	int x, y;
	ll a[5][5];
};

int T, n, m, A[5], F[5];
mat a, x;

mat operator * (mat a, mat b) {
	mat c;
	c.x = a.x;
	c.y = b.y;
	FOR(i,1,c.x) FOR(j,1,c.y) c.a[i][j] = 0ll;
	FOR(i,1,c.x)
	FOR(j,1,c.y)
	FOR(k,1,a.y)
	c.a[i][j] = (c.a[i][j] + (ll)a.a[i][k] % m * (ll)b.a[k][j] % m) % m;
	return c;
}

mat Power(mat a, int x) {
	if (x == 1) return a;
	mat ans = Power(a, x/2);
	if (x%2) return ans * ans * a;
	return ans * ans;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &A[2], &n, &m);
		A[1] = F[1] = 1 % m;
		F[2] = (1ll + (ll)A[2] * A[2]) % m;
		if (n <= 2) {
			printf("%d\n", F[n]);
			continue;
		}

		a.x = 4;
		a.y = 1;
		a.a[1][1] = (ll)F[2];
		a.a[2][1] = (ll)A[2] * A[2] % m;
		a.a[3][1] = 1ll % m;
		a.a[4][1] = (ll)A[2] % m;

		x.x = x.y = 4;
		x.a[2][1] = x.a[3][1] = x.a[4][1] = x.a[3][3] = x.a[3][4] = x.a[4][3] = 0ll;
		x.a[1][1] = x.a[1][3] = x.a[2][3] = x.a[3][2] = 1 % m;
		x.a[1][2] = x.a[2][2] = 4ll * (ll)A[2] * A[2] % m;
		x.a[1][4] = x.a[2][4] = -4ll * (ll)A[2] % m;
		x.a[4][2] = 2 * (ll)A[2] % m;
		x.a[4][4] = -1;

		a = Power(x, n-2) * a;
		ll ans = (a.a[1][1] + (ll)m) % m;
		printf("%lld\n", ans);
	}

	return 0;
}
