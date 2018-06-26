#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


const int N = 201;
int n, c[N][N], matchX[N], matchY[N], trace[N];
vector<int> a[N];
int f[N*N], ans;

int findPath() {
	queue<int> st;
	FOR(i,1,n) trace[i] = 0;
	FOR(i,1,n)
	if (matchX[i] == 0) st.push(i);
	while (! st.empty()) {
		int u = st.front();
		st.pop();
		for (auto v : a[u]) {
			if (trace[v]) continue;
			trace[v] = u;
			if (matchY[v] == 0) return v;
			st.push(matchY[v]);
		}
	}
	return -1;
}

bool solve(int time) {
	FOR(i,1,n) {
		a[i].clear();
		matchX[i] = matchY[i] = 0;
	}
	FOR(i,1,n)
	FOR(j,1,n)
	if (c[i][j] <= time) a[i].pb(j);
	for (;;) {
		int v = findPath();
		if (v == -1) break;
		while (v != 0) {
			int u = trace[v];
			int k = matchX[u];
			matchX[u] = v;
			matchY[v] = u;
			v = k;
		}
	}
	FOR(i,1,n)
	if (matchX[i] == 0) return false;
	return true;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n)
	FOR(j,1,n)
	scanf("%d", &c[i][j]), f[++f[0]] = c[i][j];

	sort(f+1, f+f[0]+1);
	f[0] = unique(f+1, f+f[0]+1)-f-1;

	int L = 1, R = f[0];
	while (L <= R) {
		int mid = (L+R)/2;
		if (solve(f[mid])) {
			ans = f[mid];
			R = mid-1;
		} else
			L = mid+1;
	}

	printf("%d\n", ans);


	return 0;
}
