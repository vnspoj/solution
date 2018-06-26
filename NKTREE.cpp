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

int     a[55000],n,x,y,z;


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	while (scanf("%d",&x) == 1) {
		n++;
		a[n] = x;
	}
	for (int i=1; i<=n-2; i++) {
		x = a[i];
		y = a[i+1];
		z = a[i+2];
		if (y < x) {
			if (z < y) continue;
			if (z < x) continue;
			printf("NO");
			return 0;
		} else {
			if (y < z) continue;
			if (x < z) continue;
			printf("NO");
			return 0;
		}
	}
	printf("YES");

	return 0;
}
