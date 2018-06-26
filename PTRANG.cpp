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


const int N = 6005;
int n, L, a[N], f[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> L;
	FOR(i,1,n) scanf("%d", &a[i]);

	FOR(i,1,n) {
		f[i] = L+1;
		int j = i, S = a[i];
		while (j > 0 && S <= L) {
			f[i] = min(f[i], max(f[j-1], L-S));
			S += a[--j];
		}
	}

	cout << f[n] << endl;

	return 0;
}
