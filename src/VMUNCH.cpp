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

const int N = 1005;
int n, m;
char a[N][N];
ii pB, pC;
queue<ii> st;
map<ii,bool> dd;
map<ii,int> res;
int dX[] = { -1, 0, 0, 1 };
int dY[] = { 0, -1, 1, 0 };

int main()
{
    // freopen("INP.TXT", "r", stdin);
    // freopen("OUT.TXT", "w", stdout);

    cin >> n >> m;
    FOR(i,1,n) {
        FOR(j,1,m) cin >> a[i][j];
    }

    FOR(i,1,n) FOR(j,1,m) {
        if (a[i][j] == 'B') pB = { i, j };
        else if (a[i][j] == 'C') pC = { i, j };
    }

    st.push(pC); dd[pC] = true;
    res[pC] = 1;

    bool found = false;
    while (!st.empty() && !found) {
        ii p = st.front();
        st.pop();
        FOR(k,0,3) {
            int nX = p.X + dX[k];
            int nY = p.Y + dY[k];
            ii nP = { nX, nY };
            if (nX < 1 || nX > n || nY < 1 || nY > m || dd[nP] || a[nX][nY] == '*') {
                continue;
            }
            if (nP == pB) {
                res[pB] = res[p];
                found = true;
                break;
            }
            dd[nP] = true;
            st.push(nP);
            res[nP] = res[p] + 1;
        }
    }

    cout << res[pB] << endl;

    return 0;
}
