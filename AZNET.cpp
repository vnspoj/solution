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

struct edge {
	int u, v, c;
};

const int N = 1e4+5, M = 1e5+5;
int T, n, m, u, v, c, A, B, x, y;
int a[N], b[N], pa[N], rnk[N], dd[M];
edge e[M];

void init() {
	scanf("%d%d", &n,&m);
	FOR(i,1,n-1) scanf("%d", &a[i]);
	FOR(i,1,n-1) scanf("%d", &b[i]);
	FOR(i,1,m)
	scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
	A = B = 0;
	FOR(i,1,m) dd[i] = 0;
}

void reset() {
	FOR(i,1,n) pa[i] = i, rnk[i] = 0;
}

int FindSet(int u) {
	if (pa[u] == u) return u;
	return pa[u] = FindSet(pa[u]);
}

int check(edge e) {
	int u = FindSet(e.u);
	int v = FindSet(e.v);
	if (u == v) return 0;
	pa[v] = u;
	if (rnk[u] <  rnk[v]) swap(rnk[u], rnk[v]);
	if (rnk[u] == rnk[v]) rnk[u]++;
	return 1;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		init();
		reset();
		FOR(i,1,m)
			if (e[i].c == 1) A += check(e[i]);

		reset();

		FOR(i,1,m)
			if (e[i].c == 2) B += check(e[i]);

		int sum = 2*1e9+1;
		FOR(i, max(0,n-1-B), min(A, n-1))
			if (sum > a[i] + b[n-1-i]) {
				sum = a[i] + b[n-1-i];
				x = i;
			}
		y = n-1-x;

		FOR(i,1,m)
			if (e[i].c == 1) dd[i] = check(e[i]);

		reset();
		int cnt = 0;
		FOR(i,1,m)
			if (dd[i]) cnt += check(e[i]);
		for (int i = 1; i <= m && cnt < x; i++)
			if (e[i].c == 1 && !dd[i])
				cnt += (dd[i] = check(e[i]));
		FOR(i,1,m)
			if (e[i].c == 2) dd[i] = check(e[i]);

		FOR(i,1,m)
			if (dd[i]) printf("%d ", i);

		EL;
	}

	return 0;
}
