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

const int N = 1e5;
int n, m, a[N], ans;
ii F[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,n) scanf("%d", &a[i]);
	FOR(i,1,n)
	FOR(j,i+1,n)
	F[a[i]+a[j]] = {i,j};
	m = min(m,30000);
	FOR(i,1,n) {
		FOD(j,m-a[i],0)
		if (F[j] != ii(0,0) && F[j].X != i && F[j].Y != i) {
			ans = max(ans, a[i]+j);
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}
