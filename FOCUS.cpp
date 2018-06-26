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

struct query {
	int t, k, a, b;
};

const int N = 1000000;
int n, m, a[N], t[N];
query q[N];

int get(int x) {
	int ans = 0;
	for (x; x > 0; x -= x&-x) ans += t[x];
	return ans;
}

void upd(int x, int v) {
	for (x; x <= m; x += x&-x) t[x] += v;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	FOR(i,1,n) {
		char c;
		scanf("%c", &c);
		if (c == '?') {
			scanf("%d%d%d\n", &q[i].k, &q[i].a, &q[i].b);
			a[++m] = q[i].a;
			a[++m] = q[i].a-1;
			a[++m] = q[i].b;
			a[++m] = q[i].b-1;
		} else {
			scanf("%d\n", &q[i].k);
			a[++m] = q[i].k;
			a[++m] = q[i].k-1;
			q[i].t = c == '+' ? 1 : -1;
		}
	}

	sort(a+1, a+m+1);
	m = unique(a+1, a+m+1)-a-1;

	FOR(i,1,n) {
		if (q[i].t == 0) {
			int L = lower_bound(a+1, a+m+1, q[i].a-1)-a, l = get(L);
			int R = lower_bound(a+1, a+m+1, q[i].b)-a, r = get(R);
			if (r-l < q[i].k) {
				puts("0");
				continue;
			}
			int x = 0;
			while (L <= R) {
				int mid = (L+R)/2;
				if (q[i].k <= get(mid)-l) {
					x = mid;
					R = mid-1;
				} else
					L = mid+1;
			}
			printf("%d\n", a[x]);
		} else {
			int x = lower_bound(a+1, a+m+1, q[i].k)-a;
			upd(x, q[i].t);
		}
	}

	return 0;
}
