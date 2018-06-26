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

const int N = 35;
int n, a[N][N], b[N][N], d[N], s[N], ans[N], dd[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n)
	FOR(j,1,n) {
		scanf("%d", &a[i][j]);
		if (i == j || a[i][j] == 2) continue;
		d[i] += a[i][j];
	}

	FOR(i,1,n) {
		FOR(j,1,n) {
			s[j] = d[j];
			dd[j] = 0;
			FOR(k,1,n) b[j][k] = a[j][k];
		}
		FOR(j,1,n) {
			if (i == j || a[i][j] != 2) continue;
			b[i][j] = 1;
			b[j][i] = 0;
			s[i]++;
		}
		dd[i] = 1;
		FOR(cnt,1,n-1) {
			int j = 0, Min = n+1;
			FOR(k,2,n)
			if (Min > s[k] && !dd[k]) Min = s[k], j = k;
			dd[j] = 1;
			if (s[i] < s[j]) break;
			while (s[j] < s[i]) {
				int k = 0, Max = 0;
				FOR(p,1,n)
				if (Max < s[p] && b[j][p] == 2) Max = s[p], k = p;
				if (k == 0) break;
				s[j]++;
				b[j][k] = 1;
				b[k][j] = 0;
			}
			FOR(k,1,n) {
				if (k == i || k == j) continue;
				if (b[j][k] == 2) {
					s[k]++;
					b[j][k] = 0;
					b[k][j] = 1;
				}
			}
		}
		ans[i] = 1;
		FOR(j,1,n) if (s[i] < s[j]) ans[i] = 0;
	}

	FOR(i,1,n) printf("%d", ans[i]);

	return 0;
}
