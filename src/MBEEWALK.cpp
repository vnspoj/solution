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

int dx[] = {-1,-1,0,0,1,1};
int dy[2][6] = {{-1,0,-1,1,-1,0}, {0,1,-1,1,0,1}};
int r = 50, F[100][100][15], dd[100][100];

void bfs() {
	queue<ii> st;
	st.push(ii(r,r));
	F[r][r][0] = 1;
	dd[r][r] = 1;
	FOR(step,1,14) {
		int sz = st.size();
		while (sz--) {
			int i = st.front().X, j = st.front().Y;
			st.pop();
			dd[i][j] = 0;
			FOR(k,0,5) {
				int u = i + dx[k], v = j + dy[i%2][k];
				F[u][v][step] += F[i][j][step-1];
				st.push(ii(u,v));
			}
		}
		sz = st.size();
		while (sz--) {
			int i = st.front().X, j = st.front().Y;
			st.pop();
			if (! dd[i][j])
				st.push(ii(i,j)), dd[i][j] = 1;
		}
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	bfs();

	int T, n;
	cin >> T;
	while (T--)
		scanf("%d", &n), printf("%d\n", F[r][r][n]);

	return 0;
}
