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


const int  maxn = 50000; // can(2^31-1)
int        n, res = 1;
bool       a[maxn];
int        z, p[maxn], k[maxn], Max;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d",&n);
	Max = sqrt(n);
	int i = 2, j;
	a[1] = true;
	a[0] = true;
	while (i <= Max) {
		if (n % i == 0) {
			z++;
			p[z] = i;
		}
		j = i + i;
		while (j <= Max) {
			a[j] = true;
			j += i;
		}
		i++;
		while (a[i]) i++;
	}

	int m = n;
	for (int i=1; i<=z; i++) {
		while (m % p[i] == 0) {
			k[i]++;
			m /= p[i];
		}
	}
	if (m > 1) {
		z++;
		p[z] = m;
		k[z] = 1;
	}

	for (int i=1; i<=z; i++) {
		long tmp = 1;
		for (int j=1; j<k[i]; j++) tmp *= p[i];
		res *= ((p[i]-1)*tmp);
	}

	printf("%d",res);

	return 0;
}
