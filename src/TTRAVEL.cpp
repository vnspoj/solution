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

typedef struct node {
	int  id;
	node *next;
};

const int   N = 200000;
int         n, x;
char        ch;
node        *head[N];

void add(int t, int id) {
	node *p = new node();
	p->id = x;
	p->next = head[t];
	head[t] = p;
}

void pop(int t) {
	if (head[t] == NULL) return ;
	if (head[t]->next == NULL) {
		head[t] = NULL;
		return ;
	}
	node *p = new node();
	p = head[t]->next;
	head[t] = p;
}

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d\n", &n);
	head[0] = NULL;
	for (int t=1; t<=n; t++) {
		scanf("%c", &ch);
		if (ch == 'a') {
			scanf("%d\n", &x);
			head[t] = head[t-1];
			add(t,x);
		} else if (ch == 's') {
			scanf("\n");
			head[t] = head[t-1];
			pop(t);
		} else if (ch == 't') {
			scanf("%d\n", &x);
			head[t] = head[x-1];
		}

		if (head[t] != NULL) printf("%d\n", head[t]->id);
		else printf("-1\n");
	}

	return 0;
}
