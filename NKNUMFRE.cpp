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

int rev(int x) {
	int ans = 0;
	while (x > 0) {
		ans = ans*10 + x%10;
		x /= 10;
	}
	return ans;
}

int a, b, res;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> a >> b;
	FOR(i,a,b) {
		if (__gcd(i, rev(i)) == 1) res++;
	}

	cout << res << endl;

	return 0;
}
