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

const int   N = 2000000, mod = 1000000007;
int         n;
ll          f[N], res;
char        s[N];


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%s", &s);
	n = strlen(s);
	for (int i=1; i<=n; i++)
		f[i] = (f[i-1]*10 + (s[i-1]-'0')*i) % mod;

	for (int i=1; i<=n; i++)
		res = (res + f[i]) % mod;

	printf("%lld", res);

	return 0;
}
