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


const int N = 101, mod = 1e9;
int n, m, a[N][N], F[N][N], ans;


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d%d", &n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);
	F[1][1] = 1;
	FOR(i,2,n) {
		F[i][1] = 1;
		FOR(j,1,i-1)
		if (__gcd(a[i][1], a[j][1]) > 1)
			F[i][1] = (F[i][1] + F[j][1]) % mod;
	}
	FOR(i,2,m)
	FOR(j,1,i-1)
	if (__gcd(a[1][i], a[1][j]) > 1)
		F[1][i] = (F[1][i] + F[1][j]) % mod;
	FOR(j,2,m)
	FOR(i,2,n)
	FOR(p,1,i) {
		int Q = j == m ? m-1 : j;
		FOR(q,1,Q)
		if (ii(i,j) != ii(p,q))
			if (__gcd(a[i][j], a[p][q]) > 1)
				F[i][j] = (F[i][j] + F[p][q]) % mod;
	}

	FOR(i,1,n) ans = (ans + F[i][m]) % mod;
	printf("%d", ans);

	return 0;
}
