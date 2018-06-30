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

typedef vector<int> data;

const int N = 1e5+5;
int n, q, a[N], L, R, k, res, cnt;
bool found;
data t[4*N], nil;

/* combine 2 child nodes (increasing vector) to the parent node (increasing vector) */
data combine(data u, data v) {
	data ans = nil;
	int i = 0, j = 0;
	while (i < sz(u) && j < sz(v)) {
		if (u[i] < v[j]) ans.pb(u[i++]);
		else ans.pb(v[j++]);
	}
	while (i < sz(u)) ans.pb(u[i++]);
	while (j < sz(v)) ans.pb(v[j++]);
	return ans;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k].pb(a[l]);
		return ;
	}
	int m = (l+r)/2;
	build(k*2, l, m);
	build(k*2+1, m+1, r);
	t[k] = combine(t[k*2], t[k*2+1]);
}

void get(int node, int l, int r) {
	if (r < L || R < l) return ;
	if (L <= l && r <= R) {
		int i = 0, j = sz(t[node])-1, pos = -1;
		while (i <= j) {
			int m = (i+j)/2;
			if (t[node][m] <= res) {
				pos = m;
				i = m+1;
			} else j = m-1;
		}
		if (pos == -1) return ;
		cnt += pos + 1;
		if (t[node][pos] == res) found = true, cnt--;
		return ;
	}
	int m = (l+r)/2;
	get(node*2,l,m);
	get(node*2+1,m+1,r);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", a+i);

	build(1,1,n);

	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &L, &R, &k);
		int l = 0, r = sz(t[1]) - 1;
		while (l <= r) {
			int m = (l+r)>>1;
			cnt = 0;
			found = false;
			res = t[1][m];
			get(1,1,n);
			if (cnt == k-1 && found) {
				printf("%d\n", res);
				break;
			}
			if (cnt < k) l = m+1;
			else r = m-1;
		}
	}

	return 0;
}

