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

int n, x;
ll ans;
stack<int> st;
map<int,int> cnt;


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	while (n--) {
		scanf("%d\n", &x);
		while (!st.empty() && x > st.top()) {
			cnt[st.top()]--;
			st.pop();
			ans++;
		}
		if (!st.empty())
			ans += x == st.top() ? cnt[x] + (st.size() > cnt[x]) : 1;
		st.push(x);
		cnt[x]++;
	}
	printf("%lld\n", ans);

	return 0;
}
