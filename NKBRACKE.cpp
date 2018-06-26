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
int n, m, tp, L, R, p;
char a[N], ch;
ii t[4*N];

ii combine(ii L, ii R) {
	ii ans;
	int t = min(L.X, R.Y);
	ans.X = L.X - t + R.X;
	ans.Y = R.Y - t + L.Y;
	return ans;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k] = a[l] == '(' ? ii(1,0) : ii(0,1);
		return ;
	}
	int mid = (l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k] = combine(t[k*2], t[k*2+1]);
}

void upd(int k, int l, int r, int p, char c) {
	if (r < p || p < l) return ;
	if (l == p && r == p) {
		t[k] = c == '(' ? ii(1,0) : ii(0,1);
		return ;
	}
	int mid = (l+r)/2;
	upd(k*2,l,mid,p,c);
	upd(k*2+1,mid+1,r,p,c);
	t[k] = combine(t[k*2], t[k*2+1]);
}

ii get(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return ii(0,0);
	if (L <= l && r <= R) return t[k];
	int mid = (l+r)/2;
	return combine(get(k*2,l,mid,L,R), get(k*2+1,mid+1,r,L,R));
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&m);
	scanf("%s\n", a+1);
	build(1,1,n);

	while (m--) {
		scanf("%d", &tp);
		if (tp == 0) {
			scanf("%d %c", &p, &ch);
			upd(1,1,n,p,ch);
		} else {
			scanf("%d %d", &L, &R);
			ii t = get(1,1,n,L,R);
			if (t.X == 0 && t.Y == 0)
				printf("1");
			else printf("0");
		}
	}

	return 0;
}
