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

string a, b, s;

vector<int> Z_Function(string s) {
	vector<int> z(s.size(),0);
	for(int i=1,l=0,r=0; i<s.size(); i++) {
		if (i <= r) z[i] = min(z[i-l], r-i+1);
		while (i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) ++z[i];
		if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
	}
	return z;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> a >> b;
	s = b + '#' + a;
	vector<int> z = Z_Function(s);
	int ans = 0;
	FOR(i,b.size()+1,s.size()-1) {
		if (ans < z[i] && i+z[i] == s.size()) ans = z[i];
	}
	FOR(i,0,a.size()-1) printf("%c", a[i]);
	FOR(i,ans,b.size()-1) printf("%c", b[i]);
	EL;

	return 0;
}
