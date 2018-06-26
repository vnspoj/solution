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

const int N = 10005, K = 105;
const ll inf = 1e15;
int n, k, a[N], f[N], pos[N], cnt[N];
ll  F[N], g[N][K*2], sum[N];

void updCnt(int, int);
int getCnt(int);
void updSum(int, ll);
ll getSum(int);

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&k);
	FOR(i,1,n) scanf("%d", &a[i]), f[++f[0]] = a[i];
	sort(f+1,f+f[0]+1);
	f[0] = unique(f+1,f+f[0]+1)-f-1;
	FOR(i,1,n) pos[i] = lower_bound(f+1,f+f[0]+1,a[i])-f;

	FOR(j,k,k*2) {
		ll Sum = 0ll;
		FOR(i,1,f[0]) cnt[i] = sum[i] = 0;

		FOR(i,1,j-1)
		updCnt(pos[i], 1), updSum(pos[i], a[i]), Sum += a[i];

		int order = (j+1)/2;
		FOR(i,j,n) {
			updCnt(pos[i], 1);
			updSum(pos[i], a[i]);
			Sum += a[i];

			int L = 1, R = f[0], x = 0;
			while (L <= R) {
				int mid = (L+R)/2;
				if (order <= getCnt(mid)) {
					x = mid;
					R = mid-1;
				} else
					L = mid+1;
			}

			ll cntN = getCnt(x-1), cntL = j - getCnt(x);
			ll sumN = getSum(x-1), sumL = Sum - getSum(x);
			g[i][j] = (ll) f[x] * cntN - sumN + sumL - (ll) f[x] * cntL;

			int p = i-j+1;
			updCnt(pos[p], -1);
			updSum(pos[p], -a[p]);
			Sum -= a[p];
		}
	}

	FOR(i,1,n) F[i] = inf;
	FOR(i,k,n)
	FOR(j,k,min(i,2*k))
	F[i] = min(F[i], F[i-j] + g[i][j]);

	printf("%lld\n", F[n]);

	return 0;
}


void updCnt(int x, int v) {
	for (; x<=f[0]; x+=x&-x) cnt[x] += v;
}

int getCnt(int x) {
	int ans = 0;
	for (; x>0; x-=x&-x) ans += cnt[x];
	return ans;
}

void updSum(int x, ll v) {
	for (; x<=f[0]; x+=x&-x) sum[x] += v;
}

ll getSum(int x) {
	ll ans = 0ll;
	for (; x>0; x-=x&-x) ans += sum[x];
	return ans;
}
