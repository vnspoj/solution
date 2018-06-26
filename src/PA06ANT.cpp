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

int s, t, k, p;

struct mat {
	int x, y;
	ll a[30][30];
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
int adj[9][3] = {
	0,0,0, 2,4,5, 1,3,6,
	2,4,7, 1,3,8, 1,6,8,
	2,5,7, 3,6,8, 4,5,7
};

int row[9][9];
ii  info[30];
ll  F[9][9][3];


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	char c;
	scanf("%c ",  &c);
	s = c - 'A' + 1;
	scanf("%c",  &c);
	t = c - 'A' + 1;
	scanf("%d %d", &k, &p);

	FOR(u,1,8)
	FOR(i,0,2) {
		int v = adj[u][i];
		row[u][v] = ++row[0][0];
		info[row[0][0]] = {u,v};
	}

	FOR(i,0,2) {
		int v = adj[s][i];
		F[s][v][1] = 1;
	}

	if (k == 1) {
		printf("%lld\n", F[s][t][1]);
		return 0;
	}

	a.x = 24;
	a.y = 1;
	FOR(i,1,a.x) {
		int u = info[i].X, v = info[i].Y;
		a.a[i][1] = F[u][v][1];
	}

	x.x = x.y = 24;
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
