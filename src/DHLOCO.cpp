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


ll n, m;

struct mat {
	int x, y;
	ll a[5][5];
};

mat operator * (mat a, mat b) {
	mat c;
	c.x = a.x;
	c.y = b.y;
	FOR(i,1,c.x) FOR(j,1,c.y) c.a[i][j] = 0;
	FOR(i,1,a.x)
	FOR(j,1,b.y)
	FOR(k,1,a.y)
	c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % m) % m;
	return c;
}

mat power(mat a, ll x) {
	if (x == 1) return a;
	mat tmp = power(a, x/2);
	mat ans = tmp * tmp;
	if (x%2) ans = ans * a;
	return ans;
}

mat a, x;

void Print(mat a) {
	printf("%d %d\n", a.x, a.y);
	FOR(i,1,a.x) {
		FOR(j,1,a.y) printf("%lld ", a.a[i][j]);
		EL;
	}
	EL;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m;
	if (n == 1 || n == 2) {
		printf("%d\n", n == 1 ? 1%m : 2%m);
		return 0;
	}

	a.x = a.y = 3;
	a.a[1][1] = a.a[1][2] = a.a[1][3] = a.a[2][1] = a.a[3][2] = 1;

	x.x = 3;
	x.y = 1;
	x.a[1][1] = 2;
	x.a[2][1] = 1;
	x.a[3][1] = 1;

	a = power(a, n-2);
	x = a * x;

	cout << x.a[1][1];

	return 0;
}
