#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct data {
	int i, j, w, id;
	bool operator < (const data &o) const {
		if (i < o.i) return true;
		if (i == o.i && j < o.j) return true;
		return false;
	}
};

const int N = 3e5+5;
int n, k, F[N], pos[N], maxi[N], maxj[N];
data a[N];

void upd(int i) {
	maxi[a[i].i] = max(maxi[a[i].i], F[i]);
	maxj[a[i].j] = max(maxj[a[i].j], F[i]);
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> n >> k;
	FOR(i,1,n) {
		scanf("%d%d%d", &a[i].i, &a[i].j, &a[i].w);
		a[i].id = i;
	}
	sort(a+1,a+n+1);
	FOR(i,1,n) pos[a[i].id] = i;

	F[pos[1]] = a[pos[1]].w;
	upd(pos[1]);

	FOR(i, pos[1]+1, pos[n]) {
		if (maxi[a[i].i] >= k)
			F[i] = max(F[i], maxi[a[i].i] - k + a[i].w);
		if (maxj[a[i].j] >= k)
			F[i] = max(F[i], maxj[a[i].j] - k + a[i].w);
		upd(i);
	}

	printf("%d\n", F[pos[n]]);

	return 0;
}
