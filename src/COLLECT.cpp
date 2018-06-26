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

int k, X, Y, Z, x, y, z, dd[5][5][5];

struct data {
	int x, y, z, i, j, k;
};

vector<data> a, ans;
queue<data> st;

void input() {
	int x, y, z, i, j, k;
	while (scanf("%d%d%d%d%d%d",&x,&y,&z,&i,&j,&k) != EOF)
		a.push_back({x, y, z, i, j, k});
}

void loang() {
	st.push({x,y,z,0});
	dd[x][y][z] = 1;
	while (! st.empty()) {
		x = st.front().x, y = st.front().y, z = st.front().z;
		int Time = st.front().i;
		st.pop();
		if (X <= x && Y <= y && Z <= z) {
			ans.push_back({x, y, z, Time});
			continue;
		}
		if (Time == k) continue;
		for (auto t : a) {
			int i = x - t.x + t.i, j = y - t.y + t.j, k = z - t.z + t.k;
			if (x >= t.x && i <= 4 && y >= t.y && j <= 4 && z >= t.z && k <= 4 && !dd[i][j][k]) {
				dd[i][j][k] = 1;
				st.push({i, j, k, Time+1});
			}
		}
	}
}

bool cmp(data u, data v) {
	return u.x < v.x || (u.x == v.x && u.y < v.y) ||
	       (u.x == v.x && u.y == v.y && u.z < v.z);
}

int output() {
	if (ans.size() == 0) return puts("-1");
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end(), cmp);
	for (auto st : ans)
		printf("%d %d %d %d\n", st.x, st.y, st.z, st.i);
	return 1;
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	cin >> k >> x >> y >> z >> X >> Y >> Z;
	input();
	loang();
	output();

	return 0;
}
