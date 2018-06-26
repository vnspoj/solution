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

const int   N = 2000;
int         n, m, a[N][N], b[N][N], x;
int         f[N][N], fa[N][N], fb[N][N];
char        c;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		scanf("\n");
		for (int j=1; j<=m; j++) {
			scanf("%c", &c);
			scanf("%d", &x);
			if (c == 'A')
				a[i][j] = x;
			else
				b[i][j] = x;
			scanf(" ");
		}
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			fa[i][j] = fa[i][j-1] + a[i][j];
			fb[i][j] = fb[i-1][j] + b[i][j];
		}

	for (int i=2; i<=n; i++)
		for (int j=2; j<=m; j++) {
			f[i][j] = f[i-1][j-1] + fa[i][j-1] + fb[i-1][j];
			f[i][j] = max(f[i][j], f[i-1][j] + fa[i][j-1]);
			f[i][j] = max(f[i][j], f[i][j-1] + fb[i-1][j]);
		}

	printf("%d", f[n][m]);

	return 0;
}
