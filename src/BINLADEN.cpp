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

typedef int data[3000][20];

const int inf = 1e9;
int n, m, ans = inf;
data a, b, d;

struct heap {
	int i, j, c;
	bool operator < (const heap &o) const {
		return c > o.c;
	}
};

priority_queue<heap> st;

void up(heap x) {
	int i = x.i, j = x.j, p = i-1, q = j;
	if (d[p][q] > d[i][j] + a[i][j]) {
		d[p][q] = d[i][j] + a[i][j];
		st.push({p, q, d[p][q]});
	}
}

void down(heap x) {
	int i = x.i, j = x.j, p = i+1, q = j;
	if (p <= n && d[p][q] > d[i][j] + a[p][q]) {
		d[p][q] = d[i][j] + a[p][q];
		st.push({p, q, d[p][q]});
	}
}

void left(heap x) {
	int i = x.i, j = x.j, p = i, q = j-1;
	if (q > 0 && d[p][q] > d[i][j] + b[p][q]) {
		d[p][q] = d[i][j] + b[p][q];
		st.push({p, q, d[p][q]});
	}
}

void right(heap x) {
	int i = x.i, j = x.j, p = i, q = j+1;
	if (q <= m && d[p][q] > d[i][j] + b[i][j]) {
		d[p][q] = d[i][j] + b[i][j];
		st.push({p, q, d[p][q]});
	}
}

void dijkstra() {
	FOR(i,0,n) FOR(j,1,m) d[i][j] = inf;
	d[n][m] = 0;
	st.push({n, m, d[n][m]});
	while (! st.empty()) {
		heap x = st.top();
		st.pop();
		if (x.i == 0) ans = min(ans, d[x.i][x.j]);
		if (x.c > d[x.i][x.j] || x.i == 0) continue;
		up(x);
		down(x);
		left(x);
		right(x);
	}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,2*n) {
		if (i%2)
			FOR(j,1,m) scanf("%d", &a[(i+1)/2][j]);
		else
			FOR(j,1,m-1) scanf("%d", &b[(i+1)/2][j]);
	}

	dijkstra();

	printf("%d\n", ans);

	return 0;
}
