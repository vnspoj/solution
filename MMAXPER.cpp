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

const int N = 1000;
int n, a[N], b[N], F[N][2];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n;
	FOR(i,1,n) scanf("%d%d",a+i,b+i);

	F[1][0] = a[1];
	F[1][1] = b[1];
	FOR(i,2,n) {
		F[i][0] = max(F[i-1][0] + a[i] + abs(b[i]-b[i-1]), F[i-1][1] + a[i] + abs(b[i]-a[i-1]));
		F[i][1] = max(F[i-1][0] + b[i] + abs(a[i]-b[i-1]), F[i-1][1] + b[i] + abs(a[i]-a[i-1]));
	}

	printf("%d\n", max(F[n][0], F[n][1]));

	return 0;
}
