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

const int oo = 1e9+9, MaxPriority = 1e9+7;

typedef struct node {
	int sz, priority;
	int val, Max;
	node *L, *R;
};
typedef node *Node;

Node root, nil;

Node newNode(int Val) {
	Node ans = new node();
	ans->val = ans->Max = Val;
	ans->sz = 1;
	ans->priority = rand();
	ans->L = ans->R = nil;
	return ans;
}

void Init() {
	nil = new node();
	nil->sz = nil->priority = 0;
	nil->val = nil->Max = -oo;
	nil->L = nil->R = nil;

	root = nil;
}

void Update(Node x) {
	x->sz = x->L->sz + x->R->sz + 1;
	x->Max = max(max(x->L->Max, x->R->Max), x->val);
}

Node UpTree(Node x, Node y) {
	if (y->L == x)
		y->L = x->R, x->R = y;
	else
		y->R = x->L, x->L = y;
	Update(y);
	Update(x);
	return x;
}

void Insert(Node &t, Node x, int pos) {
	if (t == nil) {
		t = x;
		return ;
	}
	if (pos <= t->L->sz+1) {
		Insert(t->L, x, pos);
		if (t->L->priority > t->priority) t = UpTree(t->L, t);
	} else {
		pos -= t->L->sz+1;
		Insert(t->R, x, pos);
		if (t->R->priority > t->priority) t = UpTree(t->R, t);
	}
	Update(t);
}

void Insert(int val, int pos) {
	Node x = newNode(val);
	Insert(root, x, pos);
}

int Max(Node t, int l, int r, int L, int R) {
	if (t == nil || r < L || R < l) return -oo;
	if (L == l && r == R) return t->Max;
	int mid = l + t->L->sz;
	if (mid < L) return Max(t->R, mid+1, r, L, R);
	if (R < mid) return Max(t->L, l, mid-1, L, R);
	return max(t->val, max(Max(t->L, l, mid-1, L, mid-1),
	                       Max(t->R, mid+1, r, mid+1, R)));
}

int Max(int i, int j) {
	return Max(root, 1, root->sz, i, j);
}

//--------CHECK-NODE----------//

int a[100];

void dfs(Node r) {
	if (r == nil) return;
	dfs(r->L);
	a[++a[0]] = r->val;
	dfs(r->R);
}

void check(Node t) {
	Node r = t;
	a[0] = 0;
	dfs(r);
	FOR(i,1,a[0]) printf("%d ", a[i]);
	EL;
}
//---------------------------//

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	Init();

	int n, i, j;
	char c;

	scanf("%d\n", &n);
	while (n--) {
		scanf("%c %d %d\n", &c, &i, &j);
		//printf("%c %d %d\n", c,i,j);
		if (c == 'A') {
			Insert(i,j);
			//check(root);
		} else printf("%d\n", Max(i,j));
	}

	return 0;
}
