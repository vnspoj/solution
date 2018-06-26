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


const int   N = 3000;
int         n;
int         a[N], f[N][N], s[N][N];


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		s[i][i] = i;
		a[i] += a[i-1];
	}

	for (int j=2; j<=n; j++)
		for (int i=j-1; i>0; i--) {
			for (int k=s[i][j-1]; k<=s[i+1][j]; k++) {
				ll ans = min(f[i][k]+a[k]-a[i-1], f[k+1][j]+a[j]-a[k]);
				if (f[i][j] < ans) {
					f[i][j] = ans;
					s[i][j] = k;
				}
			}
		}

	printf("%d", f[1][n]);


	return 0;
}
