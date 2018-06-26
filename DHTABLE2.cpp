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


int len;
ll n;
deque<int> ans;

void solve(int dd) {
	ll l = 1, r;
	FOR(i,1,dd-1) l *= 10ll;
	r = l*10ll - 1ll;
	if (n <= (ll)dd*(r-l+1)) {
		ll stt = n/dd + (n%dd > 0);
		ll so = l + stt - 1;
		ll vt = (n+dd-1)%dd + 1;
		ll p = so;
		FOR(i,1,dd-vt) p /= 10;
		while (p > 0 && ans.size() < len) {
			ans.push_front(p%10);
			p /= 10;
		}
		while (ans.size() < len) {
			p = --so;
			if (p <= 0)
				while (ans.size() < len) ans.push_front(-1);
			while (ans.size() < len && p > 0) {
				ans.push_front(p%10);
				p /= 10;
			}
		}
		while (!ans.empty()) {
			if (ans.front() == -1) printf(" ");
			else printf("%d", ans.front());
			ans.pop_front();
		}
		exit(0);
	} else {
		n -= (ll)dd*(r-l+1);
		solve(dd+1);
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> len >> n;
	solve(1);

	return 0;
}
