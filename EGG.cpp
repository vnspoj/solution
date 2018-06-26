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


const int   N = 1009, z = 1000;
int         t, n, m, f[N][N], llog[N];

int Log(int x) {
	int cnt = 0;
	while (x > 0) {
		cnt++;
		x /= 2;
	}
	return cnt;
}

void init() {
	for (int i=1; i<=z; i++) llog[i] = Log(i);
	for (int i=1; i<=z; i++)
		for (int j=1; j<=z; j++) f[i][j] = z;
	for (int i=1; i<=z; i++) f[1][i] = i;
	for (int i=2; i<=z; i++) {
		for (int j=1; j<=z; j++) {
			if (i > llog[j]) f[i][j] = f[i-1][j];
			else
				for (int k=2; k<=j; k++)
					f[i][j] = min(f[i][j], max(f[i-1][k-1], f[i][j-k])+1);
		}
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	init();
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", f[n][m]);
	}

	return 0;
}
