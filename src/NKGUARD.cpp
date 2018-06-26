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

const int N = 705;
int n, m, a[N][N], dd[N][N], ans;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void bfs(int i, int j) {
	int ok = 1;
	queue<ii> st;
	st.push({i,j});
	dd[i][j] = 1;
	while (!st.empty()) {
		i = st.front().X, j = st.front().Y;
		st.pop();
		FOR(k,0,7) {
			int u = i + dx[k], v = j + dy[k];
			if (u < 1 || u > n || v < 1 || v > m) continue;
			if (a[u][v] == a[i][j] && !dd[u][v]) {
				dd[u][v] = 1;
				st.push({u,v});
			}
			if (a[u][v] > a[i][j]) ok = 0;
		}
	}
	ans += ok;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);

	FOR(i,1,n) FOR(j,1,m) if (!dd[i][j]) bfs(i,j);

	printf("%d\n", ans);

	return 0;
}
