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


const int N = 10005, inf = N;
int n, m, low[N], num[N], pa[N];
vector<int> a[N];

void dfs(int u) {
	num[u] = ++num[0];
	low[u] = inf;
	for (auto v : a[u]) {
		if (v == pa[u]) continue ;
		if (num[v]) low[u] = min(low[u], num[v]);
		else {
			pa[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
}

int find_khop() {
	int khop[N] = {0}, con[N] = {0};
	FOR(v,1,n) {
		int u = pa[v];
		if (u > 0) con[u]++;
	}
	FOR(v,1,n) {
		int u = pa[v];
		if (u > 0 && pa[u] > 0 && low[v] >= num[u]) khop[u] = 1;
	}
	FOR(u,1,n)
	if (pa[u] == 0 && con[u] >= 2) khop[u] = 1;
	FOR(u,1,n) khop[0] += khop[u] == 1;
	return khop[0];
}

int find_cau() {
	int cau = 0;
	FOR(v,1,n)
	cau += pa[v] > 0 && low[v] >= num[v];
	return cau;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,m) {
		int u, v;
		scanf("%d%d", &u,&v);
		a[u].ep(v);
		a[v].ep(u);
	}
	FOR(u,1,n) if (!num[u]) dfs(u);
	printf("%d %d\n", find_khop(), find_cau());

	return 0;
}
