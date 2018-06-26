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


const int N = 1100, inf = 1e9;
int n, m, k, s, t, lab[3][N];
int f[N][N], c[N][N], trace[N], dmin[N];
vector<int> a[N];

vector<int> Input() {
	string s;
	getline(cin, s);
	vector<int> a;
	for (int i = 0; i < s.size(); ) {
		int x = 0;
		while (i < s.size() && s[i] == ' ') ++i;
		while (i < s.size() && s[i] != ' ')
			x = x * 10 + s[i++] - '0';
		if (x) a.pb(x);
	}
	return a;
}

void solve(int group) {
	FOR(i,1,n) {
		lab[group][i] = ++k;
		vector<int> adj = Input();
		for (auto j : adj) {
			if (group == 1)
				a[k].pb(j), a[j].pb(k), c[k][j] = 1;
			else
				a[k].pb(j+m), a[j+m].pb(k), c[j+m][k] = 1;
		}
	}
}

void Add(int &s, int group) {
	s = ++k;
	FOR(i,1,n) {
		int t = lab[group][i];
		a[s].pb(t);
		a[t].pb(s);
		if (group == 1) c[s][t] = 1;
		else c[t][s] = 1;
	}
}

void init() {
	k = m * 2;
	FOR(i,1,m) {
		int j = i + m;
		a[i].pb(j);
		a[j].pb(i);
		c[i][j] = 1;
	}
	solve(1);
	solve(2);
	Add(s,1);
	Add(t,2);
}

bool findPath() {
	FOR(i,1,k) dmin[i] = inf, trace[i] = 0;
	trace[s] = -1;
	queue<int> st;
	st.push(s);
	while (! st.empty()) {
		int u = st.front();
		st.pop();
		for (auto v : a[u]) {
			if (trace[v] == 0 && c[u][v] > f[u][v]) {
				trace[v] = u;
				dmin[v] = min(dmin[u], c[u][v] - f[u][v]);
				if (v == t) return true;
				st.push(v);
			}
		}
	}
	return false;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&m);

	init();

	while (findPath()) {
		int v = t, del = dmin[t];
		while (v != s) {
			int u = trace[v];
			f[u][v] += del;
			f[v][u] -= del;
			v = u;
		}
	}

	FOR(i,1,m) {
		int j = i + m, u = 0, v = 0, e = 0;
		FOR(q,1,n) {
			e = lab[1][q];
			if (f[e][i] > 0) u = q;
			e = lab[2][q];
			if (f[j][e] > 0) v = q;
			if (u && v) break;
		}
		printf("%d %d\n", u, v);
	}

	return 0;
}
