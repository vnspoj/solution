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

int t, ca, cb, ma, mb;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &ca, &cb, &ma, &mb);
		if (ma == 0) ca = 0;
		if (mb == 0) cb = 0;
		if (ca > cb) swap(ca, cb), swap(ma, mb);
		printf("%lld\n", ca + min((ll)cb, (ll)mb * (ca+1)));
	}

	return 0;
}
