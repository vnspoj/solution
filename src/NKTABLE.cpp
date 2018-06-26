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
int n, m, a[N][N], dd[N][N], dir[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
ii st[N*N];
int L, R;

void bfs() {
	L = R = 1;
	st[1] = {n,m};
	dd[n][m] = 1;
	while (L <= R) {
		int RR = R;
		FOD(priority,1,0) {
			FOR(q,L,RR) {
				int i = st[q].X, j = st[q].Y;
				if (i == 1 && j == 1) return ;
				FOR(k,0,1) {
					int u = i + dx[k], v = j + dy[k];
					if (u < 1 || v < 1 || a[u][v] != priority || dd[u][v]) continue;
					dir[u][v] = k;
					dd[u][v] = 1;
					st[++R] = {u,v};
				}
			}
		}
		L = RR+1;
	}
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);

	bfs();

	int i = 1, j = 1;
	for (;;) {
		printf("%d", a[i][j]);
		if (i == n && j == m) break;
		int k = dir[i][j] + 2;
		i += dx[k];
		j += dy[k];
	}


	return 0;
}
