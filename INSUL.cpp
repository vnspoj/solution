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

long     n,a[120000];
int64_t  res = 0;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%li",&n);
	for (long i=1; i<=n; i++) {
		scanf("%li",&a[i]);
		res += a[i];
	}
	sort(a+1,a+n+1);
	long tmp = 0;
	if (n % 2 == 0) {
		for (long i=1; i<=n/2; i++)
			tmp += a[i];
		res += (res - tmp) - tmp;
	} else {
		for (long i=1; i<=n/2; i++)
			tmp += a[i];
		long tmp2 = res - tmp - a[n/2+1];
		res += tmp2 - tmp;
	}
	printf("%I64d",res);

	return 0;
}
