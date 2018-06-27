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

typedef struct Trie {
	int f, g;
	Trie * c[2];
} * trie;

trie New() {
	trie a = new Trie();
	return a;
}

trie root = New();

void dfs(trie a) {
	a->g = a->f;
	FOR(i,0,1)
	if (a->c[i] != nullptr) {
		dfs(a->c[i]);
		a->g += a->c[i]->g;
	}
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	int n, m, k, x;

	cin >> n >> m;
	while (n--) {
		scanf("%d", &k);
		trie a = root;
		FOR(i,1,k) {
			scanf("%d", &x);
			if (a->c[x] == nullptr) a->c[x] = New();
			a = a->c[x];
		}
		a->f++;
	}

	dfs(root);

	while (m--) {
		scanf("%d", &k);
		trie a = root;
		int i, ans = 0;
		for (i = 1; i <= k; i++) {
			scanf("%d", &x);
			if (a->c[x] == nullptr) break;
			a = a->c[x];
			ans += a->f;
		}
		if (i == k+1) ans += a->g - a->f;
		for (i = i + 1; i <= k; i++) scanf("%d", &x);
		printf("%d\n", ans);
	}

	return 0;
}
