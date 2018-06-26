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

const int N = 3e5+5;
int n, k, a[N], F[N];
deque<int> Max, Min;

void push(int x) {
	while (! Max.empty() && x > Max.back()) Max.pop_back();
	Max.push_back(x);
	while (! Min.empty() && x < Min.back()) Min.pop_back();
	Min.push_back(x);
}

void pop(int x) {
	if (x == Max.front()) Max.pop_front();
	if (x == Min.front()) Min.pop_front();
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d", &n,&k);
	FOR(i,1,n) scanf("%d", &a[i]);

	int i = 1;
	FOR(j,1,n) {
		push(a[j]);
		while (Max.front() - Min.front() > k) pop(a[i++]);
		F[j] = j - i + 1;
	}

	int ans = 0;
	FOR(i,1,n) {
		ans = max(ans, F[i] + F[i-F[i]]);
		F[i] = max(F[i-1], F[i]);
	}

	printf("%d\n", ans);

	return 0;
}
