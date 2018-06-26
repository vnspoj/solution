#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct data {
	int x, l, r, type;
};

struct seg {
	int cnt, len;
};

const int N = 30010;
int n, m, k;
ll ans;
data a[N];
seg t[4*N];

bool cmp(data u, data v) {
	return (u.x < v.x || (u.x == v.x && u.type < v.type));
}

void upd(int k, int l, int r, int L, int R, int type) {
	if (L > R || r < L || R < l) return ;
	if (L <= l && r <= R) {
		t[k].cnt += type;
		if (type == 1) t[k].len = r-l+1;
		else if (t[k].cnt == 0)
			if (l < r)
				t[k].len = t[k<<1].len + t[(k<<1)+1].len;
			else
				t[k].len = 0;
		return ;
	}
	int mid = (l+r)>>1;
	upd(k<<1, l, mid, L, R, type);
	upd((k<<1)+1, mid+1, r, L, R, type);
	if (t[k].cnt == 0 && l < r)
		t[k].len = t[k<<1].len + t[(k<<1)+1].len;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
		a[++m] = {x1, y1+1, y2, 1};
		a[++m] = {x2, y1+1, y2, -1};
		k = max(k, y2);
	}

	sort(a+1,a+m+1,cmp);

	FOR(i,1,m) {
		ans += (ll)t[1].len * (ll)(a[i].x - a[i-1].x);
		upd(1, 1, k, a[i].l, a[i].r, a[i].type);
	}

	printf("%lld\n", ans);

	return 0;
}