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

const int N = 1500;
string a, b;
int F[N][N];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	getline(cin, a);
	getline(cin, b);
	FOR(i,0,a.size()-1)
	FOR(j,0,b.size()-1)
	if (a[i] == b[j])
		F[i+1][j+1] = F[i][j] + 1;
	else
		F[i+1][j+1] = max(F[i][j+1], F[i+1][j]);
	printf("%d\n", F[a.size()][b.size()]);


	return 0;
}
