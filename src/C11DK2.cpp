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

int n, s = 1, t, k, p = 2012;

struct mat {
	int x, y;
	ll a[65][65];
};

mat operator * (mat a, mat b) {
	mat c {a.x, b.y};
	FOR(i,1,c.x) FOR(j,1,c.y) c.a[i][j] = 0ll;
	FOR(i,1,c.x)
	FOR(j,1,c.y)
	FOR(k,1,a.y)
	c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % p) % p;
	return c;
}

mat power(mat a, int x) {
	if (x == 1) return a;
	mat b = power(a, x/2);
	return x%2 ? b*b*a : b*b;
}

mat a, x;
ii info[65];
ll F[25][25][3];
int adj[25][3], row[65][65];



int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&t,&k);
	FOR(u,1,2*n) {
		adj[u][0] = u <= n ? u + n : u - n;
		if (u <= n) {
			adj[u][1] = u == n ? 1 : u + 1;
			adj[u][2] = u == 1 ? n : u - 1;
		} else {
			adj[u][1] = u == 2 * n ? n + 1 : u + 1;
			adj[u][2] = u == n + 1 ? 2 * n : u - 1;
		}
	}

	FOR(i,0,2) F [ s ] [ adj[s][i] ] [ 1 ] = 1;

	if (k == 1) {
		printf("%lld\n", F[s][t][1]);
		return 0;
	}

	FOR(u,1,2*n) {
		FOR(i,0,2) {
			int v = adj[u][i];
			row[u][v] = ++row[0][0];
			info[row[0][0]] = {u,v};
		}
	}

	a.x = row[0][0];
	a.y = 1;
	FOR(i,1,a.x) {
		int u = info[i].X, v = info[i].Y;
		a.a[i][1] = F[u][v][1];
	}

	x.x = x.y = row[0][0];
	FOR(i,1,x.x) {
		int v = info[i].X, g = info[i].Y;
		FOR(j,0,2) {
			int u = adj[v][j];
			if (u == g) continue ;
			x.a[i][row[u][v]] = 1;
		}
	}

	a = power(x, k-1) * a;
	ll ans = 0ll;
	FOR(i,0,2) {
		int u = adj[t][i];
		ans = (ans + a.a[row[u][t]][1]) % p;
	}

	printf("%lld\n", ans);


	return 0;
}
