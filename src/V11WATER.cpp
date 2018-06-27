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

const int   maxn = 200000;
int         n,a[maxn],l[maxn],r[maxn];
long long   res = 0;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) l[i] = max(l[i-1],a[i-1]);
	for (int i=n; i>=1; i--) r[i] = max(r[i+1],a[i+1]);
	for (int i=1; i<=n; i++) res += max((min(l[i],r[i])-a[i]),0);
	printf("%lld",res);

	return 0;
}
