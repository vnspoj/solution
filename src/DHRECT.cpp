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


const int N = 3e5+5;
int T, n, a[N];


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		FOR(i,1,n) scanf("%d", &a[i]);
		sort(a+1,a+n+1);
		int x = -1;
		ll ans = -1;
		map<int,int> m;
		FOD(i,n,1) {
			m[a[i]]++;
			if (m[a[i]] == 2) {
				if (x == -1) x = a[i];
				else {
					ans = (ll) x * a[i];
					break;
				}
			} else if (m[a[i]] == 4) {
				ans = (ll) a[i] * a[i];
				break;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}
