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

const int   N = 3000, oo = 100000000;
int         n;
ll          f[N][N], a[N], s[N][N];


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[i] += a[i-1];
	}

	for (int i=1; i<=n; i++) s[i][i] = i;

	for (int j=2; j<=n; j++)
		for (int i=j-1; i>0; i--) {
			f[i][j] = oo;
			for (int k=s[i][j-1]; k<=s[i+1][j]; k++) {
				if (f[i][j] > f[i][k] + f[k+1][j] + a[j]-a[i-1]) {
					f[i][j] = f[i][k] + f[k+1][j] + a[j]-a[i-1];
					s[i][j] = k;
				}
			}
		}

	printf("%lld", f[1][n]);

	return 0;
}
