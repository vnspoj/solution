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

const int   base = 20122007;
ll          n,res = 1;

ll  g(int x) {
	if (x == 1) return 3;
	ll tmp = g(x/2) % base;
	if (x % 2 == 0) return (tmp*tmp) % base;
	return ((tmp*tmp % base)*3) % base;
}

ll  f(int x) {
	return (g(x) - 1 + base) % base;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%lli",&n);
	for (int i=1; i*i<=n; i++) {
		if (n % i == 0) {
			if (i*i == n)
				res = res*f(i) % base;
			else
				res = ((res*f(i) % base) * f(n/i)) % base;
		}
	}
	printf("%lli",res);

	return 0;
}
