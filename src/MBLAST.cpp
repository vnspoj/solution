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

const int N = 2500;
int n, m, k, F[N][N];
string a, b;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	getline(cin, a);
	a = "#" + a;
	n = a.size() - 1;
	getline(cin,b);
	b = "#" + b;
	m = b.size() - 1;
	scanf("%d", &k);

	FOR(i,0,m) F[0][i] = i*k;
	FOR(i,0,n) F[i][0] = i*k;

	FOR(i,1,n)
	FOR(j,1,m) {
		F[i][j] = F[i-1][j-1] + abs(a[i]-b[j]);
		F[i][j] = min(F[i][j], F[i-1][j-1] + k*2);
		F[i][j] = min(F[i][j], F[i-1][j] + k);
		F[i][j] = min(F[i][j], F[i][j-1] + k);
	}

	printf("%d\n", F[n][m]);

	return 0;
}
