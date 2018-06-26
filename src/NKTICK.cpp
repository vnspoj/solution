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

const int N = 65000;
const int inf = N * 30000;
int n, t[N], r[N], F[N][2];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &t[i]);
	FOR(i,1,n-1) scanf("%d", &r[i]);
	F[1][0] = inf;
	F[1][1] = t[1];
	F[2][0] = r[1];
	F[2][1] = t[1] + t[2];
	FOR(i,3,n) {
		F[i][0] = F[i-1][1] - t[i-1] + r[i-1];
		F[i][1] = min(F[i-1][0], F[i-1][1]) + t[i];
	}
	printf("%d\n", min(F[n][0], F[n][1]));

	return 0;
}
