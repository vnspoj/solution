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
	int a[10];
};
data a;
queue<data> st;
int deg[300000], nxt[4] = {1,2,3,0};

data m[10] = {
	0,0,0,0,0,0,0,0,0,0,
	0,1,1,0,1,1,0,0,0,0,
	0,1,1,1,0,0,0,0,0,0,
	0,0,1,1,0,1,1,0,0,0,
	0,1,0,0,1,0,0,1,0,0,
	0,0,1,0,1,1,1,0,1,0,
	0,0,0,1,0,0,1,0,0,1,
	0,0,0,0,1,1,0,1,1,0,
	0,0,0,0,0,0,0,1,1,1,
	0,0,0,0,0,1,1,0,1,1
};

int order(data a) {
	int ans = 0;
	FOR(i,1,9)
	ans = ans * 4 + a.a[i];
	return ans;
}

void Print(data x) {
	FOR(i,1,3) printf("%d", x.a[i]);
	EL;
	FOR(i,4,6) printf("%d", x.a[i]);
	EL;
	FOR(i,7,9) printf("%d", x.a[i]);
	EL;
	EL;
}

void Try(data a, int x, int d) {
	FOR(i,1,9)
	if (m[x].a[i] == 1) a.a[i] = nxt[a.a[i]];
	int ord = order(a);
	if (deg[ord] == 0) {
		deg[ord] = d;
		st.push(a);
	}
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	for (int i = 1; i <= 9; i += 3) {
		char c;
		FOR(j,0,3)
		scanf("%c", &c), a.a[i+j] = c-'0';
		scanf("\n");
	}

	st.push(a);
	deg[order(a)] = 1;
	while (!st.empty()) {
		data x = st.front();
		st.pop();
		int ord = order(x);
		if (ord == 0) break;
		FOR(i,1,9) Try(x, i, deg[ord] + 1);
	}
	printf("%d\n", deg[0]-1);

	return 0;
}
