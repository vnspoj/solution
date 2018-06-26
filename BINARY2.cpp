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

const int N = 1e6+6, mod = 1e9;
int n, k;
ll F[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d %d", &n, &k);
	F[0] = F[1] = 1ll % mod;
	FOR(i,2,k) F[i] = 2*F[i-1] % mod;
	FOR(i,k+1,n)
	F[i] = (2*F[i-1] % mod - F[i-k-1] + mod) % mod;
	printf("%lld\n", 2*F[n] % mod);

	return 0;
}
