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

ll      n, tr[20], ph[20], nt, np, a[20];


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%I64d",&n);
	a[0] = 1;
	for (int i=1; i<=18; i++) a[i] = a[i-1]*3;
	for (int i=0; n>0; n/=3,i++) ph[i] = n%3;
	for (int i=0; i<=17; i++) {
		if (ph[i] == 1) np++;
		else if (ph[i] == 2) nt++, tr[i] = 1, ph[i+1]++;
		else if (ph[i] == 3) ph[i+1]++;
	}

	printf("%I64d ", nt);
	for (int i=0; i<=18; i++)
		if (tr[i] == 1) printf("%I64d ", a[i]);

	EL;

	printf("%I64d ", np);
	for (int i=0; i<=18; i++)
		if (ph[i] == 1) printf("%I64d ", a[i]);

	return 0;
}
