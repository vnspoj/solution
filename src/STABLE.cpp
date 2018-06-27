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

const int N = 10005;
int n, m, s, d[N], f[N];
vector<int> a[N];
queue<int> st;
map<int,bool> dd[N];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d", &n,&m,&s);
	while (m--) {
		int i, j;
		scanf("%d%d", &i,&j);
		if (!dd[i][j]) a[i].pb(j), dd[i][j] = 1;
	}

	d[s] = f[s] = 1;
	st.push(s);
	while (! st.empty()) {
		int u = st.front();
		st.pop();
		for (auto v : a[u]) {
			if (d[v] == 0) {
				d[v] = d[u] + 1;
				f[v] = f[u];
				st.push(v);
			} else {
				if (d[v] == d[u] + 1) f[v]++;
			}
		}
	}

	int ans = 0;
	FOR(i,1,n)
	if (i != s && d[i] && f[i] > 1) ans++;

	printf("%d\n", ans);

	return 0;
}
