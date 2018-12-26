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
 
const int N = 1001;
int n, k, F[N][N], ans;
 
int main()
{
    //freopen("INP.INP", "r", stdin);
    //freopen("OUT.OUT", "w", stdout);
 
    scanf("%d%d", &n,&k);
    FOR(i,1,n)
        FOR(j,1,n) {
            scanf("%d", &F[i][j]);
            F[i][j] += F[i-1][j] + F[i][j-1] - F[i-1][j-1];
        }
 
    FOR(i,k,n)
        FOR(j,k,n) {
            int S = F[i][j] - F[i-k][j] - F[i][j-k] + F[i-k][j-k];
            ans = max(ans, S);
        }
 
    printf("%d\n", ans);
 
    return 0;
}
