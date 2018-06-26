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

const int N = 30000;
const int inf = 1e9;
int n, a[N], F[N][2];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n-1) scanf("%d", &a[i]);
	F[2][1] = a[1];
	F[2][0] = inf;
	FOR(i,3,n) {
		F[i][0] = F[i-1][1];
		F[i][1] = min(F[i-1][0], F[i-1][1]) + a[i-1];
	}

	printf("%d\n", F[n][1]);

	return 0;
}
