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

const int N = 1005;
int n, m, a[N], h[N], L[N], R[N], ans;
stack<int> st;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&m);
	FOR(i,1,n) {
		FOR(j,1,m) scanf("%d", &a[j]);
		FOR(j,1,m)
		h[j] = a[j] == 1 ? h[j] + 1 : 0;

		st = stack<int> {};
		FOR(j,1,m) {
			while (! st.empty() && h[j] <= h[st.top()]) st.pop();
			L[j] = st.empty() ? 1 : st.top() + 1;
			st.push(j);
		}

		st = stack<int> {};
		FOD(j,m,1) {
			while (! st.empty() && h[j] <= h[st.top()]) st.pop();
			R[j] = st.empty() ? m : st.top() - 1;
			st.push(j);
		}

		FOR(j,1,m)
		ans = max(ans, h[j] * (R[j] - L[j] + 1));
	}

	printf("%d\n", ans);


	return 0;
}
