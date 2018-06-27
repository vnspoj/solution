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


const int N = 100100;
int n, a[N], s[N];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", a+i);
	int k = 1;
	s[1] = a[1];
	FOR(i,2,n) {
		int j = k;
		while (j > 0 && s[j] <= a[i]) j--;
		if (j == k) s[++k] = a[i];
		s[j+1] = max(s[j+1], a[i]);
	}
	printf("%d\n", k);

	return 0;
}
