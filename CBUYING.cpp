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

typedef pair<ll,ll> pll;

const int N = 100005;
int n;
ll b, ans;
pll a[N];

bool cmp(pll u, pll v) {
	return u.X < v.X;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%lld\n", &n, &b);
	FOR(i,1,n) scanf("%lld%lld", &a[i].X, &a[i].Y);
	sort(a+1, a+n+1, cmp);
	FOR(i,1,n) {
		ll sl = b / a[i].X;
		if (sl < a[i].Y) {
			ans += sl;
			break;
		} else {
			ans += a[i].Y;
			b -= a[i].X * a[i].Y;
		}
	}
	printf("%lld\n", ans);

	return 0;
}
