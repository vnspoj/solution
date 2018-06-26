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

const int N = 50010;
int n, a[N], F[5][N], t[5][N], f[N];

int get(int id, int x) {
	int ans = 0;
	if (id%2)
		for (; x>0; x-=x&-x) ans = max(ans, t[id][x]);
	else
		for (; x<=f[0]; x+=x&-x) ans = max(ans, t[id][x]);
	return ans;
}

void upd(int id, int x, int v) {
	if (id%2)
		for (; x<=f[0]; x+=x&-x) t[id][x] = max(t[id][x], v);
	else
		for (; x>0; x-=x&-x) t[id][x] = max(t[id][x], v);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	FOR(i,1,n) {
		scanf("%d", &a[i]);
		f[++f[0]] = a[i];
	}
	f[++f[0]] = 0;
	sort(f+1, f+f[0]+1);
	f[0] = unique(f+1, f+f[0]+1)-f-1;
	FOR(id,1,4) {
		FOR(i,1,n) {
			int x;
			if (id%2)
				x = upper_bound(f+1,f+f[0]+1,a[i]-1)-f-1;
			else
				x = upper_bound(f+1,f+f[0]+1,a[i])-f;
			F[id][i] = get(id, x) + 1;
			if (id > 1 && F[id][i] < id+1) F[id][i] = 0;
			x = lower_bound(f+1,f+f[0]+1,a[i])-f;
			if (id == 1) upd(id, x, F[id][i]);
			else if (id == 2) {
				upd(id, x, F[id][i]);
				if
				(F[id-1][i] > 1) upd(id, x, F[id-1][i]);
			} else {
				upd(id, x, F[id][i]);
				upd(id, x, F[id-1][i]);
			}
		}
	}
	int ans = 0;
	FOR(i,1,n) ans = max(ans, F[4][i]);
	printf("%d\n", ans);


	return 0;
}
