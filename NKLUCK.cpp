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

const int   N = 1e6+1e3;
int         n, X, x[N], a[N], f[N], b[N], t[2][N];
ll          res;

void update(int x, int w) {
	for (x; x<=a[0]; x+=x&-x) t[w][x]++;
}

ll get(int x, int w) {
	ll ans = 0;
	for (x; x>0; x-=x&-x) ans += t[w][x];
	return ans;
}

ll solve(int k, int w) {
	ll ans = 0;
	f[0] = a[0] = b[0] = 0;

	for (int i=1; i<=n; i++) {
		f[i] = f[i-1] + (x[i] >= k);
		b[++b[0]] = 2*f[i]-i-1;
		b[++b[0]] = 2*f[i-1]-i;
	}

	sort(b+1,b+b[0]+1);
	b[++b[0]] = N;
	for (int i=1; i<b[0]; i++)
		if (b[i] < b[i+1]) a[++a[0]] = b[i];

	for (int j=1; j<=n; j++) {
		int x;
		x = lower_bound(a+1,a+a[0]+1,2*f[j-1]-j)-a;
		update(x,w);
		x = lower_bound(a+1,a+a[0]+1,2*f[j]-j-1)-a;
		ans += get(x,w);
	}

	return ans;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n, &X);
	for (int i=1; i<=n; i++) scanf("%d", &x[i]);
	res = solve(X,0) - solve(X+1,1);
	printf("%.6lf", (double)res/((double)n*(n+1)/2));

	return 0;
}
