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

const int   N = 200000;
struct data {
	int x,y;
} a[N];
int n;
ll  res, cnt[N];

bool cmp(const data u, const data v) {
	return ((u.x < v.x) or (u.x == v.x and u.y < v.y));
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		cnt[a[i].y]++;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n;) {
		int j = i;
		while (j < n and a[j+1].x == a[i].x) j++;
		for (int k=i; k<=j; k++)
			res += ll(j-i)*(cnt[a[k].y]-1);
		i = j+1;
	}
	printf("%lld", res);

	return 0;
}
