#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
ll c[2];
stack<ll> st;

int main() {
    
    for (;;) {
        getline(cin, s);
        if (s == "ENDPROGRAM") break;
        if (s == "IF") {
            st.push(-1); // mark IF
            st.push(1);
        } else if (s == "ELSE") {
            st.push(-2); // mark ELSE
            st.push(1);
        } else if (s == "END_IF") {
            c[0] = c[1] = 1ll;
            int idx = 0;
            while (!st.empty()) {
                int top = st.top(); 
                st.pop();
                if (top == -2) { // ELSE Branch
                    idx++; // change to IF branch
                } else if (top == -1) { // IF Branch
                    break;
                } else {
                    c[idx] *= top;
                }
            }
            int top = c[0] + c[1];
            if (!st.empty()) {
                top *= st.top();
                st.pop();
            }
            st.push(top);
        }
    }
    
    if (!st.empty()) cout << st.top(); else cout << 1;
    
    return 0;
}
