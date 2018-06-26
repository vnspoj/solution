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





int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	int T;
	cin >> T;
	while (T--) {
		priority_queue<ll> st;
		int n;
		scanf("%d", &n);
		FOR(i,1,n) {
			int x;
			scanf("%d", &x);
			st.push(-x);
		}
		ll ans = 0ll;
		FOR(i,1,n-1) {
			ll x = st.top();
			st.pop();
			ll y = st.top();
			st.pop();
			ans += x+y;
			st.push(x+y);
		}
		printf("%lld\n", -ans);
	}

	return 0;
}
