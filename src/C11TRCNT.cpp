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

const int N = 222;
int n, F[N], ans, id;
ii a[N];

bool check(ii A, ii B, ii C) {
	int xab = B.X - A.X, yab = B.Y - A.Y;
	int xac = C.X - A.X, yac = C.Y - A.Y;
	return (ll)xab * yac != (ll)xac * yab;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d%d", &a[i].X, &a[i].Y);
	FOR(i,1,n) FOR(j,i+1,n) FOR(k,j+1,n)
	if (check(a[i],a[j],a[k])) {
		ans++;
		F[i]++;
		F[j]++;
		F[k]++;
	}
	id = 1;
	FOR(i,2,n) if (F[i] < F[id]) id = i;
	printf("%d %d\n", ans, id);

	return 0;
}
