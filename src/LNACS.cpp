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

const int N = 1500;
int n, m, a[N], b[N], F[N][N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,n) scanf("%d", &a[i]);
	FOR(j,1,m) scanf("%d", &b[j]);
	FOR(i,1,n) F[i][1] = F[i-1][1] || a[i] == b[1];
	FOR(j,1,m) F[1][j] = F[1][j-1] || a[1] == b[j];
	FOR(i,2,n)
	FOR(j,2,m) {
		F[i][j] = max(F[i-1][j], F[i][j-1]);
		if (a[i] == b[j])
			F[i][j] = max(F[i][j], F[i-2][j-2] + 1);
	}
	printf("%d\n", F[n][m]);

	return 0;
}
