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

const int N = 150000;
const int mod = 14062008;
int n, k, a[N], F[N];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&k);
	FOR(i,1,k) scanf("%d", &a[0]), a[a[0]] = 1;
	F[1] = 1;
	FOR(i,2,n)
	if (a[i] == 0)
		F[i] = (F[i-1] + F[i-2]) % mod;
	printf("%d\n", F[n]);

	return 0;
}
