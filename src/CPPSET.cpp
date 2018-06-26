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

struct cmp {
	bool operator () (const int &u, const int &v) const {
		return u < v;
	}
};

int n, m, x;
set<int,cmp> s;
set<int,cmp>::iterator it;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	while (scanf("%d", &n) == 1) {
		switch (n) {
		case 0 :
			return 0;
		case 1 :
			scanf("%d", &x);
			s.insert(x);
			break;
		case 2 :
			scanf("%d", &x);
			s.erase(x);
			break;
		case 3 :
			if (s.size() == 0) {
				printf("empty\n");
				continue;
			}
			printf("%d\n", *(s.begin()));
			break;
		case 4 :
			if (s.size() == 0) {
				printf("empty\n");
				continue;
			}
			printf("%d\n", *(s.rbegin()));
			break;
		case 5 :
			scanf("%d", &x);
			if (s.size() == 0) {
				printf("empty\n");
				continue;
			}
			it = s.upper_bound(x);
			if (it == s.end()) printf("no\n");
			else printf("%d\n", *(it));
			break;
		case 6 :
			scanf("%d", &x);
			if (s.size() == 0) {
				printf("empty\n");
				continue;
			}
			it = s.lower_bound(x);
			if (it == s.end()) printf("no\n");
			else printf("%d\n", *(it));
			break;
		case 7 :
			scanf("%d", &x);
			if (s.size() == 0) {
				printf("empty\n");
				continue;
			}
			it = s.lower_bound(x);
			if (it == s.begin()) printf("no\n");
			else printf("%d\n", *(--it));
			break;
		case 8 :
			scanf("%d", &x);
			if (s.size() == 0) {
				printf("empty\n");
				continue;
			}
			it = s.lower_bound(x);
			if (*(it) == x) printf("%d\n", x);
			else if (it == s.begin()) printf("no\n");
			else printf("%d\n", *(--it));
			break;
		}

		return 0;
	}
