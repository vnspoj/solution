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

int t, n, x, z, cnt;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &t);
	while (t--) {
		z = 0;
		cnt = 0;
		scanf("%d", &n);
		for (int i=1; i<=n; i++) {
			scanf("%d", &x);
			if (x == 1) cnt++;
			z = z ^ x;
		}
		if (cnt == n) {
			if (n%2 == 0)
				printf("1\n");
			else
				printf("-1\n");
		} else {
			if (z > 0)
				printf("1\n");
			else
				printf("-1\n");
		}
	}


	return 0;
}
