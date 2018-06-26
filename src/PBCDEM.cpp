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

const int bs = 1e9;
typedef vector<int> Big;

void Print(Big a) {
	printf("%d", a.back());
	FOD(i,a.size()-2,0) printf("%09d", a[i]);
	EL;
}

Big big(int x) {
	Big a;
	a.ep(x);
	return a;
}

Big operator + (Big a, Big b) {
	Big c;
	int v = 0;
	FOR(i, 0, max(a.size(), b.size()) - 1) {
		if (i < a.size()) v += a[i];
		if (i < b.size()) v += b[i];
		c.ep(v%bs);
		v /= bs;
	}
	if (v) c.ep(v);
	return c;
}

const int N = 5000;
int n, len[N];
Big ans, F[N][100];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	scanf("%d", &n);
	FOR(i,1,n) {
		int L = 1, R = i;
		while (L <= R) {
			int mid = (L+R)/2;
			if (mid*(mid+1) <= 2*i) {
				len[i] = mid;
				L = mid+1;
			} else
				R = mid-1;
		}
	}

	ans = big(0);
	FOR(i,0,n) FOR(j,0,len[n]) F[i][j] = big(0);

	F[0][0] = big(1);
	FOR(i,1,n)
	FOR(j,1,len[i])
	F[i][j] = F[i-j][j] + F[i-j][j-1];

	FOR(i,2,len[n]) ans = ans + F[n][i];

	Print(ans);

	return 0;
}
