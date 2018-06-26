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

int     n[100],m,k,l,f[1000001],maxn;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d",&k,&l,&m);
	for (int i=1; i<=m; i++) {
		scanf("%d",&n[i]);
		maxn = max(n[i],maxn);
	}
	for (int i=1; i<=maxn; i++) {
		if (i-1 >= 0 and f[i-1] == 0) f[i] = 1;
		if (i-k >= 0 and f[i-k] == 0) f[i] = 1;
		if (i-l >= 0 and f[i-l] == 0) f[i] = 1;
	}
	for (int i=1; i<=m; i++)
		if (f[n[i]] == 1) printf("A");
		else printf("B");

	return 0;
}
