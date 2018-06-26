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

const int N = 5010;
int T, n, s[N];
ii a[N];

bool cmp(ii u, ii v) {
	return u.X < v.X || (u.X == v.X && u.Y < v.Y);
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		FOR(i,1,n) scanf("%d%d", &a[i].X, &a[i].Y);
		sort(a+1, a+n+1, cmp);
		int k = 1;
		s[1] = a[1].Y;
		FOR(i,2,n) {
			int j = k;
			while (j > 0 && s[j] <= a[i].Y) j--;
			if (j == k) s[++k] = a[i].Y;
			s[j+1] = max(s[j+1], a[i].Y);
		}
		printf("%d\n", k);
	}


	return 0;
}
