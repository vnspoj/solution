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

struct data {
	int k, p;
	bool operator < (const data &o) const {
		return p < o.p;
	}
};

set<data> st2, st3;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	int t;
	for (;;) {
		scanf("%d", &t);
		if (t == 0) return 0;
		if (t == 1) {
			int k, p;
			scanf("%d%d", &k,&p);
			st2.insert({k,-p});
			st3.insert({k,p});
		}
		if (t == 2) {
			if (st2.empty()) puts("0");
			else {
				data p = *st2.begin();
				printf("%d\n", p.k);
				st3.erase({p.k,-p.p});
				st2.erase(p);
			}
		}
		if (t == 3) {
			if (st3.empty()) puts("0");
			else {
				data p = *st3.begin();
				printf("%d\n", p.k);
				st2.erase({p.k,-p.p});
				st3.erase(p);
			}
		}
	}

	return 0;
}
