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

const int N = 30005;
int T, n, a[N], L[N], R[N];
stack<int> st;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> T;
	while (T--) {
		scanf("%d", &n);
		FOR(i,1,n) scanf("%d", &a[i]);

		stack<int> st;
		FOR(i,1,n) {
			while (! st.empty() && a[i] <= a[st.top()]) st.pop();
			L[i] = st.empty() ? 1 : st.top() + 1;
			st.push(i);
		}

		st = stack<int> {};
		FOD(i,n,1) {
			while (! st.empty() && a[i] <= a[st.top()]) st.pop();
			R[i] = st.empty() ? n : st.top() - 1;
			st.push(i);
		}

		int ans = 0, i = 0, j = 0;
		FOR(k,1,n)
		if (ans < (R[k] - L[k] + 1 ) * a[k])
			ans = (R[k] - L[k] + 1 ) * a[k], i = L[k], j = R[k];

		printf("%d %d %d\n", ans, i, j);
	}

	return 0;
}
