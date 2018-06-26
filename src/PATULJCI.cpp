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

const int N = 3e5+5;
int n, c, a[N], q, l, r;
vector<int> f[N];

int Random() {
	int a = rand()%5000;
	int b = rand()%5000;
	return a*5000+b;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> c;
	FOR(i,1,n) scanf("%d", &a[i]), f[a[i]].pb(i);

	cin >> q;
	while (q--) {
		scanf("%d%d", &l,&r);
		int ok = 0;
		FOR(i,1,25) {
			c = a[l+Random()%(r-l+1)];
			int L = lower_bound(f[c].begin(),f[c].end(),l)-f[c].begin();
			int R = upper_bound(f[c].begin(),f[c].end(),r)-f[c].begin();
			if (R-L > (r-l+1)/2) {
				ok = 1;
				break;
			}
		}
		if (ok) printf("yes %d\n", c);
		else puts("no");
	}

	return 0;
}
