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
int n, m, L[N], h[N];
ll F[N], ans;
char a[N];

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&m);
	FOR(i,1,n) {
		scanf("%s\n", a+1);
		FOR(j,1,m) h[j] = a[j] == '1' ? h[j] + 1 : 0;

		stack<int> st;
		FOR(j,1,m) {
			while (! st.empty() && h[j] <= h[st.top()]) st.pop();
			L[j] = st.empty() ? 1 : st.top() + 1;
			st.push(j);
		}

		FOR(j,1,m) {
			int k = L[j] - 1;
			F[j] = (ll) h[j] * (j - k) + F[k];
			ans += F[j];
		}
	}

	cout << ans;

	return 0;
}
