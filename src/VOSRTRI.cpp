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
	int x,y;
};

const int N = 1e5+5;
int n, cx[N], cy[N];
data a[N];
ll res;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		cx[a[i].x]++; cy[a[i].y]++;
	}
	for (int i=1; i<=n; i++) {
        res += (cx[a[i].x]-1) * 1ll * (cy[a[i].y]-1);
	}
	printf("%lld", res);

	return 0;
}
