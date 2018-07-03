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

int res;

void solve(ll x, ll y) {
	res = 1-res;
	if (x >= 2*y) return ;
	x -= y;
	if (x < y) swap(x,y);
	solve(x,y);
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	ll x, y;
	while (scanf("%lld", &x) == 1) {
		scanf("%lld", &y);
		if (x == 0 && y == 0) return 0;
		res = 0;
		if (x < y) swap(x,y);
		solve(x,y);
		if (res == 1) printf("T\n");
		else printf("S\n");
	}

	return 0;
}
