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

const int N = 550;
int n, a[N][N], F[N][N];
vector<int> ans;

int next(int i, int kc) {
	return (i + kc + n - 1) % n + 1;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) FOR(j,1,n) scanf("%d", &a[i][j]);
	FOR(i,1,n-1) F[i][i+1] = 1;
	F[n][1] = 1;
	FOR(kc,2,n-1) {
		FOR(i,1,n) {
			int j = next(i, kc), k = i;
			FOR(cnt,1,kc-1) {
				k = next(k, 1);
				if (F[i][k] && F[k][j] && (a[i][k] || a[j][k])) {
					F[i][j] = 1;
					break;
				}
			}
		}
	}

	FOR(i,1,n) {
		int j = i;
		FOR(cnt,1,n-1) {
			j = next(j, 1);
			if (F[i][j] && F[j][i] && a[i][j]) {
				ans.ep(i);
				break;
			}
		}
	}

	printf("%d\n", ans.size());
	for (auto i : ans) printf("%d\n", i);


	return 0;
}
