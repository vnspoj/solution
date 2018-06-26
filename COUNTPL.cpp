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

const int N = 300, inf = 1e9;
int n, F[N], f[N][N];
char a[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%s\n", a+1);
	n = strlen(a+1);

	FOD(i,n,1)
	FOR(j,i,n)
	if (i == j) f[i][j] = 1;
	else {
		if (i == j-1) f[i][j] = a[i] == a[j];
		else {
			if (a[i] == a[j]) f[i][j] = f[i+1][j-1];
		}
	}

	F[1] = 1;
	FOR(i,2,n) {
		F[i] = inf;
		FOR(j,1,i)
		if (f[j][i])
			F[i] = min(F[i], F[j-1] + 1);
	}

	printf("%d\n", F[n]);

	return 0;
}
