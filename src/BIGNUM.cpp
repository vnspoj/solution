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
typedef vector<int> BigInt;

void Set(BigInt &a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt Int(string s) {
	BigInt a;
	while (s.size()%9) s = '0'+s;
	for (int i=0; i<s.size(); i+=9) {
		ll b = 0;
		FOR(j,i,i+9-1) b = b*10+(s[j]-'0');
		a.insert(a.begin(), b);
	}
	Set(a);
	return a;
}

void Print(BigInt a) {
	Set(a);
	printf("%d", a.size() == 0 ? 0 : a.back());
	FOD(i,a.size()-2,0) printf("%09d", a[i]);
	EL;
}

BigInt operator + (BigInt a, BigInt b) {
	BigInt ans;
	Set(a);
	Set(b);
	int c = 0;
	for (int i=0; i<max(a.size(),b.size()); i++) {
		if (i < a.size()) c += a[i];
		if (i < b.size()) c += b[i];
		ans.pb(c%bs);
		c /= bs;
	}
	if (c) ans.pb(c);
	Set(ans);
	return ans;
}

BigInt operator - (BigInt a, BigInt b) {
	BigInt ans;
	Set(a);
	Set(b);
	int c = 0;
	for (int i=0; i<a.size(); i++) {
		c += a[i];
		if (i < b.size()) c -= b[i];
		if (c < 0)
			ans.pb(c+bs), c = -1;
		else
			ans.pb(c), c = 0;
	}
	Set(ans);
	return ans;
}

bool operator < (BigInt a, BigInt b) {
	if (a.size() != b.size()) return (a.size() < b.size());
	FOD(i,a.size()-1,0)
	if (a[i] != b[i]) return (a[i] < b[i]);
	return false;
}

BigInt operator * (BigInt a, BigInt b) {
	BigInt ans(a.size()+b.size(), 0);
	Set(a);
	Set(b);
	FOR(i,0,a.size()-1) {
		int c = 0;
		FOR(j,0,b.size()-1) {
			ll s = (ll)ans[i+j] + c + (ll)a[i]*b[j];
			ans[i+j] = s%bs;
			c = s/bs;
		}
		if (c) ans[i+b.size()] = c;
	}
	Set(ans);
	return ans;
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	string s;
	BigInt a, b;
	getline(cin, s);
	a = Int(s);
	getline(cin, s);
	b = Int(s);
	Print(a+b);
	if (a < b) {
		printf("-");
		Print(b-a);
	} else Print(a-b);
	Print(a*b);

	return 0;
}
