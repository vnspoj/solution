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

string s;
stack<int> st;
map<char, int> val;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> s;

	val['C'] = 12;
	val['H'] = 1;
	val['O'] = 16;
	val['('] = -1;
	val[')'] = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(val[s[i]]);
		} else if (s[i] == ')') {
			int v = val[')'], total = 0;
			while (v != val['(']) {
				v = st.top();
				st.pop();
				if (v != val['(']) total += v;
			}
			st.push(total);
		} else if (s[i] == 'C' || s[i] == 'H' || s[i] == 'O') {
			st.push(val[s[i]]);
		} else { // 2 -> 9
			int v = st.top();
			st.pop();
			st.push(v * (int)(s[i] - '0'));
		}
	}

	int res = 0;
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}

	cout << res << endl;

	return 0;
}
