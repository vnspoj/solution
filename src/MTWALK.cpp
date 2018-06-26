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

const int N = 105;
int n, a[N][N], dd[N][N], hmax, hmin;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

bool bfs(int del) {
	FOR(L, hmin, hmax-del) {
		int R = L + del;
		if (a[1][1] < L || a[1][1] > R) continue;
		FOR(i,1,n) FOR(j,1,n) dd[i][j] = 0;
		dd[1][1] = 1;
		queue<ii> st;
		st.push({1,1});
		while (! st.empty()) {
			int i = st.front().X, j = st.front().Y;
			st.pop();
			if (i == n && j == n) return true;
			FOR(k,0,3) {
				int u = i + dx[k], v = j + dy[k];
				if (u < 1 || u > n || v < 1 || v > n) continue;
				if (a[u][v] < L || a[u][v] > R || dd[u][v]) continue;
				dd[u][v] = 1;
				st.push({u,v});
			}
		}
	}
	return false;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n;
	hmax = 0;
	hmin = 110;
	FOR(i,1,n)
	FOR(j,1,n) {
		scanf("%d", &a[i][j]);
		hmax = max(hmax, a[i][j]);
		hmin = min(hmin, a[i][j]);
	}

	int L = 0, R = hmax - hmin, ans = 0;
	while (L <= R) {
		int mid = (L+R)/2;
		if (bfs(mid))
			ans = mid, R = mid-1;
		else
			L = mid+1;
	}

	printf("%d\n", ans);


	return 0;
}
