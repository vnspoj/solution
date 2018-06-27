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

const int inf = 1e9;
int n, a[8], c[8][8], dd[8], ans = inf;
map<string,int> d;
string f;

struct data {
	string s;
	int c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

void solve(string s) {
	int i = 0;
	while (i < s.size()) {
		int x = 0;
		while (i < s.size() && s[i] == ' ') ++i;
		while (i < s.size() && s[i] != ' ')
			x = x * 10 + s[i++] - '0';
		if (x) a[++n] = x;
	}
}

void init(int x) {
	if (x == n) {
		d[f] = inf;
		return ;
	}
	FOR(i,1,n)
	if (! dd[i]) {
		f[x] = char(i+'0');
		dd[i] = 1;
		init(x+1);
		dd[i] = 0;
	}
}

bool ok(string s) {
	FOR(i,0,n-2)
	if (a[s[i]-'0'] > a[s[i+1]-'0']) return false;
	return true;
}

void dijkstra() {
	string s = "";
	FOR(i,1,n) s = s + char(i+'0');
	priority_queue<data> st;
	st.push({s, d[s] = 0});
	while (! st.empty()) {
		string s = st.top().s;
		int w = st.top().c;
		st.pop();
		if (ok(s)) ans = min(ans, d[s]);
		if (w > d[s]) continue;
		FOR(i,0,n-1)
		FOR(j,i+1,n-1) {
			string t = s;
			swap(t[i], t[j]);
			if (d[t] > d[s] + c[i+1][j+1]) {
				d[t] = d[s] + c[i+1][j+1];
				st.push({t, d[t]});
			}
		}
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	string s;
	getline(cin, s);
	solve(s);
	FOR(i,1,n) FOR(j,1,n) scanf("%d", &c[i][j]);

	f.resize(n);
	init(0);
	dijkstra();

	printf("%d\n", ans);


	return 0;
}
