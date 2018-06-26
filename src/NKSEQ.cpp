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

const int N = 100050;
int n, a[N], L[N], R[N], F[N], ans;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[i]);

	L[1] = L[0] = a[1];
	FOR(i,2,n)
	L[i] = min(L[i-1], L[0] + a[i]), L[0] += a[i];

	R[n] = a[n];
	FOD(i,n-1,1)
	R[i] = min(a[i], R[i+1] + a[i]);

	F[n] = a[n];
	FOD(i,n-1,1) F[i] = F[i+1] + a[i];

	FOR(i,1,n)
	if (R[i] > 0 && L[i] + F[i] > 0) ans++;

	printf("%d\n", ans);


	return 0;
}
