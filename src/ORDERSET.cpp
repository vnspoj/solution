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

template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, x;
char c;
order_set<int> s;

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	while (n--) {
		scanf("%c %d\n", &c, &x);
		if (c == 'I') s.insert(x);
		else if (c == 'D') s.erase(x);
		else if (c == 'K') {
			if (x > s.size()) puts("invalid\n");
			else printf("%d\n", *s.find_by_order(x-1));
		} else
			printf("%d\n", s.order_of_key(x));
	}


	return 0;
}
