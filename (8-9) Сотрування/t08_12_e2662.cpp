#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    int target_idx = 0;
    int moves = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            if (i == target_idx) {
                target_idx = min_idx;
                moves++;
            } else if (min_idx == target_idx) {
                target_idx = i;
                moves++;
            }
            swap(a[i], a[min_idx]);
        }
    }
    
    cout << moves << "\n";
    return 0;
}
