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

struct edge {
	int u,v;
};

edge    e[10000];
int     n,m,w,a[300][300],head[300],ke[10000],u,v,top,s[10000];

int main() {
//	freopen("INP.TXT", "r", stdin);
//  freopen("OUT.TXT", "w", stdout);

	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf("%d",&w);
	for (int i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		e[i].u = u;
		e[i].v = v;
		head[u]++;
		head[v]++;
		a[u][v]++;
		a[v][u]++;
	}
	for (int i=2; i<=n+1; i++) head[i] += head[i-1];
	for (int i=1; i<=m; i++) {
		ke[head[e[i].u]] = e[i].v;
		ke[head[e[i].v]] = e[i].u;
		head[e[i].u]--;
		head[e[i].v]--;
	}
	top = 1;
	s[1] = 1;
	printf("%d\n",m);
	while (top > 0) {
		int u = s[top];
		bool kt = true;
		for (int i=head[u]+1; i<=head[u+1]; i++) {
			v = ke[i];
			if (a[u][v] > 0) {
				a[u][v]--;
				a[v][u]--;
				kt = false;
				top++;
				s[top] = v;
				break;
			}
		}
		if (kt) {
			printf("%d ",u);
			top--;
		}
	}

	return 0;
}
