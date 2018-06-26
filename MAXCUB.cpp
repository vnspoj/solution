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

const int N = 31, inf = 1e9;
int T, n, F[N][N][N], ans;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) {
			scanf("%d", &F[i][j][k]);
			F[i][j][k] += F[i-1][j][k] + F[i][j-1][k] + F[i][j][k-1]
			              - F[i-1][j-1][k] - F[i-1][j][k-1] - F[i][j-1][k-1]
			              + F[i-1][j-1][k-1];
		}

		ans = -inf;

		FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) {
			int lim = min(i,min(j,k));
			FOR(t,1,lim) {
				int sum = F[i][j][k]
				          - F[i-t][j][k] - F[i][j-t][k] - F[i][j][k-t]
				          + F[i][j-t][k-t] + F[i-t][j][k-t] + F[i-t][j-t][k]
				          - F[i-t][j-t][k-t];
				ans = max(ans, sum);
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
