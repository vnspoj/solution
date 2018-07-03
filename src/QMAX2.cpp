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

const int N = 5e4+5;
int n, m;
ll t[N<<2], lazy[N<<2];

void lazyUpdate(int k, int l, int r) {
	if (lazy[k] > 0) {
		t[k] += lazy[k];
		if (l < r) {
			lazy[k<<1] += lazy[k];
			lazy[k*2+1] += lazy[k];
		}
		lazy[k] = 0ll;
	}
}

void update(int k, int l, int r, int L, int R, int value) {
	lazyUpdate(k, l, r);
	if (r < L || R < l) return;
	if (L <= l && r <= R) {
		t[k] += (ll) value;
		if (l < r) {
			lazy[k<<1] += (ll) value;
			lazy[k*2+1] += (ll) value;
		}
		return;
	}
	int m = (l+r)>>1;
	update(k<<1, l, m, L, R, value);
	update(k*2+1, m+1, r, L, R, value);
	t[k] = max(t[k<<1], t[k*2+1]);
}

ll findMax(int k, int l, int r, int L, int R) {
	lazyUpdate(k,l,r);
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return t[k];
	int m = (l+r)>>1;
	return max(findMax(k<<1, l, m, L, R), findMax(k*2+1, m+1, r, L, R));
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m;
	while (m--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 0) {
			int value;
			scanf("%d", &value);
			update(1,1,n,x,y,value);
		} else {
			printf("%lld\n", findMax(1,1,n,x,y));
		}
	}

	return 0;
}
