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

const int N = 201, inf = 1e9;
int n, u, v, w, c[N][N], fx[N], fy[N];
int matchX[N], matchY[N], dmin[N];
int trace[N], link[N], ans;
queue<int> st;

int getC(int i, int j) {
	return c[i][j] - fx[i] - fy[j];
}

int findPath() {
	while (! st.empty()) {
		int i = st.front();
		st.pop();
		FOR(j,1,n) {
			if (trace[j]) continue;
			int w = getC(i,j);
			if (w == 0) {
				trace[j] = i;
				if (matchY[j] == 0) return j;
				st.push(matchY[j]);
			}
			if (dmin[j] > w) {
				dmin[j] = w;
				link[j] = i;
			}
		}
	}
	return -1;
}

int Xoay(int s) {
	int del = inf;
	FOR(j,1,n)
	if (trace[j] == 0) del = min(del, dmin[j]);
	fx[s] += del;
	FOR(j,1,n)
	if (trace[j]) {
		int i = matchY[j];
		fx[i] += del;
		fy[j] -= del;
	} else
		dmin[j] -= del;
	FOR(j,1,n)
	if (trace[j] == 0 && dmin[j] == 0) {
		trace[j] = link[j];
		if (matchY[j] == 0) return j;
		st.push(matchY[j]);
	}
	return -1;
}

void solve(int s) {
	FOR(j,1,n) {
		trace[j] = 0;
		dmin[j] = getC(s,j);
		link[j] = s;
	}
	st = queue<int>();
	st.push(s);
	int t = -1, k;
	while (t == -1) {
		t = findPath();
		if (t == -1) t = Xoay(s);
	}
	while (t != 0) {
		s = trace[t];
		k = matchX[s];
		matchX[s] = t;
		matchY[t] = s;
		t = k;
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);

	FOR(i,1,n) FOR(j,1,n) c[i][j] = inf;
	while (scanf("%d%d%d", &u,&v,&w) != EOF) c[u][v] = w;

	FOR(i,1,n) {
		fx[i] = inf;
		FOR(j,1,n) fx[i] = min(fx[i], c[i][j]);
	}
	FOR(j,1,n) {
		fy[j] = inf;
		FOR(i,1,n) fy[j] = min(fy[j], c[i][j] - fx[i]);
	}

	FOR(i,1,n) solve(i);

	FOR(i,1,n) ans += c[i][matchX[i]];

	printf("%d\n", ans);
	FOR(i,1,n) printf("%d %d\n", i, matchX[i]);

	return 0;
}
