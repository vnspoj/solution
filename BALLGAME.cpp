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

const int N = 1e5+5;
int n, m, hole[N];

struct data {
	int start, stop, id;
	bool operator < (const data &o) const {
		return start < o.start;
	}
};

data a[N];

struct heap {
	int i, time;
	bool operator < (const heap &o) const {
		return time > o.time;
	}
};

set<int> heap_min, heap_max;
priority_queue<heap> st;

void Lose(int i) {
	int cnt = 0;
	FOR(j,1,i) cnt += a[j].id == a[i].id;

	if (a[i].id == 0)
		printf("Alice loses at her turn: %d\n", cnt);
	else
		printf("Bob loses at his turn: %d\n", cnt);

	printf("Game lasts: %d minute(s)\n", a[i].start);
	exit(0);
}

int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d\n", &n,&m);
	FOR(i,1,m) {
		char c;
		int u, v;
		scanf("%c%d%d\n", &c,&u,&v);
		a[i] = {u, u+v, c == 'A' ? 0 : 1};
	}

	sort(a+1,a+m+1);

	FOR(i,1,n) heap_min.insert(i), heap_max.insert(-i);

	FOR(i,1,m) {
		while (! st.empty() && st.top().time <= a[i].start) {
			int j = st.top().i;
			st.pop();
			heap_min.insert(j);
			heap_max.insert(-j);
		}
		if (a[i].id == 0) {
			if (heap_min.empty()) Lose(i);
			int j = *heap_min.begin();
			heap_min.erase(j);
			heap_max.erase(-j);
			st.push({j, a[i].stop});
			hole[i] = j;
		} else {
			if (heap_max.empty()) Lose(i);
			int j = *heap_max.begin();
			heap_max.erase(j);
			heap_min.erase(-j);
			st.push({-j, a[i].stop});
			hole[i] = -j;
		}
	}

	int EndGame = 0;
	FOR(i,1,m) EndGame = max(EndGame, a[i].stop);

	puts("DRAW");
	printf("Game lasts: %d minute(s)\n", EndGame);
	FOR(i,1,m)
	if (a[i].id == 0)
		printf("Alice takes the hole: %d\n", hole[i]);
	else
		printf("Bob takes the hole: %d\n", hole[i]);

	return 0;
}
