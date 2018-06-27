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

int n, A, B;

void solve(int x) {
	if (x == 0) return ;
	int s = x/5;
	if (s > 0) A = A * (s%2 ? 4 : 6) % 10;
	for (int y = x; y % 5 > 0; y--)
		A = A * (y % 10) % 10;
	solve(x/5);
}

void calA() {
	A = n > 9 ? 6 : 1;
	FOR(i,1,n%10) if (i != 5) A = A * i % 10;
	solve(n/5);
}

void calB() {
	int k = 0, t = 0, F[20] = {0};
	for (ll i = 5ll; i <= n; i *= 5) F[++t] = n / i;
	FOR(i,1,t) k += i * (F[i] - F[i+1]);
	B = 1;
	k = (k-1+4)%4 + 1;
	FOR(i,1,k) B = B * 2 % 10;
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	if (n == 0) {
		puts("1");
		return 0;
	}
	calA();
	calB();
	for (int i = 2; i <= 8; i += 2)
		if (B * i % 10 == A) n = i;
	printf("%d\n", n);

	return 0;
}
