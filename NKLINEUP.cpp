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
int n, q, a[N], tmax[4*N], tmin[4*N];

void build(int k, int l, int r) {
	if (l == r) {
		tmax[k] = tmin[k] = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(k*2, l, mid);
	build(k*2+1, mid+1, r);
	tmax[k] = max(tmax[k*2], tmax[k*2+1]);
	tmin[k] = min(tmin[k*2], tmin[k*2+1]);
}

int get_max(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return tmax[k];
	int mid = (l+r)>>1;
	return max(get_max(k*2, l, mid, L, R), get_max(k*2+1, mid+1, r, L, R));
}

int get_min(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return 1e6;
	if (L <= l && r <= R) return tmin[k];
	int mid = (l+r)>>1;
	return min(get_min(k*2, l, mid, L, R), get_min(k*2+1, mid+1, r, L, R));
}



int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> q;
	FOR(i,1,n) scanf("%d", &a[i]);

	build(1,1,n);

	while (q--) {
		int L, R;
		scanf("%d%d", &L,&R);
		int ans = get_max(1,1,n,L,R) - get_min(1,1,n,L,R);
		printf("%d\n", ans);
	}

	return 0;
}
