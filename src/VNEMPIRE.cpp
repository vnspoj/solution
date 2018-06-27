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

struct data {
	int x, y, z, id;
};

bool cmp1(data u, data v) {
	return u.x < v.x;
}
bool cmp2(data u, data v) {
	return u.y < v.y;
}
bool cmp3(data u, data v) {
	return u.z < v.z;
}

const int N = 1e5+5;
int n, m, pa[N], rnk[N];
data a[N], s[N*3];
ll ans;

int d(data u, data v) {
	return min(abs(u.x-v.x), min(abs(u.y-v.y), abs(u.z-v.z)));
}

void upd() {
	FOR(i,1,n-1)
	s[++m] = {d(a[i], a[i+1]), a[i].id, a[i+1].id};
}

int FindSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = FindSet(pa[u]);
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);

	FOR(i,1,n) {
		int x, y, z;
		scanf("%d%d%d", &x,&y,&z);
		a[i] = {x,y,z,i};
	}

	sort(a+1,a+n+1,cmp1);
	upd();
	sort(a+1,a+n+1,cmp2);
	upd();
	sort(a+1,a+n+1,cmp3);
	upd();

	sort(s+1,s+m+1,cmp1);

	FOR(i,1,n) pa[i] = i, rnk[i] = 0;

	FOR(i,1,m) {
		int u = FindSet(s[i].y), v = FindSet(s[i].z);
		if (u == v) continue;
		pa[v] = u;
		if (rnk[v] > rnk[u]) swap(rnk[u], rnk[v]);
		if (rnk[v] == rnk[u]) rnk[u]++;
		ans += (ll) s[i].x;
	}

	printf("%lld\n", ans);


	return 0;
}
