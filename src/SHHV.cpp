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

const int N = 15;
int n, dd[N];
ll a[N], x, F[N];

void solve1() {
	ll ans = 1ll;
	FOR(i,1,n) {
		int cnt = 0;
		FOR(j,1,n) cnt += j < a[i] && !dd[j];
		ans += F[n-i] * cnt;
		dd[a[i]] = 1;
	}
	printf("%lld\n", ans);
}

void solve2() {
	FOR(i,1,n) dd[i] = a[i] = 0;
	x--;
	FOR(i,1,n) {
		int ord = 0, cnt = 0;
		while (x >= F[n-i]) {
			x -= F[n-i];
			ord++;
		}
		FOR(j,1,n) {
			if (!dd[j] && cnt == ord) {
				a[i] = j;
				dd[j] = 1;
				break;
			}
			if (!dd[j]) cnt++;
		}
	}
	FOR(i,1,n) printf("%d ", a[i]);
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	while (scanf("%lld", &x) == 1) a[++n] = x;
	n--;
	F[0] = 1ll;
	FOR(i,1,n) F[i] = F[i-1] * i;
	solve1();
	solve2();

	return 0;
}
