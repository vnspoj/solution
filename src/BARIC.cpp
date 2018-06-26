#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 105;
const ll inf = 1e18;
int n, E, a[N];
ll T[3][N][N], F[N][N][2];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> E;
	FOR(i,1,n) scanf("%d", &a[i]);

	FOR(i,1,n)
	FOR(j,i+1,n)
	T[1][i][j] = T[1][i][j-1] + 2ll * abs(a[j]-a[i]);

	FOR(i,1,n)
	FOR(j,i+1,n)
	FOR(k,i+1,j-1)
	T[2][i][j] += (ll) abs(2*a[k]-a[i]-a[j]);

	FOR(i,1,n) FOR(j,1,n) FOR(k,0,1) F[i][j][k] = inf;

	F[1][1][1] = 0ll;
	FOR(i,2,n) {
		F[i][1][1] = 0ll;
		FOR(j,1,i-1) {
			F[i][1][0] = min(F[i][1][0], F[j][1][1] + T[1][j][i]);
			F[i][1][1] += 2ll * abs(a[i]-a[j]);
		}
	}

	FOR(k,2,n)
	FOR(i,k,n)
	FOR(j,1,i-1) {
		F[i][k][0] = min(F[i][k][0], F[j][k][1] + T[1][j][i]);
		F[i][k][1] = min(F[i][k][1], F[j][k-1][1] + T[2][j][i]);
	}

	FOR(i,1,n)
	FOR(j,0,1)
	if (F[n][i][j] <= E) {
		printf("%d %lld\n", i, F[n][i][j]);
		return 0;
	}

	return 0;
}
