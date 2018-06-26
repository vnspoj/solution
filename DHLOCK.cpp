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


const int N = 305;
const ll inf = 1e18;
int n, k, a[N], b[N];

#define pos(x) (x - shift_left + n - 1) % n + 1
#define dis(x,y) x <= y ? y - x : k - x + y + 1
#define add(x,d) (x + d) % (k + 1)



int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> k;
	FOR(i,1,n) scanf("%d", &a[i]);
	FOR(i,1,n) scanf("%d", &b[i]);

	ll ans = 0ll;
	FOR(i,1,n) ans += dis(a[i], b[i]);

	FOR(shift_left,0,n-1) {
		FOR(p,1,n) {
			int del = dis(a[pos(p)], b[p]);
			ll sum = (ll) shift_left + del;
			FOR(i,1,n)
			sum += (ll) dis(add(a[pos(i)], del), b[i]);
			ans = min(ans, sum);
		}
	}

	printf("%lld\n", ans);

	return 0;
}
