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

const int N = 55, inf = 1e9;
int n, m, a[N][N], d[N][N][10][10], s, t;

struct data {
	int i, j, duoi, c, truoc, tren, phai;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

priority_queue<data> st;

#define ok   d[p][q][duoi][truoc] > d[i][j][x.duoi][x.truoc] + a[p][q] * duoi
#define upd  d[p][q][duoi][truoc] = d[i][j][x.duoi][x.truoc] + a[p][q] * duoi

void truoc(data x) {
	int i = x.i, j = x.j, p = i+1, q = j;
	int truoc = x.tren, tren = 7-x.truoc, phai = x.phai, duoi = 7-tren;
	if (p <= n && ok) {
		upd;
		st.push({p, q, duoi, d[p][q][duoi][truoc], truoc, tren, phai});
	}
}

void sau(data x) {
	int i = x.i, j = x.j, p = i-1, q = j;
	int truoc = 7-x.tren, tren = x.truoc, phai = x.phai, duoi = 7-tren;
	if (p > 0 && ok) {
		upd;
		st.push({p, q, duoi, d[p][q][duoi][truoc], truoc, tren, phai});
	}
}

void trai(data x) {
	int i = x.i, j = x.j, p = i, q = j-1;
	int truoc = x.truoc, tren = x.phai, phai = 7-x.tren, duoi = 7-tren;
	if (q > 0 && ok) {
		upd;
		st.push({p, q, duoi, d[p][q][duoi][truoc], truoc, tren, phai});
	}
}

void phai(data x) {
	int i = x.i, j = x.j, p = i, q = j+1;
	int truoc = x.truoc, tren = 7-x.phai, phai = x.tren, duoi = 7-tren;
	if (q <= m && ok) {
		upd;
		st.push({p, q, duoi, d[p][q][duoi][truoc], truoc, tren, phai});
	}
}

void dijkstra() {
	FOR(i,1,n) FOR(j,1,m)
	FOR(k,1,6) FOR(t,1,6) d[i][j][k][t] = inf;
	d[s][t][5][1] = 5 * a[s][t];
	st.push({s, t, 5, d[s][t][5][1], 1, 2, 3});
	while (! st.empty()) {
		data x = st.top();
		st.pop();
		if (x.c > d[x.i][x.j][x.duoi][x.truoc]) continue;
		truoc(x);
		sau(x);
		trai(x);
		phai(x);
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);

	scanf("%d%d", &s,&t);

	dijkstra();

	scanf("%d%d", &s,&t);

	int ans = inf;

	FOR(i,1,6)
	FOR(j,1,6) {
		if (j == i || j == 7-i) continue;
		ans = min(ans, d[s][t][i][j]);
	}

	printf("%d\n", ans);

	return 0;
}
