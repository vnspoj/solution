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

const int N = 1e4+5;
int n, m, s, len[N], cnt[N];
vector<int> a[N];
queue<int> st;
map<ii,bool> dd;

int main()
{
    // freopen("INP.TXT", "r", stdin);
    // freopen("OUT.TXT", "w", stdout);

    faster;

    cin >> n >> m >> s;
    FOR(i,1,m) {
        int u, v;
        cin >> u >> v;
        if (dd[{ u,v }]) continue; // duplicated edges
        dd[{ u,v }] = true;
        a[u].push_back(v);
    }

    len[s] = 0;
    cnt[s] = 1; 
    // cnt == { 0: not path, 1: one path, 2: more paths }
    // only check if more paths without counting the number of shortest paths
    // => avoid overflow (big integer)

    st.push(s); 
    while (!st.empty()) {
        int u = st.front();
        st.pop();
        for (int v: a[u]) {
            if (cnt[v] == 0) { // not visited => shortest path
                len[v] = len[u] + 1;
                cnt[v] = cnt[u];
                st.push(v);
            } else { // visited
                if (len[v] == len[u] + 1) { // more paths with the same length
                    if (cnt[v] == 1) cnt[v] = 2;
                }
            }
        }
    }

    int res = 0;
    FOR(i,1,n) {
        res += cnt[i] == 2;
    }

    cout << res << endl;

    return 0;
}
