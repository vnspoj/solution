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
	Trie * c[30];
} * trie;

trie New() {
	trie a = new Trie();
	a->f = a->g = 0;
	return a;
}

trie root = New();

int dfs(trie a) {
	a->g = a->f;
	FOR(i,0,25)
	if (a->c[i] != nullptr) {
		dfs(a->c[i]);
		a->g = max(a->g, a->f + a->c[i]->g);
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	int n;
	scanf("%d\n", &n);
	while (n--) {
		string s;
		getline(cin, s);
		trie a = root;
		FOR(i,0,s.size()-1) {
			if (a->c[s[i]-'a'] == nullptr) a->c[s[i]-'a'] = New();
			a = a->c[s[i]-'a'];
		}
		a->f = 1;
	}

	dfs(root);

	cout << root->g;

	return 0;
}
