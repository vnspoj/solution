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
int n, a[N], s[N], F0[N], F1[N], k, res;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[i]);

	k = 1;
	s[1] = a[n];
	F0[n] = 1;
	FOD(i,n-1,1) {
		int j = k;
		while (j > 0 && a[i] >= s[j]) j--;
		if (j == k) s[++k] = 0;
		s[j+1] = max(s[j+1], a[i]);
		F0[i] = j+1;
	}

	k = 1;
	fillchar(s,0);
	s[1] = a[n];
	F1[n] = 1;
	FOD(i,n-1,1) {
		int j = k;
		while (j > 0 && a[i] <= s[j]) j--;
		if (j == k) s[++k] = 1e9+7;
		s[j+1] = min(s[j+1], a[i]);
		F1[i] = j+1;
	}

	FOR(i,1,n) res = max(res, F0[i]+F1[i]-1);
	printf("%d\n", res);

	return 0;
}
