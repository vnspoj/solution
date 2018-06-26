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


const int N = 1000000;
const int inf = 1e9;
int n, s, a[150], F[N+1], ans;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n, &s);
	FOR(i,1,n) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	FOR(i,1,N/n) {
		F[i] = inf;
		FOR(j,1,n)
		if (a[j] <= i)
			F[i] = min(F[i], 1 + F[i-a[j]]);
		else break;
	}

	if (s <= N/n) {
		printf("%d\n", F[s]);
		return 0;
	}

	ans = inf;

	int time = 0;
	for (int cnt = s / a[n]; cnt > 0; cnt--) {
		int t = s - a[n] * cnt;
		if (t > N/n || time > N) break;
		ans = min(ans, cnt + F[t]);
		time++;
	}

	printf("%d\n", ans);

	return 0;
}
