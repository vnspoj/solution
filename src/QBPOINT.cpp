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


const int N = 2005;
int n, x[N], y[N];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n;
	FOR(i,1,n) scanf("%d%d", &x[i], &y[i]);

	ll ans = 0ll;
	FOR(i,1,n) {
		vector<double> st;
		int cnt = 0;
		FOR(j,1,n)
		if (x[j] != x[i])
			st.pb((double) (y[j]-y[i]) / (x[j]-x[i]));
		else
			cnt++;
		sort(st.begin(), st.end());
		ll res = (ll)(cnt-1) * (cnt-2);
		if (st.size()) {
			double cur = st[0];
			int p = 0;
			FOR(j,0,st.size()-1) {
				if (st[j] == cur) p++;
				else {
					res += p*(p-1);
					p = 1;
					cur = st[j];
				}
			}
			res += p * (p-1);
		}
		ans += res;
	}

	cout << ans/6;

	return 0;
}
