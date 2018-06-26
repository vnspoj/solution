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

const int N = 100001, M = 790972;
int n, k;
ll F[2][51], ans;
ii a[N];

bool cmp(ii u, ii v) {
	return u.Y < v.Y;
}

int get(int L, int R) {
	F[1][1] = a[L].X;
	FOR(i,2,k) F[1][i] = 0;
	FOR(i,L+1,R) {
		FOR(j,1,k) F[0][j] = F[1][j];
		F[1][1] = F[0][1] + a[i].X;
		FOR(j,2,k)
		F[1][j] = (F[0][j] + F[0][j-1] * a[i].X % M) % M;
	}

	return F[1][k];
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&k);
	FOR(i,1,n) scanf("%d%d", &a[i].X, &a[i].Y);
	sort(a+1,a+n+1,cmp);

	ans = get(1,n);

	int L = 1, R = 1;
	ll S = 0ll;
	while (L <= n) {
		while (R < n && a[R+1].Y == a[L].Y) ++R;
		S = (S + get(L,R)) % M;
		L = ++R;
	}

	ans = (ans - S + 2 * M) % M;

	printf("%d\n", ans);

	return 0;
}
