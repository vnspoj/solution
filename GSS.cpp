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
	int sum, L, R, ans;
};

const int N = 50005;
int n, m, a[N];
data t[4*N];

data combine(data L, data R) {
	data ans;
	ans.sum = L.sum + R.sum;
	ans.L = max(L.L, L.sum + R.L);
	ans.R = max(R.R, L.R + R.sum);
	ans.ans = max(max(L.ans, R.ans), L.R + R.L);
	return ans;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k] = {a[l], a[l], a[l], a[l]};
		return ;
	}
	int mid = (l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k] = combine(t[k*2], t[k*2+1]);
}

data get(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return data {0,-1e9,-1e9,-1e9};
	if (L <= l && r <= R) return t[k];
	int mid = (l+r)/2;
	return combine(get(k*2,l,mid,L,R), get(k*2+1,mid+1,r,L,R));
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);


	cin >> n;
	FOR(i,1,n) scanf("%d", &a[i]);

	build(1,1,n);

	cin >> m;
	while (m--) {
		int l, r;
		scanf("%d%d", &l,&r);
		printf("%d\n", get(1,1,n,l,r).ans);
	}

	return 0;
}
