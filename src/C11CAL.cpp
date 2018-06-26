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
	ll a[60][60];
};

mat operator * (mat a, mat b) {
	mat c{a.x, b.y};
	FOR(i,1,c.x) FOR(j,1,c.y) c.a[i][j] = 0ll;
	FOR(i,1,c.x)
	FOR(j,1,c.y)
	FOR(k,1,a.y)
	c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
	return c;
}

mat Power(mat a, int x) {
	if (x == 1) return a;
	mat ans = Power(a, x/2);
	return x%2 ? ans * ans * a : ans * ans;
}

ll C[60][60];
int n, k;
mat a, x;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	C[0][0] = 1ll;
	FOR(j,1,50) {
		C[0][j] = 1ll;
		FOR(i,1,j) C[i][j] = (C[i][j-1] + C[i-1][j-1]) % mod;
	}
	while (scanf("%d", &n) == 1) {
		scanf("%d", &k);

		if (n == 1) {
			puts("1");
			continue ;
		}

		a.x = k+2;
		a.y = 1;
		FOR(i,1,a.x) a.a[i][1] = 1ll;

		x.x = x.y = k+2;
		FOR(i,1,x.x) FOR(j,1,x.y) x.a[i][j] = 0ll;
		x.a[1][1] = 1;
		FOR(j,2,x.y) x.a[1][j] = C[j-2][k];
		FOR(i,2,x.x)
		FOR(j,2,i)
		x.a[i][j] = C[j-2][i-2];

		mat ans = Power(x, n-1) * a;
		printf("%lld\n", ans.a[1][1]);
	}


	return 0;
}
