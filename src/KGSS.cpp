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
	int index;
	ll value;
};

const int N = 1e5+5;
int n;
ll a[N];
data t[N<<2];

data combine(data l, data r) {
	return l.value > r.value ? l : r;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k] = { l, a[l] };
		return;
	}
	int m = (l+r)>>1;
	build(k<<1, l, m);
	build(k*2+1, m+1, r);
	t[k] = combine(t[k<<1], t[k*2+1]);
}

void update(int k, int l, int r, int x, int y) {
	if (r < x || x < l) return;
	if (l == x && r == x) {
		t[k] = { x, y };
		return;
	}
	int m = (l+r)>>1;
	update(k<<1, l, m, x, y);
	update(k*2+1, m+1, r, x, y);
	t[k] = combine(t[k<<1], t[k*2+1]);
}

data findMax(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return { -1, -1 };
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
	FOR(i,1,n) scanf("%lld", a+i);

	build(1,1,n);

	int Q;
	scanf("%d\n", &Q);
	while (Q--) {
		char c; int x, y;
		scanf("%c%d%d\n", &c, &x, &y);
		if (c == 'U') {
			update(1,1,n,x,y);
		} else {
			data p = findMax(1,1,n,x,y);
			data pl = findMax(1,1,n,x,p.index-1);
			data pr = findMax(1,1,n,p.index+1,y);
			data pm = combine(pl, pr);
			printf("%lld\n", p.value + pm.value);
		}
	}


	return 0;
}
