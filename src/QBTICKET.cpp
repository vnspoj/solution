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

const int N = 1e5+5;
const ll inf = 1e18;
int n, L[4], C[4], p[4], S, T;
ll s[N], F[N];


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	FOR(i,1,3) cin >> L[i];
	FOR(i,1,3) cin >> C[i];
	cin >> n >> S >> T;
	FOR(i,2,n) scanf("%lld", &s[i]);

	FOR(i,1,3) p[i] = S;

	FOR(i,S+1,T) {
		F[i] = inf;
		FOD(j,3,1) {
			while (s[i]-s[p[j]] > L[j]) p[j]++;
			F[i] = min(F[i], F[p[j]] + C[j]);
			p[j-1] = p[j];
		}
	}

	printf("%lld\n", F[T]);

	return 0;
}
