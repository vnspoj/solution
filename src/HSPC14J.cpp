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

int     n, k, a[100000], top, res ;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	while (scanf("%d",&n) == 1) {
		scanf("%d",&k);
		for (int i=1; i<=n+1; i++) a[i] = 1;
		a[1] = a[0] = 0;
		top = 0;
		res = 0;
		int i = 2;
		while (i <= n) {
			top++;
			if (top == k) {
				res = i;
				break;
			}
			for (int j=i+i; j<=n; j+=i) {
				if (a[j] == 1) {
					a[j] = 0;
					top++;
					if (top == k) {
						res = j;
						break;
					}
				}
			}
			if (res > 0) break;
			i++;
			while (a[i] == 0) i++;
		}
		printf("%d\n",res);
	}

	return 0;
}
