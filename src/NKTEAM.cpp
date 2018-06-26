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
	int x, y, z;
	bool operator < (const data &other) const {
		return x > other.x;
	}
};

const int N = 1e5+1;
int n, k, t[N], res;
data a[N];

void update(int x, int newVal) {
	for (x; x>0; x-=x&-x) t[x] = max(t[x], newVal);
}

int get(int x) {
	int ans = 0;
	for (x; x<=n; x+=x&-x) ans = max(ans, t[x]);
	return ans;
}


int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	FOR(i,1,3) {
		int score = n;
		FOR(j,1,n) {
			scanf("%d", &k);
			if (i == 1) a[k].x = score--;
			if (i == 2) a[k].y = score--;
			if (i == 3) a[k].z = score--;
		}
	}

	sort(a+1,a+n+1);

	FOR(i,1,n) {
		int maxScore3 = get(a[i].y+1);
		if (maxScore3 < a[i].z) res++;
		update(a[i].y, a[i].z);
	}

	printf("%d\n", res);


	return 0;
}
