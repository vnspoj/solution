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

const int N = 20000;
int T, n, k, a[N];
deque<int> st;

void push(int x) {
	while (!st.empty() && x < st.back()) st.pop_back();
	st.push_back(x);
}

void solve() {
	scanf("%d%d", &n,&k);
	FOR(i,1,n) scanf("%d", &a[i]);
	st = deque<int> {};
	FOR(i,1,k-1) push(a[i]);
	FOR(i,k,n) {
		push(a[i]);
		printf("%d ", st.front());
		if (a[i-k+1] == st.front()) st.pop_front();
	}
	EL;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> T;
	while (T--) solve();

	return 0;
}
