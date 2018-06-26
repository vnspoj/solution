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

const int inf = 2*1e9+7;
int n, a1 = inf, a2 = -inf, b1 = -inf, b2 = inf;
ll ans;

void solve() {
	int x, y, A1 = -inf, A2 = inf, B1 = inf, B2 = -inf;
	FOR(i,1,4) {
		scanf("%d%d", &x,&y);
		A1 = max(A1, y-x);
		A2 = min(A2, y-x);
		B1 = min(B1, y+x);
		B2 = max(B2, y+x);
	}
	a1 = min(a1, A1);
	a2 = max(a2, A2);
	b1 = max(b1, B1);
	b2 = min(b2, B2);
}

bool trai(int a, int b) {
	return abs(a-b)%2;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) solve();
	if (a1 <= a2 || b2 <= b1) {
		puts("0");
		return 0;
	}
	int a = a1 - a2 - 1;
	int b = b2 - b1 - 1;
	int al = max(a/2, a-a/2);
	int an = min(a/2, a-a/2);
	int bl = max(b/2, b-b/2);
	int bn = min(b/2, b-b/2);

	if (trai(a1, a2) || trai(b1, b2))
		ans = (ll) al * bl + (ll) an * bn;
	else if (trai(a1, b1))
		ans = (ll) an * bl + (ll) al * bn;
	else
		ans = (ll) al * bl + (ll) an * bn;

	printf("%lld\n", ans);

	return 0;
}
