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
	int cnt;
	Trie * c[52];
} * trie;

int order(char c) {
	if ('a' <= c && c <= 'z') return c - 'a';
	return c - 'A' + 'z' - 'a' + 1;
}

trie New() {
	trie a = new Trie();
	a->cnt = 0;
	return a;
}

const int N = 1e5+5;
int n;
string s;
trie root = New();

void dfs(trie a, string s) {
	if (a->cnt%2) {
		cout << s << endl;
		exit(0);
	}
	for (char c = 'a'; c <= 'z'; c++) {
		if (a->c[order(c)]) {
			dfs(a->c[order(c)], s + c);
		}
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		if (a->c[order(c)])
			dfs(a->c[order(c)], s + c);
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	FOR(i,1,n) {
		getline(cin, s);
		trie a = root;
		FOR(i,0,s.size()-1) {
			if (a->c[order(s[i])] == nullptr)
				a->c[order(s[i])] = New();
			a = a->c[order(s[i])];
		}
		a->cnt ^= 1;
	}

	dfs(root, s = "");
	puts("-1");

	return 0;
}
