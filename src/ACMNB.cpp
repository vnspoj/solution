#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 8*1e5+5;
int n, res;
ii a[N];

bool cmp(ii u, ii v) {
	return u.X-u.Y < v.X-v.Y;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n;
	n *= 2;
	FOR(i,1,n) scanf("%d%d", &a[i].X, &a[i].Y);

	sort(a+1,a+n+1,cmp);

	FOR(i,1,n/2) res += a[i].X;
	FOR(i,n/2+1,n) res += a[i].Y;

	printf("%d\n", res);

	return 0;
}
