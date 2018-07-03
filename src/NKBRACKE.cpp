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
	int open, close;
};

const int N = 1e5+5;
int n, m;
char c[N];
data t[N<<2];

data combine(data l, data r) {
	data res;
	int loss = min(l.open, r.close);
	res.open = l.open - loss + r.open;
	res.close = r.close - loss + l.close;
	return res;
}

void build(int k, int l, int r) {
	if (l == r) {
		if (c[l-1] == '(') t[k] = {1, 0};
		else t[k] = {0, 1};
		return;
	}
	int m = (l+r)>>1;
	build(k<<1, l, m);
	build(k*2+1, m+1, r);
	t[k] = combine(t[k<<1], t[k*2+1]);
}

void update(int k, int l, int r, int i, char c) {
	if (r < i || i < l) return;
	if (l == i && r == i) {
		if (c == '(') t[k] = {1, 0};
		else t[k] = {0, 1};
		return;
	}
	int m = (l+r)>>1;
	update(k<<1, l, m, i, c);
	update(k*2+1, m+1, r, i, c);
	t[k] = combine(t[k<<1], t[k*2+1]);
}

data get(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return { 0, 0 };
	if (L <= l && r <= R) return t[k];
	int m = (l+r)>>1;
	return combine(get(k<<1, l, m, L, R), get(k*2+1, m+1, r, L, R));
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n%s", &n, &m, &c);

	build(1,1,n);

	while (m--) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int i;
			char ch;
			scanf("%d %c", &i, &ch);
			update(1,1,n,i,ch);
		} else {
			int L, R;
			scanf("%d%d", &L, &R);
			data res = get(1,1,n,L,R);
			printf("%d", res.open == 0 && res.close == 0 ? 1 : 0);
		}
	}

	return 0;
}
