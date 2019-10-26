#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int mod[20];
bool rem[20][1000];
char dig[101];
long long dp[101];

inline bool check(const int &a, const int &b) {
    if (dig[a]=='0') return false;
    for (int i=0; i<20; ++i) {
        int x=0;
        for (int j=a; j<=b; ++j) {
            x=x*10+dig[j]-'0';
            if (x>=mod[i]) x%=mod[i];
        }
        if (!rem[i][x]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    for (int i=0; i<20; ++i) mod[i]=rand()%1000;
    for (int i=1; i<=2000; ++i) {
        for (int j=0; j<20; ++j) {
            rem[j][i*i%mod[j]]=true;
        }
    }

    int T; cin>>T;
    while (T--) {
        cin>>dig;
        int i;
        for (i=0; dig[i]; ++i) {
            dp[i]=(check(0, i))?1:0;
            for (int j=0; j<i; ++j)
                if (dp[j] && check(j+1, i)) dp[i]+=dp[j];
        }
        cout<<dp[i-1]<<"\n";
    }
    return 0;
}
