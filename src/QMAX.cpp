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


const int N = 50005;
int n, q, a[N], t[N<<2];

void build(int k, int l, int r) {
	if (l == r) {
		t[k] = a[l]; return;
	}
	int m = (l+r)>>1;
	build(k<<1, l, m);
	build(k*2+1, m+1, r);
	t[k] = max(t[k<<1], t[k*2+1]);
}

int findMax(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return t[k];
	int m = (l+r)>>1;
	return max(findMax(k<<1, l, m, L, R), findMax(k*2+1, m+1, r, L, R));
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> q;
	while (q--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		a[l] += k;
		a[r+1] -= k;
	}
	FOR(i,2,n) a[i] += a[i-1];

	build(1,1,n);
	cin >> q;
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", findMax(1,1,n,l,r));
	}

	return 0;
}
