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


const int N = 1005;
int n, a[N], F[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n;
	FOR(i,1,n) scanf("%d", &a[i]);

	a[++n] = 10001;
	FOR(j,1,n) {
		F[j] = 1;
		FOR(i,1,j-1) if (a[i] < a[j]) F[j] = max(F[j], F[i]+1);
	}

	cout << F[n]-1;

	return 0;
}
