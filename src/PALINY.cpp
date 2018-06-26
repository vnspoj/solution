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

const int N = 5e4+5, base = 1e9+9;
int n, ans;
ll p[N];
string s, t;
vector<ll> S, T;

vector<ll> getH(string s) {
	vector<ll> h(s.size(),0);
	h[0] = s[0]-'a'+1;
	FOR(i,1,s.size()-1)
	h[i] = (h[i-1] * 27 + s[i]-'a'+1) % base;
	return h;
}

ll getS(int l, int r) {
	if (l == 0) return S[r];
	ll ans = (S[r] - S[l-1] * p[r-l+1] % base) % base;
	while (ans < 0) ans += base;
	return ans;
}

ll getT(int l, int r) {
	if (l == 0) return T[r];
	ll ans = (T[r] - T[l-1] * p[r-l+1] % base) % base;
	while (ans < 0) ans += base;
	return ans;
}

bool check(int len) {
	FOR(i,0,n-1-len+1) {
		int j = i+len-1;
		if (getS(i,j) == getT(n-j-1,n-i-1))
			return true;
	}
	return false;
}

void solve(int L, int R, int k) {
	while (L <= R) {
		int mid = (L+R)/2, len = 2*mid+k;
		if (check(len))
			ans = max(ans, len), L = mid+1;
		else
			R = mid-1;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	getline(cin, s);

	t = s;
	reverse(t.begin(), t.end());

	S = getH(s);
	T = getH(t);

	p[0] = 1;
	FOR(i,1,n-1) p[i] = p[i-1] * 27 % base;

	solve(0,(n-1)/2,1);
	solve(1,n/2,0);

	printf("%d\n", ans);

	return 0;
}
