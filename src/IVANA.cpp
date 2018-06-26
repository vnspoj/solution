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

int n, a[500], f[500][500], res;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[i] %= 2;
		f[i][i] = (a[i] == 1);
	}

	for (int len=1; len<n; len++) {
		for (int i=1; i<=n; i++) {
			int j = (i+len-1)%n + 1;
			int next_i = i%n+1, last_j = (j-2+n)%n+1;
			f[i][j] = max(f[i][i]-f[next_i][j], f[j][j]-f[i][last_j]);
		}
	}

	for (int i=1; i<=n; i++) {
		int next_i = i%n+1, last_i = (i-2+n)%n+1;
		res += (f[i][i]-f[next_i][last_i] > 0);
	}

	printf("%d", res);

	return 0;
}
