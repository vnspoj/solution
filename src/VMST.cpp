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

struct edge {
	int u, v, select;
};

const int   N = 4000;
int         n, m, lab[N];
edge        e[N];

void uni(int u, int v) {
	int x = lab[u] + lab[v];
	if (lab[u] < lab[v]) {
		lab[u] = x;
		lab[v] = u;
	} else {
		lab[v] = x;
		lab[u] = v;
	}
}

int get(int u) {
	while (lab[u] > 0) u = lab[u];
	return u;
}

void check(edge &e) {
	int u = get(e.u), v = get(e.v);
	if (u != v) {
		uni(u,v);
		e.select = 1;
	}
}

void init() {
	for (int i=1; i<=m; i++) e[i].select = 0;
	for (int i=1; i<=n; i++) lab[i] = -1;
}

void xuat() {
	for (int i=1; i<=m; i++)
		if (e[i].select) printf("%d %d\n", e[i].u, e[i].v);
}

bool cmp(const edge u, const edge v) {
	return (u.v < v.v);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf("%d %d", &e[i].u, &e[i].v);

	printf("3\n");

	init();
	for (int i=1; i<=m; i++) check(e[i]);
	xuat();

	init();
	for (int i=m; i>=1; i--) check(e[i]);
	xuat();


	init();
	for (int i=1; i<=m/3; i++) check(e[i]);
	for (int i=2*m/3+1; i<=m; i++) check(e[i]);
	for (int i=m/3+1; i<=2*m/3; i++) check(e[i]);
	xuat();


	return 0;
}
