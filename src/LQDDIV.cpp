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

const int   N = 500000;
int         n;
ll          sum, a[N], x[N], m, s, res, cnt;

void dfs1(int i) {
	if (i == n/2+1) {
		x[++m] = s;
		return ;
	}
	dfs1(i+1);
	s += a[i];
	dfs1(i+1);
	s -= a[i];
}

void solve() {
	ll t = sum - 2*s, good = sum+5, cntt = 0;

	ll l = 1, r = m, mid, pos = 0;
	while (l <= r) {
		mid = (l+r)/2;
		if (2*x[mid] <= t) {
			pos = mid;
			l = mid+1;
		} else
			r = mid-1;
	}

	if (pos > 0)
		good = abs(t-2*x[pos]);
	if (abs(t-2*x[pos+1]) < good)
		good = abs(t-2*x[++pos]);

	if (good == sum+5 or (res < sum+5 and good > res)) return ;

	ll L = pos-1, R = pos+1;
	cntt = 1;
	while (L > 0 and good == abs(t-2*x[L])) {
		L--;
		cntt++;
	}
	while (R <= m and good == abs(t-2*x[R])) {
		R++;
		cntt++;
	}

	if (res > good) {
		res = good;
		cnt = cntt;
	} else
		cnt += cntt;
}

void dfs2(int i) {
	if (i == n+1) {
		solve();
		return ;
	}
	dfs2(i+1);
	s += a[i];
	dfs2(i+1);
	s -= a[i];
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		sum += ll(a[i]);
	}
	res = sum+5;

	dfs1(1);
	sort(x+1,x+m+1);
	s = 0;
	dfs2(n/2+1);

	printf("%lld %lld", res, cnt/2);

	return 0;
}
