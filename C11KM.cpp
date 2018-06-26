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

const int N = 1010, oo = N*300;
int n, a[N], F[N][N], ans = oo;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[i]);
	FOR(i,0,n+1) FOR(j,0,n+1) F[i][j] = oo;
	F[0][0] = 0;
	FOR(i,1,n)
	FOR(j,0,n)
	if (a[i] > 100 && j > 0)
		F[i][j] = min(F[i-1][j-1] + a[i], F[i-1][j+1]);
	else
		F[i][j] = min(F[i-1][j] + a[i], F[i-1][j+1]);
	FOR(i,0,n) ans = min(ans, F[n][i]);
	printf("%d\n", ans);

	return 0;
}
