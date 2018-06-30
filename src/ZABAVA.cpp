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

const int N = 505;
int n, m, k, a[N];
ll f[N][N], g[N][N];

ll solve(int n, int k) {
	int p = n/k;
	int y = n-p*k;
	int x = k-y;
	return (ll)x * p*(p+1)/2 + (ll)y * (p+1) * (p+2)/2;
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&k);
	FOR(i,1,n) {
		int t; scanf("%d", &t);
		a[t]++;	
	}
	
	FOR(i,1,m) FOR(j,0,k) f[i][j] = solve(a[i], j+1);
	
	FOR(j,0,k) g[1][j] = f[1][j];
	FOR(i,2,m) FOR(j,0,k) {
		g[i][j] = g[i-1][j] + f[i][0];
		FOR(c,1,j)
			g[i][j] = min(g[i][j], g[i-1][j-c] + f[i][c]);
	}

	printf("%lld", g[m][k]);

	return 0;
}
