#include <iostream>
#include <vector>

using namespace std;

void generate_arrangements(int n, int k, vector<int>& current, vector<bool>& used) {
    if (current.size() == k) {
        for (int i = 0; i < k; ++i) {
            cout << current[i] << (i == k - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(i);
            generate_arrangements(n, k, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    if (cin >> n >> k) {
        vector<int> current;
        vector<bool> used(n + 1, false);
        generate_arrangements(n, k, current, used);
    }
    
    return 0;
}
