#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 10001;
int n, k, a[N], F[N], res;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> k;

	FOR(i,1,n) scanf("%d", &a[i]);
	FOR(i,1,n) {
		F[i] = -1e9;
		FOR(j,1,k) {
			F[i] = max(F[i], F[i-j] + a[i]);
			res = max(res, F[i]);
		}
	}

	cout << res << endl;

	return 0;
}
