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

const int   N = 500010;
int         n, a[N];
set <int>   b;
set <int>::iterator it;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	b.insert(0);
	a[0] = 0;
	for (int i=1; i<=N; i++) {
		int k = a[i-1] - i;
		if (k > 0) {
			it = b.find(k);
			if (it != b.end()) {
				a[i] = a[i-1] + i;
				b.insert(a[i]);
			} else {
				a[i] = k;
				b.insert(k);
			}
		} else {
			a[i] = a[i-1] + i;
			b.insert(a[i]);
		}
	}

	while (1) {
		scanf("%d", &n);
		if (n == -1) break;
		printf("%d\n", a[n]);
	}

	return 0;
}
