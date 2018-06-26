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
	int l, r;
	ll  p;
};

const int   N = 600000, T = 4*N;
const ll    oo = ll(1000000000000000ll);
int         n;
data        a[N];
ll          t[T], lazy[T], ans;

void make_tree(int k, int l, int r) {
	if (l == r) {
		if (l == 0)
			t[k] = lazy[k] = 0;
		else
			t[k] = lazy[k] = oo;
		return ;
	}
	int mid = (l+r)/2;
	make_tree(k*2,l,mid);
	make_tree(k*2+1,mid+1,r);
	t[k] = max(t[k*2], t[k*2+1]);
	lazy[k] = max(lazy[k*2], lazy[k*2+1]);
}

void lazy_update(int k, int l, int r) {
	if (lazy[k] < oo) {
		t[k] = min(t[k], lazy[k]);
		if (l < r) {
			lazy[k*2] = min(lazy[k*2], t[k]);
			lazy[k*2+1] = min(lazy[k*2+1], t[k]);
		}
		lazy[k] = oo;
	}
}

ll get(int k, int l, int r, int v) {
	if (r < v or v < l) return oo;
	lazy_update(k,l,r);
	if (l == r and r == v) return t[k];
	int mid = (l+r)/2;
	if (mid < v)
		return get(k*2+1, mid+1, r, v);
	if (v < mid+1)
		return get(k*2, l, mid, v);
}

void update(int k, int l, int r, int L, int R, ll val) {
	if (r < L or R < l or l > r) return ;
	lazy_update(k,l,r);
	if (L <= l and r <= R) {
		t[k] = min(t[k], val);
		if (l < r) {
			lazy[k*2] = min(lazy[k*2], t[k]);
			lazy[k*2+1] = min(lazy[k*2+1], t[k]);
		}
		lazy[k] = oo;
		return ;
	}
	int mid = (l+r)/2;
	update(k*2, l, mid, L, R, val);
	update(k*2+1, mid+1, r, L, R, val);
	t[k] = max(t[k*2], t[k*2+1]);
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d%lld", &a[i].r, &a[i].p);
		a[i].l = i-1;
	}

	make_tree(1,0,n);

	for (int i=0; i<=n; i++) {
		ans = get(1,0,n,i);
		if (i == n) break;
		update(1,0,n, a[i+1].l+1, a[i+1].r, a[i+1].p + ans);
	}

	printf("%lld", ans);


	return 0;
}
