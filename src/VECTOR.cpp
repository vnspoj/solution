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
	int x, y;
};

int     n, u, v, res;
data    a[100], t;
vector  <data> f, g;

void dfs1(int i) {
	if (i == n/2+1) {
		f.push_back(t);
		return ;
	}
	dfs1(i+1);
	t.x += a[i].x;
	t.y += a[i].y;
	dfs1(i+1);
	t.x -= a[i].x;
	t.y -= a[i].y;
}

void dfs2(int i) {
	if (i == n+1) {
		g.push_back(t);
		return ;
	}
	dfs2(i+1);
	t.x += a[i].x;
	t.y += a[i].y;
	dfs2(i+1);
	t.x -= a[i].x;
	t.y -= a[i].y;
}

bool cmp(const data u, const data v) {
	return ((u.x < v.x) or (u.x == v.x and u.y < v.y));
}

int Search(int x, int y) {
	int  l = 0, r = f.size()-1, ans = 0, k, mid;
	while (l <= r) {
		mid = (l+r)/2;
		if (f[mid].x < x) l = mid+1;
		else if (f[mid].x > x) r = mid-1;
		else {
			if (f[mid].y < y) {
				while (f[mid].x == x and f[mid].y < y and mid < r)
					mid++;
				if (f[mid].x != x or f[mid].y != y) return 0;
			} else if (f[mid].y > y) {
				while (f[mid].x == x and f[mid].y > y and mid > l)
					mid--;
				if (f[mid].x != x or f[mid].y != y) return 0;
			}
			ans = 1;
			k = mid+1;
			while (f[k].x == x and f[k].y == y and k <= r)
				ans++, k++;
			k = mid-1;
			while (f[k].x == x and f[k].y == y and k >= l)
				ans++, k--;
			return ans;
		}
	}
	return 0;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d %d", &a[i].x, &a[i].y);
	scanf("%d %d", &u, &v);

	t.x = 0;
	t.y = 0;
	dfs1(1);
	sort(f.begin(), f.end(), cmp);

	t.x = 0;
	t.y = 0;
	dfs2(n/2+1);

	for (int i=0; i<g.size(); i++) {
		int  x = u - g[i].x;
		int  y = v - g[i].y;
		res += Search(x,y);
	}

	printf("%d",res);

	return 0;
}
