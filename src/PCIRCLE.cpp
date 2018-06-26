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


int     n,x[100],dd[100];
bool    yes[100][100];
int     res[100] = {0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144};
int     dem = 0;

bool kt(int x) {
	if (x <= 1) return false;
	for (int i=2; i*i<=x; i++)
		if (x % i == 0) return false;
	return true;
}

void dq(int t) {
	if (t == n+1) {
		if (not yes[x[1]][x[n]]) return;
		dem++;
		for (int i=1; i<=n; i++) printf("%d ",x[i]);
		printf("\n");
		return;
	}
	for (int i=1; i<=n; i++)
		if (dd[i] == 0 and yes[x[t-1]][i]) {
			x[t] = i;
			dd[i] = 1;
			dq(t+1);
			if (dem == 10000) return;
			dd[i] = 0;
		}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d",&n);
	printf("%d\n",res[n]);

	n *= 2;
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++) {
			yes[i][j] = kt(i+j);
			yes[j][i] = yes[i][j];
		}

	x[1] = 1;
	dd[1] = 1;
	dq(2);

	return 0;
}
