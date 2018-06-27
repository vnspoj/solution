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


int n, a[20000], res, i, tmp, trace;

bool kt(int x) {
	int del = 1+8*x;
	int can = sqrt(del);
	if (can*can == del and (-1+can)%2 == 0 and (-1+can) != 0)
		return true;
	return false;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	i = 1;
	while (i <= n) {
		if (kt(a[i])) {
			tmp = 0;
			while (i <= n and kt(a[i])) {
				tmp++;
				if (i == n or a[i+1] < a[i]) {
					i++;
					break;
				}
				i++;
			}
			res = max(res,tmp);
		} else
			i++;
	}
	printf("%d",res);

	return 0;
}
