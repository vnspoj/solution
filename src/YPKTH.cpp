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

const int   N = 100100;
int         n, q, a[N], L, R, k, res, cnt, f;
data        t[4*N], nil;

data combine(data u, data v) {
	data ans = nil;
	int i = 0, j = 0;
	while (i < u.size() and j < v.size()) {
		if (u[i] < v[j]) ans.pb(u[i++]);
		else ans.pb(v[j++]);
	}
	while (i < u.size()) ans.pb(u[i++]);
	while (j < v.size()) ans.pb(v[j++]);
	return ans;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k].pb(a[l]);
		return ;
	}
	int mid = (l+r)/2;
	build(k*2, l, mid);
	build(k*2+1, mid+1, r);
	t[k] = combine(t[k*2], t[k*2+1]);
}

void get(int node, int l, int r) {
	if (r < L or R < l) return ;
	if (L <= l and r <= R) {
		int i = 0, j = t[node].size()-1, pos = -1;
		while (i <= j) {
			int mid = (i+j)/2;
			if (t[node][mid] <= res) {
				pos = mid;
				i = mid+1;
			} else j = mid-1;
		}
		if (pos == -1) return ;
		if (t[node][pos] == res) f = true;
		cnt += pos + 1;
		if (t[node][pos] == res) cnt--;
		return ;
	}
	int mid = (l+r)/2;
	get(node*2,l,mid);
	get(node*2+1,mid+1,r);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);

	build(1,1,n);

	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &L,&R,&k);
		int l = 0, r = t[1].size()-1;
		while (l <= r) {
			int mid = (l+r)/2;
			res = t[1][mid];
			cnt = 0;
			f = 0;
			get(1,1,n);
			if (cnt == k-1 and f) {
				printf("%d\n", res);
				break;
			}
			if (cnt < k) l = mid+1;
			else r = mid-1;
		}
	}

	return 0;
}
