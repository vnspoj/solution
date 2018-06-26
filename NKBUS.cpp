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

const int  maxn = 250000,z=0;
int        n,m,k,t,f[maxn],a[maxn],p,x,res;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d",&n,&m);

	// thoi gian xe den tram i
	f[1] = 0;
	// so luong nguoi
	p = 0;

	for (int i=1; i<=n; i++) {
		scanf("%d%d",&t,&k);

		// thoi gian den tram tiep tang len t
		f[i+1] = f[i] + t;

		for (long j=p+1; j<=p+k; j++) {
			scanf("%d",&x);
			// a[j] la thoi gian xe buyt cho thang j
			a[j] = max(z,x-f[i]);
		}

		// tang luong nguoi len k
		p += k;
	}

	sort(a+1,a+p+1);

	res = f[n+1]+a[m];

	printf("%d",res);

	return 0;
}
