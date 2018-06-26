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

const int N = 150000;
int n, a[N], p, f[N], t[N], ans;

int get(int x) {
	int ans = n+1;
	for (x; x > 0; x -= x&-x) ans = min(ans, t[x]);
	return ans;
}

void upd(int x, int v) {
	for (x; x <= f[0]; x += x&-x) t[x] = min(t[x], v);
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n, &p);
	FOR(i,1,n) {
		scanf("%d", &a[i]);
		a[i] += a[i-1];
		f[++f[0]] = a[i];
		f[++f[0]] = a[i]-p;
	}
	f[++f[0]] = 0;
	f[++f[0]] = 0-p;
	sort(f+1, f+f[0]+1);
	f[0] = unique(f+1, f+f[0]+1)-f-1;
	FOR(i,1,f[0]) t[i] = n+1;
	ans = -1;
	FOR(j,1,n) {
		int x = lower_bound(f+1, f+f[0]+1, a[j-1])-f;
		upd(x,j);
		x = lower_bound(f+1, f+f[0]+1, a[j]-p)-f;
		int i = get(x);
		if (i == n+1) continue;
		ans = max(ans, j-i+1);
	}
	printf("%d\n", ans);

	return 0;
}
