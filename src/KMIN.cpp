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

const int N = 5e5+5;
int a[N], b[N], n;

struct data {
	int i, j, c;
	bool operator < (const data &o) const {
		return c > o.c;
	}
};

priority_queue<data> st;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> a[0] >> b[0] >> n;
	FOR(i,1,a[0]) scanf("%d", &a[i]);
	sort(a+1,a+a[0]+1);
	FOR(i,1,b[0]) scanf("%d", &b[i]);
	sort(b+1,b+b[0]+1);

	FOR(j,1,b[0]) st.push({1, j, a[1]+b[j]});

	FOR(i,1,n) {
		data t = st.top();
		st.pop();
		printf("%d\n", t.c);
		if (t.i < a[0])
			st.push({t.i+1, t.j, a[t.i+1] + b[t.j]});
	}


	return 0;
}
