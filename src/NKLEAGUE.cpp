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

const int   N = 1500;
int         n, cnt, node[N], dd[N];
vector<int> ke[N];
char        s[N];

void dfs(int u) {
	dd[u] = 1;
	for (int i=0; i<ke[u].size(); i++) {
		int v = ke[u][i];
		if (!dd[v]) dfs(v);
	}
	node[cnt] = u;
	cnt--;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	for (int i=1; i<=n; i++) {
		scanf("%s",&s);
		for (int j=1; j<=n; j++) {
			if (s[j-1] == '1')
				ke[i].push_back(j);
		}
	}

	cnt = n;
	for (int i=1; i<=n; i++) if (!dd[i]) dfs(i);

	for (int i=1; i<=n; i++) printf("%d ", node[i]);

	return 0;
}
