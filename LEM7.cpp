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


const int   N = 15000, oo = 10000000;
int         e, fn[N], fs[N], fk[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &e);

	for (int i=1; i<=e; i++)
		for (int j=sqrt(i); j>0; j--)
			if (i%j == 0) {
				fn[i] = j + i/j;
				fs[i] = min(j, i/j);
				fk[i] = 1;
				break;
			}

	for (int i=2; i<=e; i++)
		for (int j=1; j*2<=i; j++) {
			int n = fn[j] + fn[i-j];
			int s = fs[j] + fs[i-j];
			int k = fk[j] + fk[i-j];
			if (n < fn[i] or (n == fn[i] and s < fs[i]) or (n == fn[i] and s == fs[i] and k < fk[i])) {
				fn[i] = n;
				fs[i] = s;
				fk[i] = k;
			}
		}

	printf("%d %d %d", fn[e], fs[e], fk[e]);

	return 0;
}
