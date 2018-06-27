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

int     n;
ll      res;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	if (n%2 == 0) {
		for (int x1=1; 2*x1<n; x1++)
			for (int x3=n/2+1; x3<n; x3++) {
				int l = max(2*x1,2*x3-n)/2;
				int r = min(2*x3,2*x1+n)/2;
				res += ll(r-l-1);
			}
	} else {
		for (int x1=1; 2*x1<n; x1++)
			for (int x3=n/2+1; x3<n; x3++) {
				int l = max(2*x1,2*x3-n-1)/2;
				int r = min(2*x3,2*x1+n+1)/2;
				res += ll(r-l-1);
			}
	}
	cout << res ;

	return 0;
}
