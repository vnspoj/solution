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


int     n, l, a[1000], x[1000], cnt, dd[1000];

void xuat() {
	for (int i=1; i<=l; i++) printf("%d ", x[i]);
	printf("\n");
}

void dfs(int i) {
	if (i == l+1) {
		xuat();
		cnt++;
		if (cnt == 1000) exit(0);
		return ;
	}
	if (i == 1) {
		for (int j=1; j<=n; j++)
			if (!dd[j]) {
				dd[j] = 1;
				for (int k=1; k<=a[j]; k++) x[i+k-1] = j;
				dfs(i+a[j]);
				dd[j] = 0;
			}
	} else {
		for (int j=0; j<=n; j++)
			if (!dd[j])
				if (j > 0) {
					dd[j] = 1;
					for (int k=1; k<=a[j]; k++) x[i+k-1] = j;
					dfs(i+a[j]);
					dd[j] = 0;
				} else if (x[i-1] > 0)
					for (int k=a[0]; k>0; k--) {
						for (int q=1; q<=k; q++) x[i+q-1] = 0;
						a[0] -= k;
						if (a[0] == 0) dd[0] = 1;
						dfs(i+k);
						dd[0] = 0;
						a[0] += k;
					}
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &l,&n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[0] += a[i];
	}
	a[0] = l - a[0];
	dfs(1);

	return 0;
}
