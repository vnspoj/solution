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

const int N = 1e5+5;
int n, m, low[N], num[N], pa[N][21];
int tin[N], tout[N], Time;
vector<int> a[N];

void dfs(int p, int u) {
	tin[u] = ++Time;

	num[u] = ++num[0];
	low[u] = n+1;

	pa[u][0] = p;
	FOR(i,1,20) pa[u][i] = pa[pa[u][i-1]][i-1];

	for (auto v : a[u]) {
		if (v == p) continue;
		if (num[v])
			low[u] = min(low[u], num[v]);
		else {
			dfs(u,v);
			low[u] = min(low[u], low[v]);
		}
	}

	tout[u] = ++Time;
}

bool thuoc(int v, int u) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int FindParent(int p, int v) {
	FOD(i,20,0) {
		int u = pa[v][i];
		if (u > 0 && u != p && thuoc(u,p)) v = u;
	}
	return v;
}

bool solve1(int,int,int,int);
bool solve2(int,int,int);


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	while (m--) {
		int i, j;
		scanf("%d%d", &i,&j);
		a[i].pb(j);
		a[j].pb(i);
	}

	dfs(0,1);

	scanf("%d", &m);
	while (m--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int A, B, G1, G2;
			scanf("%d%d%d%d", &A, &B, &G1, &G2);
			if (solve1(A, B, G1, G2)) puts("yes");
			else puts("no");
		} else {
			int A, B, C;
			scanf("%d%d%d", &A, &B, &C);
			if (solve2(A, B, C)) puts("yes");
			else puts("no");
		}
	}

	return 0;
}

bool solve1(int A, int B, int G1, int G2) {
	if (num[G1] > num[G2]) swap(G1, G2);
	if (pa[G2][0] != G1) return true;
	if (low[G2] <= num[G1]) return true;
	if (thuoc(A,G2) == thuoc(B,G2)) return true;
	return false;
}

bool solve2(int A, int B, int C) {
	if (num[A] > num[B]) swap(A,B);
	if (pa[B][0] == A) return true;
	if (thuoc(B,A)) {
		if (thuoc(C,A) && thuoc(B,C)) {
			B = FindParent(C,B);
			if (low[B] < num[C]) return true;
			return false;
		}
		return true;
	}
	if (thuoc(C,A) || thuoc(C,B)) return true;
	if (thuoc(A,C) && thuoc(B,C)) {
		A = FindParent(C,A);
		B = FindParent(C,B);
		if (A == B) return true;
		if (low[A] < num[C] && low[B] < num[C]) return true;
		return false;
	}
	if (thuoc(A,C) || thuoc(B,C)) {
		if (thuoc(B,C)) swap(A,B);
		A = FindParent(C,A);
		if (low[A] < num[C]) return true;
		return false;
	}
	return true;
}
