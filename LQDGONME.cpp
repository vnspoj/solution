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
int n, m, a[15][N], F[N], pos[N][15], ans;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,m)
	FOR(j,1,n) {
		scanf("%d", &a[i][j]);
		pos[a[i][j]][i] = j;
	}
	FOR(x,1,n) {
		int j = a[1][x];
		FOR(y,0,x-1) {
			int i = a[1][y], ok = 1;
			FOR(k,2,m)
			if (pos[j][k] <= pos[i][k]) {
				ok = 0;
				break;
			}
			if (ok)
				F[j] = max(F[j], F[i] + 1);
		}
		ans = max(ans, F[j]);
	}
	printf("%d\n", ans);

	return 0;
}
