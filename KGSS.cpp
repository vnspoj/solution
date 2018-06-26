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

const int N = 1e5+5;
int n, q, a[N];
ii t[4*N];

ii combine(ii L, ii R) {
	return L.Y > R.Y ? L : R;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k] = {l, a[l]};
		return ;
	}
	int mid = (l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k] = combine(t[k*2], t[k*2+1]);
}

void upd(int k, int l, int r, int p, int v) {
	if (r < p || p < l) return ;
	if (l == p && r == p) {
		t[k] = {l,v};
		return ;
	}
	int mid = (l+r)/2;
	upd(k*2, l, mid, p, v);
	upd(k*2+1, mid+1, r, p, v);
	t[k] = combine(t[k*2], t[k*2+1]);
}

ii get(int k, int l, int r, int L, int R) {
	if (l > r || r < L || R < l) return ii(0,0);
	if (L <= l && r <= R) return t[k];
	int mid = (l+r)/2;
	return combine(get(k*2,l,mid,L,R), get(k*2+1,mid+1,r,L,R));
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[i]);

	build(1,1,n);

	scanf("%d\n", &q);
	while (q--) {
		char c;
		int x, y;
		scanf("%c%d%d\n", &c,&x,&y);
		if (c == 'U') upd(1,1,n,x,y);
		else {
			ii i = get(1,1,n,x,y);
			ii j = get(1,1,n,x,i.X-1);
			ii k = get(1,1,n,i.X+1,y);
			printf("%d\n", i.Y + max(j.Y, k.Y));
		}
	}

	return 0;
}
