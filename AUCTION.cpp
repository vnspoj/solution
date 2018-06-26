#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e6;
int n, m, a[N+1], x, ans;
ll sum;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,m) scanf("%d", &x), a[x]++;

	FOD(i,N-1,1) a[i] += a[i+1];

	FOR(i,1,N) {
		ll tmp = i*(min(a[i],n));
		if (tmp > sum) {
			sum = tmp;
			ans = i;
		}
	}

	printf("%d %lld\n", ans, sum);

	return 0;
}
