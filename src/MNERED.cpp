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

const int   N = 500;
int         n, m, a[N][N], f[N][N], res = N*N;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d",&n,&m);
	for (int i=1,u,v; i<=m; i++) {
		scanf("%d%d", &u,&v);
		a[u][v] = 1;
	}

	for (int j=1; j<=n; j++)
		for (int i=1; i<=n; i++)
			f[i][j] = f[i-1][j] + a[i][j];

	for (int i=1; i<=n; i++)
		for (int l=1; l<=n; l++) {
			for (int r=l; r<=n; r++) {
				int ngang = r-l+1;
				int doc   = m/ngang;
				if (m%ngang != 0 or doc <= 0 or i+doc-1 > n) continue;

				int sum = 0;
				for (int k=l; k<=r; k++)
					sum += f[i+doc-1][k] - f[i-1][k];

				res = min(res, m-sum);
			}
		}

	printf("%d", res);

	return 0;
}
