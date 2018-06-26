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


const int N = 1e5+5, base = 1e6+9;
int n, k, st[base];
ll p[N], H[N];
string s;

ll getH(int i, int j) {
	if (i == 0) return H[j];
	ll ans = (H[j]-H[i-1]*p[j-i+1]%base)%base;
	while (ans < 0) ans += base;
	return ans;
}

bool check(int len) {
	FOR(i,0,base-1) st[i] = 0;
	FOR(i,0,n-1-len+1) {
		ll code = getH(i,i+len-1);
		if (++st[code] >= k) return true;
	}
	return false;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&k);
	getline(cin, s);

	p[0] = 1;
	FOR(i,1,n) p[i] = p[i-1] * 27 % base;

	H[0] = s[0]-'a'+1;
	FOR(i,1,n-1)
	H[i] = (H[i-1]*27 + s[i]-'a'+1) % base;

	int ans = 0;

	int L = 1, R = n;
	while (L <= R) {
		int mid = (L+R)/2;
		if (check(mid))
			ans = mid, L = mid+1;
		else
			R = mid-1;
	}

	cout << ans << endl;

	return 0;
}
