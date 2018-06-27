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

const int N = 1001;
int T, n, m, c[N][N];
ll  F[N][N][2];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n,&m);
		FOR(i,1,n) FOR(j,1,m) scanf("%d", &c[i][j]);

		F[1][1][0] = F[1][1][1] = (ll) c[1][1];
		FOR(i,2,m) {
			F[1][i][1] = (ll) c[1][i];
			F[1][i][0] = min(F[1][i-1][0], F[1][i-1][1] + (ll) c[1][i]);
		}
		FOR(i,2,n) {
			F[i][1][0] = (ll) c[i][1];
			F[i][1][1] = min(F[i-1][1][1], F[i-1][1][0] + (ll) c[i][1]);
		}

		FOR(i,2,n)
		FOR(j,2,m) {
			F[i][j][0] = min(min(
			                   F[i-1][j-1][0] + (ll) c[i][j] + c[i][j-1],
			                   F[i-1][j-1][1] + (ll) c[i][j]), F[i][j-1][0]);

			F[i][j][1] = min(min(
			                   F[i-1][j-1][1] + (ll) c[i][j] + c[i-1][j],
			                   F[i-1][j-1][0] + (ll) c[i][j]), F[i-1][j][1]);
		}

		printf("%lld\n", min(F[n][m][0], F[n][m][1]));
	}

	return 0;
}
