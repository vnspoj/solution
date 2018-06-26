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

const int mod = 111539786;

struct mat {
	int x, y;
	ll a[3][3];
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

int t, n;
mat a, x;



int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	a.x = 2;
	a.y = 1;
	a.a[1][1] = 2;
	a.a[2][1] = 1;

	x.x = x.y = 2;
	x.a[1][1] = x.a[1][2] = x.a[2][1] = 1;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n <= 2) {
			printf("%d\n", n);
			continue;
		}
		mat ans = Power(x, n-2) * a;
		printf("%lld\n", ans.a[1][1]);
	}

	return 0;
}
