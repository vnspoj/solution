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

const int N = 500005;
int m, n, cnt, F[N];


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &m,&n);
	FOR(i,1,m) {
		int h, l, r;
		scanf("%d", &h);
		if (i%2) l = 1, r = h;
		else l = n-h+1, r = n;
		F[l]++;
		F[r+1]--;
	}
	FOR(i,1,n) {
		F[i] += F[i-1];
		if (F[i] < m) m = F[i], cnt = 1;
		else if (F[i] == m) cnt++;
	}
	printf("%d %d\n", m, cnt);

	return 0;
}
