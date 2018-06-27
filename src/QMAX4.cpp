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

const int oo = 1e9+7;

typedef struct node {
	int sz, priority;
	int val, Max;
	node *L, *R;
};
typedef node *Node;

Node root, nil;

int Rand() {
	return (rand()*11111 + rand()*33333) % oo;
}

Node newNode(int Val) {
	Node ans = new node();
	ans->val = ans->Max = Val;
	ans->sz = 1;
	ans->priority = Rand();
	ans->L = ans->R = nil;
	return ans;
}

void Init() {
	nil = new node();
	nil->sz = nil->priority;
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

void Insert(Node &t, Node x, int i) {
	if (t == nil) {
		t = x;
		return ;
	}
	if (i <= t->L->sz+1) {
		Insert(t->L, x, i);
		if (t->L->priority > t->priority) t = UpTree(t->L, t);
	} else {
		Insert(t->R, x, i-t->L->sz-1);
		if (t->R->priority > t->priority) t = UpTree(t->R, t);
	}
	Update(t);
}

void Insert(Node &t, int val, int pos) {
	Node x = newNode(val);
	Insert(t, x, pos);
}

Node Join(Node t1, Node t2) {
	if (t1 == nil) return t2;
	if (t2 == nil) return t1;
	if (t1->priority > t2->priority) {
		t1->R = Join(t1->R, t2);
		Update(t1);
		return t1;
	} else {
		t2->L = Join(t1, t2->L);
		Update(t2);
		return t2;
	}
}

void Split(Node t, int i, Node &t1, Node &t2) {
	if (t == nil) {
		t1 = t2 = nil;
		return ;
	}
	if (i == 0) {
		t1 = nil;
		t2 = t;
		return ;
	}
	if (i < t->L->sz+1) {
		Split(t->L, i, t1, t->L);
		t2 = t;
	} else {
		i -= t->L->sz+1;
		Split(t->R, i, t->R, t2);
		t1 = t;
	}
	Update(t);
}

void Delete(Node &t, int i) {
	Node t1, t2, t3;
	Split(t, i-1, t1, t2);
	Split(t2, 1, t2, t3);
	t = Join(t1, t3);
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

int Max(Node t, int i, int j) {
	return Max(t, 1, t->sz, i, j);
}

int get(Node t, int i) {
	if (i == t->L->sz+1) return t->val;
	if (i < t->L->sz+1) return get(t->L, i);
	return get(t->R, i-t->L->sz-1);
}

void Change(Node &t, int i, int v) {
	if (i == t->L->sz+1) t->val = v;
	else if (i < t->L->sz+1) Change(t->L, i, v);
	else Change(t->R, i-t->L->sz-1, v);
	Update(t);
}

void Swap(Node &t, int i, int j) {
	int x = get(t,i), y = get(t,j);
	Change(t,i,y);
	Change(t,j,x);
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

	int n, x, y;
	char c;

	Init();
	scanf("%d\n", &n);
	while (n--) {
		scanf("%c", &c);
		if (c == 'I') {
			scanf("%d%d\n", &x,&y);
			if (y > root->sz+1) y = root->sz+1;
			Insert(root, x, y);
		} else if (c == 'S') {
			scanf("%d%d\n", &x,&y);
			Swap(root, x, y);
		} else if (c == 'D') {
			scanf("%d\n", &x);
			Delete(root, x);
		} else {
			scanf("%d%d\n", &x,&y);
			printf("%d\n", Max(root, x, y));
		}
	}

	return 0;
}
