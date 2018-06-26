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


struct data {
	int i, j, k;
};

const int N = 1005, inf = 1e9;
int n, m, a[N][N], d[N][N][2], F[N][N][2], InQueue[N][N][2];
queue<data> st;

void push(int i, int j, int k) {
	if (! InQueue[i][j][k])
		st.push({i,j,k}), InQueue[i][j][k] = 1;
}

void update(int i, int j, int k, int u, int v, int g) {
	if (d[u][v][g] > d[i][j][k] + 1) {
		d[u][v][g] = d[i][j][k] + 1;
		F[u][v][g] = F[i][j][k];
		push(u, v, g);
	} else if (d[u][v][g] == d[i][j][k] + 1)
		F[u][v][g] += F[i][j][k];
}



int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);
	FOR(i,2,n) FOR(j,1,m) FOR(k,0,1) d[i][j][k] = inf;
	FOR(i,1,1) FOR(j,1,m)
	d[i][j][1] = inf, d[i][j][0] = F[i][j][0] = 1, push(i,j,0);


	while (! st.empty()) {
		data f = st.front();
		st.pop();
		int i = f.i, j = f.j, k = f.k;
		InQueue[i][j][k] = 0;
		if (a[i][j] == 0) {
			if (k == 0) {
				if (j < m)
					update(i, j, k, i, j+1, a[i][j] == a[i][j+1] ? k^1 : k);
				if (i > 1)
					update(i, j, k, i-1, j, k^1);
			} else {
				if (j > 1)
					update(i, j, k, i, j-1, a[i][j] == a[i][j-1] ? k^1 : k);
				if (i < n)
					update(i, j, k, i+1, j, k^1);
			}
		} else {
			if (k == 0) {
				if (j > 1)
					update(i, j, k, i, j-1, a[i][j] == a[i][j-1] ? k^1 : k);
				if (i > 1)
					update(i, j, k, i-1, j, k^1);
			} else {
				if (j < m)
					update(i, j, k, i, j+1, a[i][j] == a[i][j+1] ? k^1 : k);
				if (i < n)
					update(i, j, k, i+1, j, k^1);
			}
		}
	}

	int ans = inf, cnt;
	FOR(i,1,m)
	if (ans > d[n][i][1])
		ans = d[n][i][1], cnt = F[n][i][1];
	else if (ans == d[n][i][1])
		cnt += F[n][i][1];

	if (ans == inf) puts("0 0");
	else printf("%d %d\n", ans, cnt);

	return 0;
}
