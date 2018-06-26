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

const int N = 2001, M = 2005;
int a[M][M], L[M], R[M], U[M], D[M];
int row[M][M], col[M][M];
queue<ii> st;

int FindSetRow(int i, int j) {
	if (row[i][j] == j) return j;
	return row[i][j] = FindSetRow(i,row[i][j]);
}

int FindSetCol(int j, int i) {
	if (col[j][i] == i) return i;
	return col[j][i] = FindSetCol(j,col[j][i]);
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	FOR(i,0,N+1) {
		L[i] = D[i] = N+1, R[i] = U[i] = 0;
		FOR(j,0,N+1) row[i][j] = j, col[j][i] = i;
	}

	int t;
	cin >> t;
	while (t--) {
		int i, j;
		scanf("%d%d", &i,&j);
		i += 1001;
		j += 1001;
		if (a[i][j]) continue;
		a[i][j] = 1;
		st.push({i,j});
		L[i] = min(L[i], j);
		R[i] = max(R[i], j);
		D[j] = min(D[j], i);
		U[j] = max(U[j], i);
	}

	while (! st.empty()) {
		int i = st.front().X, j = st.front().Y;
		st.pop();

		int Left = L[i], Right = R[i];
		for (int k = FindSetRow(i,Left); k <= Right; k = FindSetRow(i,k+1)) {
			row[i][k] = k+1;
			if (a[i][k]) continue;
			a[i][k] = 1;
			st.push({i,k});
			D[k] = min(D[k], i);
			U[k] = max(U[k], i);
		}

		int Down = D[j], Up = U[j];
		for (int k = FindSetCol(j,Down); k <= Up; k = FindSetCol(j,k+1)) {
			col[j][k] = k+1;
			if (a[k][j]) continue;
			a[k][j] = 1;
			st.push({k,j});
			L[k] = min(L[k], j);
			R[k] = max(R[k], j);
		}
	}

	int ans = 0;
	FOR(i,1,N) FOR(j,1,N) ans += a[i][j];

	printf("%d\n", ans);


	return 0;
}
