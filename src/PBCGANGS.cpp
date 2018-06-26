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

const int N = 1001;
int n, m, u, v, pa[N], sz[N], thu[N];
char c;

int FindSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = FindSet(pa[u]);
}

void Union(int u, int v) {
	u = FindSet(u);
	v = FindSet(v);
	pa[v] = u;
	sz[u] += sz[v];
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&m);
	FOR(i,1,n) pa[i] = i, sz[i] = 1;
	FOR(i,1,m) {
		scanf("%c%d%d\n", &c,&u,&v);
		if (c == 'F') Union(u,v);
		else {
			if (thu[v]) Union(u, thu[v]);
			if (thu[u]) Union(thu[u], v);
			thu[u] = v;
			thu[v] = u;
		}
	}
	int ans = 0;
	FOR(i,1,n) ans += pa[i] == i;
	printf("%d\n", ans);


	return 0;
}
