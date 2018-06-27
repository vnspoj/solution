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

const int   N = 100010;
int         n, m, a[N], b[N], c[N], x[N];
int         n1, n2, cnt, res, ans, t[N];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n1,&n2,&n);
	for (int i=1,k; i<=n1; i++) {
		scanf("%d", &k);
		if (x[k] == 0) {
			x[k] = 1;
			c[++m] = k;
		}
	}

	for (int i=1,k; i<=n2; i++) {
		scanf("%d", &k);
		x[k] = -1;
	}
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);

	a[n+1] = N-1;
	x[N-1] = -1;
	for (int i=1; i<=n+1; i++) {
		if (x[a[i]] != -1) {
			ans++;
			cnt += (x[a[i]] == 1 and t[a[i]] == 0);
			t[a[i]] = 1;
		} else {
			if (cnt == m) res = max(res, ans);
			ans = cnt = 0;
			for (int j=1; j<=m; j++) t[c[j]] = 0;
		}
	}
	printf("%d",res);

	return 0;
}
