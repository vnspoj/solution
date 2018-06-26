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

int n;
ll F[35];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	F[0] = 1ll;
	for (int i = 2; i <= 30; i += 2) {
		F[i] = 3 * F[i-2];
		for (int j = 0; j <= i - 4; j += 2)
			F[i] += 2 * F[j];
	}
	while (scanf("%d", &n) != EOF) {
		if (n == -1) break;
		printf("%lld\n", F[n]);
	}

	return 0;
}
