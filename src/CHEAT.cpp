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

const int N = 1e5+5;
int n, x, a[N];
stack<int> st;

int solve() {
	FOR(i,1,n) {
		if (a[i] > a[i-1]) {
			for (x = x + 1; x < a[i]; x++) st.push(x);
		} else {
			if (! st.empty() && st.top() == a[i]) st.pop();
			else
				return puts("YES");
		}
	}
	return puts("NO");
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n;
	FOR(i,1,n) scanf("%d", &a[i]);
	solve();

	return 0;
}
