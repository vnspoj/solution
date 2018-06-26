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

const int N = 10000;
int n, u, v, t, pa[N+1], rnk[N+1];

int FindSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = FindSet(pa[u]);
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	FOR(i,1,N) pa[i] = i, rnk[i] = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &u,&v,&t);
		u = FindSet(u);
		v = FindSet(v);
		if (t == 1) {
			pa[v] = u;
			if (rnk[u] < rnk[v]) swap(rnk[u], rnk[v]);
			if (rnk[u] == rnk[v]) rnk[u]++;
		} else {
			printf("%d\n", u == v);
		}
	}


	return 0;
}
