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
	int a;
	int b;
};

const int   N = 150000, oo = 1000001;
int         n, res, s[N];
data        a[N];

bool cmp(const data u, const data v) {
	return (u.b > v.b or (u.b == v.b and u.a < v.a));
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d%d", &a[i].a, &a[i].b);
	sort(a+1,a+n+1,cmp);
	//for (int i=1;i<=n;i++) printf("%d %d\n",a[i].a,a[i].b);
	res = 1;
	s[1] = a[1].a;
	for (int i=2; i<=n; i++) {
		int j = res;
		while (j > 0 and s[j] > a[i].a) j--;
		if (j ==res) s[++res] = oo;
		s[j+1] = min(s[j+1], a[i].a);
	}
	printf("%d", res);

	return 0;
}
