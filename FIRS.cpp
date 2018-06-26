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


const int   N = 200000, T = 4*N, oo = 1000000;
int         n, res, a[N], t[T];

int combine(int t1, int t2) {
	return min(t1, t2);
}

void make_tree(int node, int l, int r) {
	if (l == r) {
		t[node] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	make_tree(node*2,l,mid);
	make_tree(node*2+1,mid+1,r);
	t[node] = combine(t[node*2], t[node*2+1]);
}

void get_min(int node, int l, int r, int &v, int &Min) {
	if (t[node] == oo) return ;
	if (l == r) {
		if (t[node] < Min) {
			v = l;
			Min = t[node];
		}
		return ;
	}
	int mid = (l+r)/2;
	if (t[node*2] <= t[node*2+1])
		get_min(node*2,l,mid,v,Min);
	else
		get_min(node*2+1,mid+1,r,v,Min);
}

void update(int node, int l, int r, int L, int R) {
	if (r < L or R < l or t[node] == oo) return;
	if (L <= l and r <= R) {
		t[node] = oo;
		if (l < r) {
			t[node*2] = oo;
			t[node*2+1] = oo;
		}
		return ;
	}
	int mid = (l+r)/2;
	update(node*2,l,mid,L,R);
	update(node*2+1,mid+1,r,L,R);
	t[node] = combine(t[node*2], t[node*2+1]);
}


int main() {
//  freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d", &n);
	for (int i=1; i<=n; i++)  scanf("%d", &a[i]);
	make_tree(1,1,n);
	while (1) {
		int Min = oo, v = 0;
		get_min(1,1,n,v,Min);
		if (v == 0) break;
		res++;
		int l = max(0,v-1), r = min(n,v+1);
		update(1,1,n,l,r);
	}
	printf("%d", res);

	return 0;
}
