#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    if (getline(cin, str)) {
        stack<char> s;
        bool ok = true;
        
        for (char c : str) {
            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (s.empty()) {
                    ok = false;
                    break;
                }
                char top = s.top();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    ok = false;
                    break;
                }
                s.pop();
            }
        }
        
        cout << (ok && s.empty() ? "yes\n" : "no\n");
    }
    
    return 0;
}
