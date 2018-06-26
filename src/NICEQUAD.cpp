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

int     t, n;
ll      res, cnt[10][10];
data    p[10][10];

int phan(int x, int y) {
	if (x > 0 and y > 0) return 1;
	if (x < 0 and y > 0) return 2;
	if (x < 0 and y < 0) return 3;
	if (x > 0 and y < 0) return 4;
}

int cho(int x, int y) {
	if (x == 1 and y == 1) return 4;
	if (x == 1 and y == 2) return 2;
	if (x == 2 and y == 1) return 3;
	if (x == 2 and y == 2) return 1;
}

void solve_x(int p1, int p2, int d1, int d2, int x) {
	p[p1][d1].x = p[p1][d2].x = p[p2][d1].x = p[p2][d2].x = x;
}

void solve_y(int p1, int p2, int d1, int d2, int y) {
	p[p1][d1].y = p[p1][d2].y = p[p2][d1].y = p[p2][d2].y = y;
}

bool kt(data A, data B, data C, data D) {
	int k = (A.x-B.x)*(A.y+B.y)+(B.x-C.x)*(B.y+C.y)
	        +(C.x-D.x)*(C.y+D.y)+(D.x-A.x)*(D.y+A.y);
	if (k%2 == 0) return true;
	return false;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	solve_x(1,4,1,3,2);
	solve_x(1,4,2,4,1);
	solve_x(2,3,2,4,-1);
	solve_x(2,3,1,3,-2);

	solve_y(1,2,1,2,2);
	solve_y(1,2,3,4,1);
	solve_y(4,3,3,4,-1);
	solve_y(4,3,1,2,-2);

	scanf("%d", &t);
	while (t--) {
		for (int i=1; i<=4; i++)
			for (int j=1; j<=4; j++)
				cnt[i][j] = 0;
		res = 0;
		scanf("%d", &n);
		for (int i=1,x,y; i<=n; i++) {
			scanf("%d%d", &x,&y);
			if (x == 0 or y == 0) continue;
			int ph = phan(x,y);
			x = (x%2+2)%2;
			y = (y%2+2)%2;
			if (x == 0) x = 2;
			if (y == 0) y = 2;
			int k = cho(x,y);
			cnt[ph][k]++;
		}

		for (int d1=1; d1<=4; d1++)
			for (int d2=1; d2<=4; d2++)
				for (int d3=1; d3<=4; d3++)
					for (int d4=1; d4<=4; d4++) {
						if (kt(p[1][d1], p[2][d2], p[3][d3], p[4][d4]))
							res += (cnt[1][d1]*cnt[2][d2]*cnt[3][d3]*cnt[4][d4]);
					}
		printf("%lld\n", res);
	}

	return 0;
}
