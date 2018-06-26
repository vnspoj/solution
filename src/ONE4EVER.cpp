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
	llu a[4][4];
};

int T;
llu a, b, m, n;
mat u, v;

llu solve(llu x, llu y) {
	if (x == 0 || y == 0) return 0;
	string X = "", Y = "";
	for (; x>0; x/=10) X += char(x % 10 + '0');
	for (; y>0; y/=10) Y += char(y % 10 + '0');
	string Z(X.size() + Y.size(), '0');
	FOR(i,0,X.size()-1) {
		int c = 0;
		FOR(j,0,Y.size()-1) {
			int g = Z[i+j]-'0' + c + (X[i]-'0')*(Y[j]-'0');
			c = g/10;
			g %= 10;
			Z[i+j] = char(g + '0');
		}
		if (c > 0) Z[i+Y.size()] = char(Z[i+Y.size()]-'0'+c+'0');
	}
	llu ans = 0;
	FOD(i,Z.size()-1,0)
	ans = (ans*10llu + Z[i]-'0') % m;
	return ans;
}

mat operator * (mat a, mat b) {
	mat c = {a.x, b.y};
	FOR(i,1,c.x) FOR(j,1,c.y) c.a[i][j] = 0;
	FOR(i,1,c.x)
	FOR(j,1,c.y)
	FOR(k,1,a.y)
	c.a[i][j] = (c.a[i][j] + solve(a.a[i][k]%m, b.a[k][j]%m)) % m;
	//c.a[i][j] = (c.a[i][j] + a.a[i][k]%m * b.a[k][j]%m) %m;
	return c;
}

mat Power(mat a, llu x) {
	if (x == 1) return a;
	mat ans = Power(a, x/2);
	if (x%2) return ans * ans *a;
	return ans * ans;
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &T);
	while (T--) {
		cin >> a >> b >> m >> n;
		if (n == 1) {
			printf("%llu\n", b%m);
			continue;
		}
		u.x = 2;
		u.y = 1;
		u.a[1][1] = u.a[2][1] = b%m;

		v.x = v.y = 2;
		v.a[1][1] = a%m;
		v.a[2][1] = 0;
		v.a[1][2] = v.a[2][2] = 1%m;

		u = Power(v, n-1) * u;
		printf("%llu\n", u.a[1][1]);
	}

	return 0;
}
