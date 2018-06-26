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


const ll    oo = 1000000000000000001ll;
ll          p[20] = {0,2,3,5,7,11,13,17,19,23,29};
ll          n, res = oo;

void solve(int i, ll ans, int cnt) {
	if (cnt > n)  return ;
	if (cnt == n) res = min(res, ans);
	for (int j=1;; j++) {
		if (ans*p[i] > res) break;
		ans *= p[i];
		if (ans < 0) break;
		solve(i+1, ans, cnt*(j+1));
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	solve(1,1,1);
	printf("%lld", res);

	return 0;
}
