#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Expr {
    string s;
    int prio;
    char op;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string prefix;
    if (cin >> prefix) {
        stack<Expr> st;
        for (int i = prefix.length() - 1; i >= 0; i--) {
            char c = prefix[i];
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                Expr left = st.top(); st.pop();
                Expr right = st.top(); st.pop();
                
                int curPrio = (c == '+' || c == '-') ? 1 : 2;
                
                string lstr = left.s;
                if (left.prio < curPrio) {
                    lstr = "(" + lstr + ")";
                }
                
                string rstr = right.s;
                if (right.prio < curPrio || (right.prio == curPrio && (c == '-' || c == '/'))) {
                    rstr = "(" + rstr + ")";
                }
                
                st.push({lstr + c + rstr, curPrio, c});
            } else {
                st.push({string(1, c), 3, c});
            }
        }
        cout << st.top().s << "\n";
    }
    
    return 0;
}
