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
int n, k, a[N][N], InQueue[2][N][N], ans;
int dx[2][3] = {{1,0,1},{1,0,1}};
int dy[2][3] = {{0,1,1},{0,-1,-1}};
queue<ii> st[2];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> k;
	while (k--) {
		int i, j;
		scanf("%d%d", &i,&j);
		a[i][j] = 1;
	}

	st[0].push({1,1});
	InQueue[0][1][1] = 1;
	st[1].push({1,n});
	InQueue[1][1][n] = 1;

	int robot = 0, ans = 0;
	for (;;) {
		if (robot == 1) ans++;
		int sz = st[robot].size();
		while (sz--) {
			int i = st[robot].front().X, j = st[robot].front().Y;
			st[robot].pop();
			InQueue[robot][i][j] = 0;
			FOR(k,0,2) {
				int u = i + dx[robot][k], v = j + dy[robot][k];
				if (u < 1 || u > n || v < 1 || v > n || a[u][v]) continue;
				if (robot == 1 && InQueue[0][u][v]) {
					printf("%d\n", ans);
					return 0;
				}
				st[robot].push({u,v});
			}
		}
		sz = st[robot].size();
		while (sz--) {
			ii f = st[robot].front();
			st[robot].pop();
			if (! InQueue[robot][f.X][f.Y])
				st[robot].push(f), InQueue[robot][f.X][f.Y] = 1;
		}
		robot ^= 1;
	}


	return 0;
}
