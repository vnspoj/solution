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

const int N = 2e6+5;
int kmp[N];
string a, b, s;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> a >> b;
	s = b + '#' + a;

	kmp[0] = 0;
	FOR(i,1,s.size()-1) {
		int j = kmp[i-1];
		while (j > 0 && s[j] != s[i]) j = kmp[j-1];
		if (s[j] == s[i]) ++j;
		kmp[i] = j;
	}

	FOR(i,b.size()+1,s.size()-1)
	if (kmp[i] == b.size())
		printf("%d ", i-2*b.size()+1);

	return 0;
}
