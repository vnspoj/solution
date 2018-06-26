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

int n, s, a[505], sum;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&s);
	sum = n*(n+1)/2;
	FOD(i,n,1) {
		if (sum-2*i >= s) {
			a[i] = 1;
			sum -= 2*i;
		}
	}
	if (sum == s) {
		if (a[1]) {
			FOR(i,4,n) {
				if (a[1] == 0) break;
				if (a[i])
					FOR(j,2,i/2)
					if (a[j] == 0 && a[i+1-j] == 0) {
						a[j] = a[i+1-j] = 1;
						a[1] = a[i] = 0;
						break;
					}
			}
			if (a[1]) {
				puts("Impossible");
				return 0;
			}
		}
		printf("1");
		FOR(i,2,n)
		printf("%c%d", (a[i] == 1) ? '-' : '+', i);
	} else puts("Impossible");

	return 0;
}
