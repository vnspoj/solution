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

long l,r,x,y,z,a[200000],res = 0;

void edit() {
	for (long i=1; i<=r; i++) a[i] = 1;
	for (long i=2; i<=r/2; i++)
		for (long j=2; j<=r/i; j++)
			a[i*j] += i;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%li%li",&l,&r);
	edit();
	for (long i=l; i<=r; i++)
		if (a[i] > i) res++;
	printf("%li",res);

	return 0;
}
