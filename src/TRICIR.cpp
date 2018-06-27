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


const int N = 1e6+1;
int n, p, dd[N], pa[N];
ll  a, b, c, res, sum;
char ch[10];

int findSet(int u) {
	if (u == pa[u]) return u;
	return pa[u] = findSet(pa[u]);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	for (;;) {
		gets(ch);
		if (ch[1] == 'E') return 0;
		scanf("%d%d%lld%lld%lld\n", &n,&p,&a,&b,&c);
		if (n%2) {
			puts("0");
			continue;
		}
		res = sum = 0ll;
		if (n <= p) {
			FOR(i,0,n-1) dd[i] = 1;
		} else {
			FOR(i,0,n-1) dd[i] = 0, pa[i] = i;
			for (ll i=0; i<p; i++) {
				ll f = (a*i*i+b*i+c)%n;
				int j = findSet((int) f);
				dd[j] = 1;
				pa[j] = (j == n-1 ? 0 : j+1);
			}
		}
		FOR(i,0,n-1) sum += dd[i];
		FOR(i,0,n/2-1) {
			int j = i+n/2;
			if (dd[i] && dd[j]) res += sum-2;
		}
		printf("%lld\n", res);
	}


	return 0;
}
