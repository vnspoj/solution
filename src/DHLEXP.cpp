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

const ll mod = 1e9+9;

typedef struct Node {
	Node * L, * R;
	char c;
} * node;

node init(char c) {
	node a = new Node();
	a->c = c;
	a->L = a->R = nullptr;
	return a;
}

string number(string);
string change(string);
string suffix(string);
node Build_Binary_Tree(string);

#define f(x,y) dfs(a->L, x) * dfs(a->R, y) % mod

ll dfs(node a, int x) {
	if ('a' <= a->c && a->c <= 'z') return 1ll;
	if (a->c == '&')
		return x ? f(1,1) : ((f(1,0) + f(0,1)) % mod + f(0,0)) % mod;
	if (a->c == '|')
		return x ? ((f(1,0) + f(0,1)) % mod + f(1,1)) % mod : f(0,0);
	return x ? (f(1,0) + f(0,1)) % mod : (f(0,0) + f(1,1)) % mod;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	int T;
	scanf("%d\n", &T);
	while (T--) {
		string s;
		getline(cin, s);
		string num = number(s);
		s = suffix(change(s));
		node root = Build_Binary_Tree(s);
		ll ans = 1ll;
		FOR(i,0,num.size()-1)
		ans = (ans * dfs(root, num[i]-'0')) % mod;
		printf("%lld\n", ans);
	}

	return 0;
}

string number(string s) {
	string a, b;
	ll n = 0ll, i = s.size()-1;
	while (s[i] != ' ') a = s[i--] + a;
	FOR(i,0,a.size()-1) n = n*10ll + a[i]-'0';
	while (n) {
		b = char(n%2+'0') + b;
		n /= 2;
	}
	while (b.size() < 32) b = '0' + b;
	return b;
}

string change(string s) {
	string t;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ' && s[i+1] == '=') break;
		if (s[i] == 'A') t = t + '&', i += 2;
		else if (s[i] == 'O') t = t + '|', i++;
		else if (s[i] == 'X') t = t + '^', i += 2;
		else t = t + s[i];
	}
	return t;
}

string suffix(string s) {
	string t;
	s = '(' + s + ')';
	stack<char> st;
	FOR(i,0,s.size()-1) {
		if (s[i] == '(') st.push(s[i]);
		else if ('a' <= s[i] && s[i] <= 'z') t = t + s[i];
		else if (s[i] == ' ') continue;
		else if (s[i] == ')') {
			for (;;) {
				char k = st.top();
				st.pop();
				if (k == '(') break;
				t = t + k;
			}
		} else {
			while (!st.empty() && st.top() != '(') {
				t = t + st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	return t;
}

node Build_Binary_Tree(string s) {
	stack<node> st;
	FOR(i,0,s.size()-1) {
		node a = init(s[i]);
		if (s[i] < 'a' || s[i] > 'z') {
			a->R = st.top();
			st.pop();
			a->L = st.top();
			st.pop();
		}
		st.push(a);
	}
	return st.top();
}
