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
	int val, time, id;
};

const int N = 10010;
int n;
data a[N];
ll ans, sum;

bool cmp(data u, data v) {
	return (ll)u.val * v.time > (ll)u.time * v.val;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[i].val), sum += (ll)a[i].val;
	FOR(i,1,n) scanf("%d", &a[i].time), a[i].id = i;
	sort(a+1, a+n+1, cmp);
	FOR(i,1,n) {
		ans += sum * a[i].time;
		sum -= a[i].val;
	}
	printf("%lld\n", ans);
	FOR(i,1,n) printf("%d ", a[i].id);

	return 0;
}
