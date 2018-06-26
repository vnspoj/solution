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

const int N = 105, inf = 1e9;
int n, m, a[N][N], F[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

struct data {
	int i, j, c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

priority_queue<data> st;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m;
	FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);

	FOR(i,1,n) FOR(j,1,m) F[i][j] = inf;

	FOR(i,1,m) {
		F[1][i] = a[1][i];
		st.push({1,i,F[1][i]});
		F[n][i] = a[n][i];
		st.push({n,i,F[n][i]});
	}
	FOR(i,1,n) {
		F[i][1] = a[i][1];
		st.push({i,1,F[i][1]});
		F[i][m] = a[i][m];
		st.push({i,m,F[i][m]});
	}

	while (! st.empty()) {
		data t = st.top();
		st.pop();
		if (t.c > F[t.i][t.j]) continue;
		FOR(k,0,3) {
			int i = t.i + dx[k], j = t.j + dy[k];
			if (i <= 1 || i >= n || j <= 1 || j >= m) continue;
			int c = max(F[t.i][t.j], a[i][j]);
			if (F[i][j] > c) {
				F[i][j] = c;
				st.push({i, j, F[i][j]});
			}
		}
	}

	int ans = 0;
	FOR(i,1,n) FOR(j,1,m) ans += F[i][j] - a[i][j];

	printf("%d\n", ans);


	return 0;
}
