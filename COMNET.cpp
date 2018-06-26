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
	int u, v, o, n;
};

const int N = 1e5+5, M = 1e6+6;
int t, n, m, q, u, v, c, k, pa[N], Rank[N];
vector<ii> a[N];
edge e[M];
int test[111];

int FindSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = FindSet(pa[u]);
}

void Union(int u, int v) {
	u = FindSet(u);
	v = FindSet(v);
	if (u == v) return ;
	pa[v] = u;
	if (Rank[v] > Rank[u]) swap(Rank[u], Rank[v]);
	if (Rank[u] == Rank[v]) Rank[u]++;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &t);
	while (t--) {
		scanf("%d%d%d\n", &n,&m,&q);
		FOR(i,1,m) scanf("%d%d%d\n", &e[i].u, &e[i].v, &e[i].o);
		while (q--) {
			FOR(i,1,n) pa[i] = i, Rank[i] = 0;
			scanf("%d%d", &k, &v);
			FOR(i,1,v) {
				scanf("%d%d\n", &u, &c);
				e[u].n = c;
				swap(e[u].n, e[u].o);
				test[i] = u;
			}
			FOR(i,1,m) if (e[i].o < e[k].o) Union(e[i].u, e[i].v);
			printf("%s\n", FindSet(e[k].u) == FindSet(e[k].v) ? "YES" : "NO");
			FOR(i,1,v) {
				u = test[i];
				swap(e[u].o, e[u].n);
			}
		}
	}

	return 0;
}
