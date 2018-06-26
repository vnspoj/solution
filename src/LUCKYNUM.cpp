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

const int N = 205;
int T, n, f[N][N], p10[N] = {1};

void solve() {
	scanf("%d", &n);
	FOR(i,0,200) FOR(j,0,200-i) f[i][j] = -1;
	FOR(i,1,200) p10[i] = p10[i-1] * 10 % n;

	queue<ii> st;
	st.push({0,1});
	f[0][1] = 6%n;
	st.push({1,0});
	f[1][0] = 8%n;

	while (! st.empty()) {
		int x = st.front().X, y = st.front().Y;
		st.pop();
		if (f[x][y] == 0) {
			FOR(i,1,x) printf("8");
			FOR(i,1,y) printf("6");
			EL;
			return ;
		}
		if (x + y == 200) continue;

		if (f[x][y+1] == -1) {
			f[x][y+1] = (f[x][y] * 10 % n + 6) % n;
			st.push({x, y + 1});
		}
		if (f[x+1][y] == -1) {
			f[x+1][y] = (8 * p10[x+y] % n + f[x][y]) % n;
			st.push({x + 1, y});
		}
	}

	puts("-1");
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> T;
	while (T--) solve();

	return 0;
}
