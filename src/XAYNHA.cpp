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

int T;
ll  n, x, k, h;

void solve(ll t) {
	if (t < 0) return ;
	ll p = t*(t+1)/2;
	p *= p;
	if (t > h and abs(n-p) <= abs(k)) {
		k = n-p;
		h = t;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		cin >> n;
		if (n == 0) {
			printf("0 1 1\n");
			continue;
		}
		k = n;
		h = 0;
		x = sqrt(2*sqrt(n));
		for (ll t=x-3; t<=x+3; t++) solve(t);
		if (k == 0) printf("1 %lld\n", h);
		else printf("0 %lld %lld\n", -k, h);
	}

	return 0;
}
