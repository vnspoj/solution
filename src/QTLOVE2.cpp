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

const int mod = 1e9+7;
struct mat {
	int x, y;
	ll a[3][3];
};

mat operator * (mat a, mat b) {
	mat c {a.x, b.y};
	FOR(i,1,c.x) FOR(j,1,c.y) c.a[i][j] = 0ll;
	FOR(i,1,c.x)
	FOR(j,1,c.y)
	FOR(k,1,a.y)
	c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
	return c;
}

mat power(mat a, ll x) {
	if (x == 1) return a;
	mat b = power(a, x/2);
	return x%2 ? b*b*a : b*b;
}

ll n, m;
mat a, x;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m;
	if (n <= 3) {
		ll ans = m;
		if (n == 2) ans = m * (m-1) % mod;
		if (n == 3) ans = m * (m-1) % mod * (m-2) % mod;
		printf("%lld\n", ans);
		return 0;
	}

	if (m == 1) {
		puts("0");
		return 0;
	}

	a.x = 2;
	a.y = 1;
	a.a[1][1] = m * (m-1) % mod * (m-2) % mod;
	a.a[2][1] = m * (m-1) % mod * (m-1) % mod * (m-1) % mod;

	x.x = x.y = 2;
	x.a[1][1] = -1;
	x.a[1][2] = 1;
	x.a[2][2] = m-1;

	a = power(x, n-3) * a;

	printf("%lld\n", (a.a[1][1] + (ll)mod) % mod);

	return 0;
}
