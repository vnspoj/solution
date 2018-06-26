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

const int N = 300000;
const int m = 66000;
int T, n, k, a[N], t[m+1];
int mul, add, ord;
ll ans;

int get(int x) {
	int ans = 0;
	for (; x > 0; x -= x&-x) ans += t[x];
	return ans;
}

void upd(int x, int v) {
	for (; x <= m; x += x&-x) t[x] += v;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);

	FOR(test,1,T) {

		scanf("%d %d %d %d %d", &a[1], &mul, &add, &n, &k);
		FOR(i,2,n) a[i] = ((ll) a[i-1] * mul + add) % 65536;
		FOR(i,1,n) a[i]++;
		ord = (k+1)/2;

		ans = 0ll;
		FOR(i,1,m) t[i] = 0;
		FOR(i,1,k-1) upd(a[i], 1);

		FOR(i,k,n) {
			upd(a[i], 1);
			int L = 1, R = m, x = 0;
			while (L <= R) {
				int mid = (L+R)/2;
				if (ord <= get(mid)) {
					x = mid;
					R = mid-1;
				} else
					L = mid+1;
			}
			ans += (ll) x;
			upd(a[i-k+1], -1);
		}

		printf("Case #%d: %lld\n", test, ans - (n-k+1));
	}


	return 0;
}
