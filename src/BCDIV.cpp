#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int T, n, k;
ll  F[50][50];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	F[0][0] = 1ll;
	FOR(i,1,25)
	FOR(j,1,25)
	F[i][j] = F[i-1][j-1] + j*F[i-1][j];

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n,&k);
		printf("%lld\n", F[n][k]);
	}

	return 0;
}
