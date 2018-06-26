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
	int i, j, type, id;
};

const int   N = 30001, Q = 200001, A = 1000001;
int         n, q, res[Q], last_pos[A], bit[N];
data        a[N+Q];

bool cmp(data u, data v) {
	return (u.j < v.j or (u.j == v.j and u.type < v.type));
}

void update(int x, int k) {
	for (x; x<=n; x+=x&-x) bit[x] += k;
}

int get(int x) {
	int ans = 0;
	for (x; x>0; x-=x&-x) ans += bit[x];
	return ans;
}



int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i].i), a[i].j = i, a[i].type = -1;
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
		scanf("%d%d", &a[i+n].i, &a[i+n].j), a[i+n].id = i;

	sort(a+1,a+n+q+1,cmp);

	for (int i=1; i<=n+q; i++) {
		if (a[i].type == -1) {
			update(a[i].j, 1);
			if (last_pos[a[i].i] > 0) update(last_pos[a[i].i], -1);
			last_pos[a[i].i] = a[i].j;
		} else {
			res[a[i].id] = get(a[i].j) - get(a[i].i-1);
		}
	}

	for (int i=1; i<=q; i++) printf("%d\n", res[i]);

	return 0;
}
