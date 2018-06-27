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


const int   N = 10009, M = 509;
int         n, m, a[N], f1[N][M], f2[N][M], f3[N][M];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	for (int i=1; i<=n; i++) {
		for (int j=m; j>=0; j--) {
			// bo qua : 1
			f1[i][j] = max(max(f1[i-1][j], f2[i-1][j]),f3[i-1][j]);
			// bo ho lo : 2
			if (j < m)
				f2[i][j] = max(max(f1[i-1][j+1], f2[i-1][j+1]), f3[i-1][j+1]);
			// lay ho lo : 3
			if (j == 1)
				f3[i][j] = max(f1[i-1][0], f2[i-1][0]) + a[i];
			if (j  > 1)
				f3[i][j] = f3[i-1][j-1] + a[i];
		}
	}
	printf("%d", max(f1[n][0], f2[n][0]));


	return 0;
}
