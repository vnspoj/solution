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

const int N = 6000;
int u, v, p, q, now, ans;
int root = N/2, InQueue[N][N], dd[N][N];
int dx[] = {1,2,-1,-2,1,-2,2,-1};
int dy[] = {2,1,-2,-1,-2,1,-1,2};
queue<ii> st;

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d%d%d%d", &u, &v, &p, &q, &now);

	if (now) now = 0, p--;

	if ((u - p + v - q) % 2 == 0) {
		puts("NO");
		return 0;
	}

	st.push({u,v});
	dd[u+root][v+root] = 1;
	InQueue[u+root][v+root] = 1;

	int DX = abs(u-p)+30, DY = abs(v-q)+30;

	for (;;) {
		if (now) {
			p--;
			FOR(k,0,7)
			if (InQueue [p+dx[k]+root] [q+dy[k]+root]) {
				printf("YES\n%d\n", ans+1);
				return 0;
			}
		} else {
			ans++;
			int sz = st.size();
			while (sz--) {
				ii f = st.front();
				st.pop();
				InQueue[f.X+root][f.Y+root] = 0;
				FOR(k,0,7) {
					int i = f.X + dx[k], j = f.Y + dy[k];
					if (dd[i+root][j+root]) continue;
					if (abs(i-p) > DX || abs(j-q) > DY) continue;
					if (j < -1002 || j > 1002) continue;
					st.push({i,j});
					dd[i+root][j+root] = 1;
					InQueue[i+root][j+root] = 1;
				}
			}
		}
		now = 1 - now;
	}

	return 0;
}
