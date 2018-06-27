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

const int N = 1005;
int n, m, a[N][N], F[N][N], ans = 1;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m;
	FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);

	FOR(j,1,m) F[1][j] = 1;
	FOR(i,1,n) F[i][1] = 1;

	FOR(i,2,n)
	FOR(j,2,m) {
		if (a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1] && a[i][j] == a[i-1][j-1])
			F[i][j] = min(F[i-1][j], min(F[i][j-1], F[i-1][j-1])) + 1;
		else
			F[i][j] = 1;
		ans = max(ans, F[i][j]);
	}

	cout << ans;

	return 0;
}
