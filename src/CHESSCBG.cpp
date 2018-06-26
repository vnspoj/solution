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

struct data {
	int a[4][4];
};

const int N = 70000;
int dd[N];
data a;
queue<data> st;

int getCode(data a) {
	int ans = 0;
	FOR(i,0,3) FOR(j,0,3) ans = ans * 2 + a.a[i][j];
	return ans;
}

data read() {
	data a;
	FOR(i,0,3) {
		string s;
		getline(cin, s);
		FOR(j,0,3) a.a[i][j] = s[j] - '0';
	}
	return a;
}

void push(data a, int ord) {
	st.push(a);
	dd[getCode(a)] = ord;
}

void up(int i, int j, data a, int ord) {
	if (i == 0 || a.a[i-1][j] == 1) return ;
	swap(a.a[i][j], a.a[i-1][j]);
	if (!dd[getCode(a)]) push(a, ord);
}

void down(int i, int j, data a, int ord) {
	if (i == 3 || a.a[i+1][j] == 1) return ;
	swap(a.a[i][j], a.a[i+1][j]);
	if (!dd[getCode(a)]) push(a, ord);
}

void left(int i, int j, data a, int ord) {
	if (j == 0 || a.a[i][j-1] == 1) return ;
	swap(a.a[i][j], a.a[i][j-1]);
	if (!dd[getCode(a)]) push(a, ord);
}

void right(int i, int j, data a, int ord) {
	if (j == 3 || a.a[i][j+1] == 1) return ;
	swap(a.a[i][j], a.a[i][j+1]);
	if (!dd[getCode(a)]) push(a, ord);
}



int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	a = read();
	push(a, 1);
	a = read();

	while (! st.empty()) {
		data x = st.front();
		st.pop();
		if (getCode(x) == getCode(a)) break;
		int ord = dd[getCode(x)] + 1;
		FOR(i,0,3)
		FOR(j,0,3)
		if (x.a[i][j] == 1) {
			up(i,j,x,ord);
			down(i,j,x,ord);
			left(i,j,x,ord);
			right(i,j,x,ord);
		}
	}

	printf("%d\n", dd[getCode(a)] - 1);

	return 0;
}
