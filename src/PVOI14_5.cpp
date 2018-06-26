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

const int inf = 1e9;
const int N = 10000;
int n, Ans, Pos;
int a[N+1], dd[N+1], cnt[N+1][15];
vector<int> p;

void sang() {
	for (int i = 2; i*i <= N; i++)
		if (! dd[i])
			for (int j = i*i; j <= N; j += i)
				dd[j] = 1;
	FOR(i,2,N) if (!dd[i]) p.ep(i);
}

void solve(int x) {
	if (a[x] == 0) return ;
	int sl = a[x];
	for (int i = 2; i * i <= x; i++)
		if (x%i == 0) {
			int j = 0;
			while (x%i == 0) ++j, x /= i;
			cnt[i][j] += sl;
			cnt[i][0] += sl;
		}
	if (x > 1)
		cnt[x][1] += sl, cnt[x][0] += sl;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	sang();
	FOR(i,2,N) solve(i);
	FOR(i,2,N) cnt[i][0] = n - cnt[i][0];

	Pos = 1;
	for (auto x : p) {
		if (cnt[x][0] == n) continue;
		int k = 0, dem = 0;
		FOR(i,0,13) {
			dem += cnt[x][i];
			if (dem >= (n+1)/2) {
				k = i;
				break;
			}
		}
		FOR(i,0,13) Ans += cnt[x][i] * abs(k-i);
		FOR(i,1,k) Pos *= x;
	}

	printf("%d %d", Ans, Pos);


	return 0;
}
