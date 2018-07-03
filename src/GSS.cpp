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
	ll sum, prefix, suffix, best;
};

const int N = 50005;
const ll MAXV = 15000ll * N;
int n, a[N];
data t[N<<2];

data combine(data l, data r) {
	data res;
	res.sum = l.sum + r.sum;
	res.prefix = max(l.prefix, l.sum + r.prefix);
	res.suffix = max(r.suffix, r.sum + l.suffix);
	res.best = max(max(l.best, r.best), l.suffix + r.prefix);
	return res;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k].sum = t[k].prefix = t[k].suffix = t[k].best = (ll) a[l];
		return;
	}
	int m = (l+r)>>1;
	build(k<<1, l, m);
	build(k*2+1, m+1, r);
	t[k] = combine(t[k<<1], t[k*2+1]);
}

data findMax(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return { 0ll, -MAXV, -MAXV, -MAXV };
	if (L <= l && r <= R) return t[k];
	int m = (l+r)>>1;
	data lt = findMax(k<<1, l, m, L, R);
	data rt = findMax(k*2+1, m+1, r, L, R);
	return combine(lt, rt);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n;
	FOR(i,1,n) scanf("%d", a+i);

	build(1,1,n);

	int Q;
	cin >> Q;
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", findMax(1,1,n,l,r).best);
	}

	return 0;
}
