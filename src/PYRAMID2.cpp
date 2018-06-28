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


const int   N = 1500000;
int         n, a[N], delay, m, l, r;
char        c[N];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	scanf("%s\n", &c);

	l = 0;
	while (l < n and c[l] == '<') l++, m++;
	while (l < n and c[l] == '>') l++;
	if (l == n) {
		printf("0");
		return 0;
	}

	r = n-1;
	while (r >= 0 and c[r] == '>') r--;
	if (r == -1) {
		printf("0");
		return 0;
	}

	m++;
	for (int i=l+1; i<=r; i++) {
		if (c[i] == '<') {
			m++;
			delay++;
			if (delay < 0) delay = 0;
		} else
			delay--;
	}

	printf("%d", r+1 - m + delay);

	return 0;
}
