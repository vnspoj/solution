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
 
const int N = 1e6+6;
char c[N];
ll  f[N];
 
int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);
 
	gets(c);
	int l = strlen(c);
	int cur = 0, n = 0;
	for (int i=0; i<l; i++) {
		if (c[i] == '7') {
			f[++cur]++;
			n = max(n, cur);
		} else {
		   	cur = 0;
		}
	}
	
	for (int i=n-1;i>0;i--) f[i] += f[i+1];
 
	for (int i=1; i<=n; i++) printf("%d %lld\n", i, f[i]);
 
	return 0;
}
