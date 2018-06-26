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

const int N = 10010;
int n, m, pa[N], Rank[N];

int FindSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = FindSet(pa[u]);
}

void Union(int u, int v) {
	u = FindSet(u);
	v = FindSet(v);
	if (u == v) return ;
	pa[v] = u;
	if (Rank[v] > Rank[u]) swap(Rank[v], Rank[u]);
	if (Rank[v] == Rank[u]) Rank[u]++;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&m);
	FOR(i,1,n) pa[i] = i;
	FOR(v,2,n) {
		int u, k;
		scanf("%d%d\n", &u,&k);
		if (k == 1) Union(u,v);
	}
	FOR(i,1,m) {
		int u, v;
		scanf("%d%d\n", &u,&v);
		printf("%s\n", FindSet(u) == FindSet(v) ? "NO" : "YES");
	}

	return 0;
}
