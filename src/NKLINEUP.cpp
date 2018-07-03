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
	int vmax, vmin;
};

const int N = 50005;
const int HMAX = 1e6+6;
int n, q, a[N];
data t[N<<2];

data combine(data l, data r) {
	return {
		max(l.vmax, r.vmax),
		min(l.vmin, r.vmin)
	};
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k] = { a[l], a[l] };
		return;
	}
	int m = (l+r)>>1;
	build(k<<1, l, m);
	build(k*2+1, m+1, r);
	t[k] = combine(t[k<<1], t[k*2+1]);
}

int findMax(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return t[k].vmax;
	int m = (l+r)>>1;
	return max(findMax(k<<1, l, m, L, R), findMax(k*2+1, m+1, r, L, R));
}

int findMin(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return HMAX;
	if (L <= l && r <= R) return t[k].vmin;
	int m = (l+r)>>1;
	return min(findMin(k<<1, l, m, L, R), findMin(k*2+1, m+1, r, L, R));
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> q;
	FOR(i,1,n) scanf("%d", a+i);

	build(1,1,n);

	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int res = findMax(1,1,n,l,r) - findMin(1,1,n,l,r);
		printf("%d\n", res);
	}

	return 0;
}
