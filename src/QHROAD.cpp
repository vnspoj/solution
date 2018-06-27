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
	int u;
	int v;
};

const int   N = 200000;
int         n, m, q, lab[N], ans, res[N], query[N], dd[N];
edge        e[N];

void Union(int u, int v) {
	int x = lab[u] + lab[v];
	if (lab[u] > lab[v]) {
		lab[v] = u;
		lab[u] = x;
	} else {
		lab[u] = v;
		lab[v] = x;
	}
}

int get(int u) {
	while (lab[u] > 0) u = lab[u];
	return u;
}

void check(int u, int v) {
	int s = get(u), t = get(v);
	if (s != t) {
		ans--;
		Union(s, t);
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&q);
	for (int i=1; i<=m; i++) scanf("%d%d", &e[i].u, &e[i].v);
	for (int i=1; i<=q; i++) scanf("%d", &query[i]), dd[query[i]] = 1;

	ans = n;
	for (int i=1; i<=m; i++)
		if (not dd[i]) check(e[i].u, e[i].v);

	res[q] = ans;
	for (int i=q; i>0; i--) {
		int j = query[i];
		check(e[j].u, e[j].v);
		res[i-1] = ans;
	}

	for (int i=1; i<=q; i++) printf("%d\n", res[i]);

	return 0;
}
