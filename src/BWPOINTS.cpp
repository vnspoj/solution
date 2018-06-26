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

const int N = 200005;
int n, m, ans, Now;
ii a[N];

bool cmp(ii u, ii v) {
	return u.X < v.X;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[++m].X), a[i].Y = 0;
	FOR(i,1,n) scanf("%d", &a[++m].X), a[i].Y = 1;
	sort(a+1, a+m+1, cmp);
	Now = a[1].Y;
	FOR(i,2,m)
	if (a[i].Y + Now == 1) ans++, Now = -1;
	else Now = a[i].Y;
	printf("%d\n", ans);

	return 0;
}
