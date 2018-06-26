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


const int N = 505;
const ll inf = 1e9;
int n, m, k, ans, i1, i2, J1, j2;
ll  F[N][N];


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&k);
	FOR(i,1,n)
	FOR(j,1,m) {
		int x;
		scanf("%d", &x);
		F[i][j] = F[i-1][j] + F[i][j-1] + (ll) x - F[i-1][j-1];
	}

	ans = inf;

	FOR(L,1,m)
	FOR(R,L,m) {
		int i = 1, j = 1;
		while (i <= j && j <= n) {
			ll W = F[j][R] - F[j][L-1] - F[i-1][R] + F[i-1][L-1];
			if (W >= k) {
				int S = (R-L+1) * (j-i+1);
				if (S < ans)
					ans = S, i1 = i, J1 = L, i2 = j, j2 = R;
				i++;
			} else
				j++;
		}
	}

	if (ans == inf) puts("-1");
	else
		printf("%d\n%d %d %d %d\n", ans, i1, J1, i2, j2);

	return 0;
}
