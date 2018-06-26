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

const int   N = 600;
int         n, t, f[N][N], a[N][N], h[N][N], c[N][N];


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				scanf("%d", &a[i][j]), a[i][j] %= 2;

		memset(f, 0, sizeof f);
		memset(h, 0, sizeof h);
		memset(c, 0, sizeof c);

		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				h[i][j] = (h[i][j-1] + a[i][j]) % 2;
				c[j][i] = (c[j][i-1] + a[i][j]) % 2;
			}
		}

		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				f[i][j] = (!f[i-1][j] and !h[i][j] or (!f[i][j-1] and !c[j][i]));

		if (f[n][n])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
