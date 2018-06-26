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

const int   base = 2111992;
int         n,k,f[100100];


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d",&n,&k);
	for (int i=1; i<k+2; i++) f[i] = (i+1) % base;
	for (int i=k+2; i<=n; i++) f[i] = (f[i-k-1] % base + f[i-1] % base) % base;
	printf("%d",f[n]);

	return 0;
}
