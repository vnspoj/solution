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

ll  n, k;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	while (1) {
		scanf("%lld%lld", &n,&k);
		if (n == 0 and k == 0) break;
		while (k%2 == 0) n--, k /= 2;
		if (n == 1)
			printf("D\n");
		else if (k%4 == 1)
			printf("U\n");
		else
			printf("D\n");
	}

	return 0;
}
