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


struct data {
	int t;
	ll  d;
};

const int   N = 500000;
int         n, A, B, fa[N], fb[N];
ll          fd[N], res = LONG_LONG_MAX;
data        a[N];

bool cmp(const data u, const data v) {
	return (u.d < v.d);
}

int Search_a(int l, int r, int a) {
	int ans = -1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (fa[mid] <= a) {
			ans = mid;
			l = mid+1;
		} else
			r = mid-1;
	}
	return ans;
}

int Search_b(int l, int r, int b) {
	int ans = -1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (fb[mid] <= b) {
			ans = mid;
			l = mid+1;
		} else
			r = mid-1;
	}
	return ans;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d%d%d", &n,&A,&B);
	for (int i=1; i<=n; i++)
		scanf("%lld %d", &a[i].d,&a[i].t);

	sort(a+1,a+n+1,cmp);

	for (int i=1; i<=n; i++) {
		fd[i] = a[i].d;
		fa[i] = fa[i-1] + (a[i].t == 1);
		fb[i] = fb[i-1] + (a[i].t == 2);
	}

	for (int i=1; i<=n; i++) {
		if (fb[i] < B or fa[i] < A) continue;
		int ja = Search_a(0,i-2,fa[i]-A);
		int jb = Search_b(0,i-2,fb[i]-B);
		int j = min(ja,jb);
		if (j == -1) continue;
		res = min(res, fd[i]-fd[j+1]);
	}

	if (res == LONG_LONG_MAX) cout << -1;
	else cout << res;


	return 0;
}
