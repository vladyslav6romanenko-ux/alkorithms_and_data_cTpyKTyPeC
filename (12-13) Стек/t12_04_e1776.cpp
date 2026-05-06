#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while (cin >> n && n) {
        int first;
        while (cin >> first && first) {
            vector<int> target(n);
            target[0] = first;
            for (int i = 1; i < n; ++i) {
                cin >> target[i];
            }
            
            stack<int> s;
            int curr = 1, idx = 0;
            
            while (curr <= n) {
                s.push(curr++);
                while (!s.empty() && s.top() == target[idx]) {
                    s.pop();
                    idx++;
                }
            }
            
            cout << (s.empty() ? "Yes\n" : "No\n");
        }
        cout << "\n";
    }
    
    return 0;
}
