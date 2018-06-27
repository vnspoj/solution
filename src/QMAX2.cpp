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
int n, m, lazy[4*N], t[4*N];
int tp, L, R, val;

void lazy_upd(int k, int l, int r) {
	if (lazy[k] == 0) return ;
	t[k] += lazy[k];
	if (l < r) {
		lazy[k*2] += lazy[k];
		lazy[k*2+1] += lazy[k];
	}
	lazy[k] = 0;
}

void upd(int k, int l, int r, int L, int R, int val) {
	lazy_upd(k,l,r);
	if (r < L || R < l) return ;
	if (L <= l && r <= R) {
		lazy[k] = val;
		lazy_upd(k,l,r);
		return ;
	}
	int mid = (l+r)/2;
	upd(k*2,l,mid,L,R,val);
	upd(k*2+1,mid+1,r,L,R,val);
	t[k] = max(t[k*2], t[k*2+1]);
}

int get(int k, int l, int r, int L, int R) {
	lazy_upd(k,l,r);
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return t[k];
	int mid = (l+r)/2;
	return max(get(k*2,l,mid,L,R), get(k*2+1,mid+1,r,L,R));
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> m;
	while (m--) {
		scanf("%d", &tp);
		if (tp == 0) {
			scanf("%d%d%d", &L,&R,&val);
			upd(1,1,n,L,R,val);
		} else {
			scanf("%d%d", &L,&R);
			printf("%d\n", get(1,1,n,L,R));
		}
	}
    
	return 0;
}
