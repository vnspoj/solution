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

const int N = 15000;
int n, F[N];
ii a[N];

bool cmp(ii u, ii v) {
	return u.Y < v.Y;
}

int search(int L, int R, int x) {
	int ans = 0;
	while (L <= R) {
		int mid = (L+R)/2;
		if (a[mid].Y <= x) {
			ans = mid;
			L = mid+1;
		} else
			R = mid-1;
	}
	return ans;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d%d", &a[i].X, &a[i].Y);
	sort(a+1, a+n+1, cmp);

	F[1] = a[1].Y - a[1].X;
	FOR(i,2,n) {
		int k = search(1,i-1,a[i].X);
		F[i] = max(F[i-1], F[k] + a[i].Y - a[i].X);
	}
	printf("%d\n", F[n]);

	return 0;
}
