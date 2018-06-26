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

const int N = 500;
int c, n, ans, a[N], s[N];
int b[6], dd[6], deg[6];
ii x[N];

void solve() {
	FOR(i,1,c) deg[b[i]] = i;
	FOR(i,1,n) a[i] = deg[x[i].X] * 1000 + x[i].Y;
	int k = 1;
	s[1] = a[1];
	FOR(i,2,n) {
		int j = k;
		while (j > 0 && a[i] <= s[j]) j--;
		if (j == k) s[++k] = a[i];
		s[j+1] = min(s[j+1], a[i]);
	}
	ans = min(ans, n-k);
}

void dq(int k) {
	if (k == c+1) solve();
	else FOR(i,1,c)
		if (!dd[i]) {
			dd[i] = 1;
			b[k] = i;
			dq(k+1);
			dd[i] = 0;
		}
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &c,&n);
	n *= c;
	FOR(i,1,n) scanf("%d%d", &x[i].X, &x[i].Y);
	ans = n;
	dq(1);
	printf("%d\n", ans);

	return 0;
}
