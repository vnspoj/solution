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

int m, n, a[5500];
bool F[5500];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &m,&n);
	FOR(i,1,n) scanf("%d", &a[i]);
	F[0] = 1;
	FOR(i,1,n)
	FOD(j,m,a[i])
	F[j] = F[j] || F[j-a[i]];
	FOD(i,m,0)
	if (F[i]) {
		printf("%d\n", i);
		break;
	}

	return 0;
}
