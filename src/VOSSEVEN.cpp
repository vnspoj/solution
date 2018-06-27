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

char c[1000009];
int  a[1000009], n, l, m;
ll   t[1000009];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	gets(c);
	l = strlen(c);
	for (int i=0; i<l; i++) {
		if (c[i] == '7') {
			if (i > 0 and c[i-1] == '7') a[n]++;
			else a[++n] = 1;
		}
	}

	for (int i=1; i<=n; i++) m = max(m, a[i]);

	for (int i=1; i<=n; i++)
		for (int j=1; j<=a[i]; j++)
			t[j] += (a[i]-j+1);

	for (int i=1; i<=m; i++) printf("%d %lld\n", i, t[i]);

	return 0;
}
