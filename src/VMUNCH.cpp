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

struct qwe {
	int x, y;
};

qwe     que[1500000];
int     n,m,a[150][150],l,r,u,v,s,t,res[150][150];
char    c[150];

bool kt(int d, int f) {
	return (1 <= d and d <= n and 1 <= f and f <= m);
}

void xet(int d, int f) {
	if (kt(d,f) and a[d][f] == 1) {
		a[d][f] = 0;
		r++;
		que[r].x = d;
		que[r].y = f;
		res[d][f] = res[u][v] + 1;
	}
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) {
		scanf("%s",&c);
		for (int j=0; j<m; j++) {
			if (c[j] == '.') a[i][j+1] = 1;
			else if (c[j] == 'C') {
				u = i;
				v = j+1;
			} else if (c[j] == 'B') {
				s = i;
				t = j+1;
				a[s][t] = 1;
			}
		}
	}
	l = 1;
	r = 1;
	que[1].x = u;
	que[1].y = v;
	res[u][v] = 0;
	while (l <= r) {
		u = que[l].x;
		v = que[l].y;
		if (u == s and v == t) {
			printf("%d",res[u][v]);
			return 0;
		}
		xet(u-1,v);
		xet(u+1,v);
		xet(u,v-1);
		xet(u,v+1);
		l++;
	}
	printf("0");

	return 0;
}
