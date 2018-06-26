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

const int N = 1500000;
const ll inf = 70000ll*(ll)N;
int n, a[N];
ll S, sum, ans = -inf;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	FOR(i,1,n) scanf("%d", &a[i]), S += (ll)a[i];

	int i = 1;

	FOR(j,1,n) {
		sum += (ll)a[j];
		ans = max(ans, j-i+1 == n ? ans : sum);
		if (sum < 0) sum = 0ll, i = j+1;
	}

	sum = 0ll;
	i = 1;
	FOR(j,1,n) {
		sum += (ll)a[j];
		ans = max(ans, j-i+1 == n ? ans : S-sum);
		if (sum > 0) sum = 0ll, i = j+1;
	}

	printf("%lld\n", ans);


	return 0;
}
