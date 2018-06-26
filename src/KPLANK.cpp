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

const int N = 1e6+6;
int n, a[N], L[N], R[N];
stack<int> st;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", &a[i]);

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

	int ans = 0;
	FOR(i,1,n)
	if (R[i] - L[i] + 1 >= a[i]) ans = max(ans, a[i]);

	printf("%d\n", ans);


	return 0;
}
