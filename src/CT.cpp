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

int t, x, y;
ll res;

ll getA(int l, int r) {
	l = max(l,0);
	r = min(r,x);
	return (ll) r-l+1;
}

ll getB(int l, int r) {
	l = max(l,0);
	r = min(r,y);
	return (ll) r-l+1;
}

void solve(int i, int j) {
	res += getA(i-j,i-j+y)*getB(i+j-x,i+j)-1;
	res += getA(j+i-y,j+i)*getB(j-i,j-i+x)-1;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &t);
	while(t--) {
		scanf("%d%d\n", &x,&y);
		res = 0ll;
		FOR(i,0,x) FOR(j,0,y) solve(i,j);
		printf("%lld\n", res/2);
	}

	return 0;
}
