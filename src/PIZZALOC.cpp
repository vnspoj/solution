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
	int x, y, s, sum;
	bool operator < (const data &o) const {
		return sum > o.sum;
	}
};

int k, r, m, n, Ans;
int dn[105], dk[25], sum;
data a[25], b[105];
vector<int> adj[25];

bool in (int i, int j) {
	int x = b[i].x - a[j].x;
	int y = b[i].y - a[j].y;
	return (x*x + y*y <= r*r);
}

void dq(int x, int last, int cnt) {
	if (cnt == sum) {
		printf("%d\n", sum);
		exit(0);
	}
	if (x == k+1) {
		Ans = max(Ans, cnt);
		return ;
	}
	FOR(i,last+1,m)
	if (!dk[i]) {
		dk[i] = 1;
		for (auto j : adj[i])
			if (dn[j] == 0) cnt += b[j].s, dn[j] = x;
		dq(x+1, i, cnt);
		dk[i] = 0;
		for (auto j : adj[i])
			if (dn[j] == x) cnt -= b[j].s, dn[j] = 0;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &k,&r,&m);
	FOR(i,1,m) scanf("%d%d", &a[i].x, &a[i].y);
	scanf("%d", &n);
	FOR(i,1,n) {
		scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].s);
		int ok = 0;
		FOR(j,1,m)
		if (in(i,j)) {
			adj[j].ep(i);
			a[j].sum += b[i].s;
			ok = 1;
		}
		if (ok) sum += b[i].s;
	}

	sort(a+1, a+m+1);

	dq(1,0,0);

	printf("%d\n", Ans);

	return 0;
}
